"""Compare exported Toon highlight footprints without claiming MMD BRDF parity."""
from pathlib import Path
import argparse,json
import numpy as np
from PIL import Image


def analyze(directory):
    directory=Path(directory)
    receipt=json.loads((directory/'receipt.json').read_text(encoding='utf-8-sig'))
    if not receipt.get('passed'):raise AssertionError('Incomplete native sphere matrix')
    images={device:np.asarray(Image.open(directory/(device+'.png')).convert('RGBA'),dtype=np.int16)
            for device in ('gpu','cpu')}
    delta=np.abs(images['gpu']-images['cpu'])
    if delta.max()>2:raise AssertionError('GPU/CPU sphere discrepancy')
    result={'module':receipt['module'],'gpu_cpu_max_rgba':delta.max(axis=(0,1)).tolist(),
            'metric':'8-bit blue-channel excess above zero-Specular base, normalized to exported peak',
            'clipped_output_is_not_hdr_lobe_measurement':True,'devices':{},'passed':False}
    for device,array in images.items():
        occupied_x=np.any(array[:,:,3]>200,axis=0)
        occupied_y=np.any(array[:,:,3]>200,axis=1)
        def runs(mask):
            values=np.where(mask)[0]
            return [part for part in np.split(values,np.where(np.diff(values)>1)[0]+1) if len(part)]
        columns,rows=runs(occupied_x),runs(occupied_y)
        if len(columns)!=3 or len(rows)!=2:raise AssertionError('Unexpected sphere framing')
        bottom=rows[1]
        crops=[array[bottom[0]:bottom[-1]+1,column[0]:column[-1]+1] for column in columns]
        zero=crops[0];zero_mask=zero[:,:,3]>250
        base=float(zero[:,:,2][zero_mask].max())
        metrics={'zero_specular_max_rgb':zero[:,:,:3][zero_mask].max(axis=0).tolist(),'powers':{}}
        for power,crop in zip((8,64),crops[1:]):
            mask=crop[:,:,3]>250
            light=np.maximum(crop[:,:,2]-base,0.)
            peak=float(light[mask].max())
            if peak<=20:raise AssertionError('Missing Specular response')
            areas={str(t):int(np.count_nonzero(mask&(light>=peak*t))) for t in (.1,.25,.5)}
            metrics['powers'][str(power)]={'exported_peak_excess':peak,'normalized_areas':areas,
                                          'unique_blue_values':len(np.unique(crop[:,:,2][mask]))}
        for threshold in ('.1','.25','.5'):
            key=str(float(threshold))
            if metrics['powers']['64']['normalized_areas'][key]>=metrics['powers']['8']['normalized_areas'][key]:
                raise AssertionError('Power broadened the normalized highlight footprint')
        if metrics['powers']['8']['unique_blue_values']<50:raise AssertionError('Highlight remains a hard cut')
        result['devices'][device]=metrics
    result['passed']=True
    return result


if __name__=='__main__':
    parser=argparse.ArgumentParser();parser.add_argument('directory');args=parser.parse_args()
    result=analyze(args.directory)
    (Path(args.directory)/'pixel-analysis.json').write_text(json.dumps(result,indent=2),encoding='utf8')
    print(json.dumps(result,indent=2))
