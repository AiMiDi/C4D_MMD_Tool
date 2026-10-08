"""Check Toon frame reset, image opacity and CPU/GPU consistency receipts."""
from pathlib import Path
import argparse,json
import numpy as np
from PIL import Image


def analyze(directory):
    directory=Path(directory)
    receipt=json.loads((directory/'receipt.json').read_text(encoding='utf-8-sig'))
    if not receipt['passed']:
        raise AssertionError('Incomplete native render matrix')
    cases={case['name']:case for case in receipt['cases']}
    arrays={name:np.asarray(Image.open(directory/(name+'.png')).convert('RGBA'),dtype=np.int16) for name in cases}
    results={'module':receipt['module'],'pairs':{},'reset':{},'morph':{},'contour':{},'passed':False}

    def difference(a,b,label,tolerance=2,assert_equal=True):
        delta=np.abs(arrays[a]-arrays[b])
        row={'max_rgb':int(delta[:,:,:3].max()),'max_alpha':int(delta[:,:,3].max()),
             'changed_pixels':int(np.count_nonzero(np.any(delta,axis=2))),
             'mean_rgba':float(delta.mean()),'tolerance':tolerance}
        results['pairs'][label]=row
        if assert_equal and delta.max()>tolerance:
            raise AssertionError((label,row))
        return row

    for device in ('gpu','cpu'):
        for step,frame in ((3,0),(6,0),(4,30),(5,15)):
            first={0:0,15:1,30:2}[frame]
            results['reset'][device+str(step)]=difference(f'morph-{device}-{first}-{frame}',
                                                         f'morph-{device}-{step}-{frame}',device+str(step))
        for step,frame in enumerate((0,15,30)):
            name=f'morph-{device}-{step}-{frame}'
            bindings=cases[name]['binding']
            if len(bindings)!=2 or any(len(row['nodes'])!=40 for row in bindings):
                raise AssertionError('Graph size changed during animation')
            tint=(0.,.7,.9)[step]
            multiply=(0.,.75,.25)[step]
            for row in bindings:
                values=row['values']
                diffuse_r=.2*(1.-.5*multiply if row['material']=='textured' else 1.)+.1*tint
                if max(abs(a-b) for a,b in zip(values[0],[diffuse_r,.4,.6]))>2e-5:
                    raise AssertionError(('Material/Group/Flip color',name,values[0]))
                if abs(values[1]-(.5+.1*tint))>2e-5:
                    raise AssertionError(('Morph opacity',name,values))
                if abs(values[3]-(2./(12.+20.*tint))**.25)>2e-5:
                    raise AssertionError(('Morph power',name,values))
            left,right=arrays[name][90,96],arrays[name][90,224]
            # Embedded texture alpha is independent of factor alpha, which
            # only participates in texture RGB multiplication/addition.
            alpha=(.5+.1*tint)*255
            if abs(int(left[3])-alpha)>2 or abs(int(right[3])-alpha*96/255)>2:
                raise AssertionError(('Rendered opacity',name,left.tolist(),right.tolist()))
            results['morph'][name]={'left':left.tolist(),'right':right.tolist(),'tint':tint,'stable_nodes':40}
    for step,frame in enumerate((0,15,30)):
        difference(f'morph-gpu-{step}-{frame}',f'morph-cpu-{step}-{frame}','device-frame-'+str(frame))
    difference('preview-off','preview-reopen','preview-reset')
    if np.abs(arrays['preview-mixed']-arrays['preview-off']).max()<5:
        raise AssertionError('Preview did not change the rendered image')
    for multipart in ('False','True'):
        base=f'character-{multipart}-'
        difference(base+'off-gpu',base+'zero-width-gpu','edge-zero-'+multipart)
        difference(base+'off-gpu',base+'global-off-gpu','global-off-'+multipart)
        for case in ('base','off','zero-width','wide','zero-spec','global-off','global-control'):
            difference(base+case+'-gpu',base+case+'-cpu','character-device-'+multipart+case)
        for case in ('base','wide'):
            delta=np.max(np.abs(arrays[base+case+'-gpu'][:,:,:3]-arrays[base+'off-gpu'][:,:,:3]),axis=2)
            results['contour'][multipart+'-'+case]={'changed_pixels':int(np.count_nonzero(delta>8))}
        if results['contour'][multipart+'-wide']['changed_pixels']<=results['contour'][multipart+'-base']['changed_pixels']:
            raise AssertionError('Contour width did not increase')
        control=arrays[base+'global-control-gpu']
        magenta=(control[:,:,0]>control[:,:,1]+40)&(control[:,:,2]>control[:,:,1]+40)&(control[:,:,3]>100)
        results['contour'][multipart+'-global-positive']={'magenta_pixels':int(np.count_nonzero(magenta))}
        if np.count_nonzero(magenta)<5:
            raise AssertionError('Global Contour positive control did not draw')
    for case in ('base','off','zero-width','wide','zero-spec','global-off'):
        left,right=f'character-False-{case}-gpu',f'character-True-{case}-gpu'
        strict=case in ('off','zero-width','global-off')
        row=difference(left,right,'mesh-layout-'+case,assert_equal=strict)
        # Native Contour uses object silhouettes. Splitting objects may change
        # line coverage; require the difference to stay on affected line pixels.
        line_mask=(np.max(np.abs(arrays[left][:,:,:3]-arrays['character-False-off-gpu'][:,:,:3]),axis=2)>2)
        line_mask|=(np.max(np.abs(arrays[right][:,:,:3]-arrays['character-True-off-gpu'][:,:,:3]),axis=2)>2)
        delta=np.abs(arrays[left]-arrays[right])
        outside=int(delta[:,:,:3][~line_mask].max())
        row['outside_contour_max_rgb']=outside
        row['contour_variation_pixels']=int(np.count_nonzero(np.any(delta[:,:,:3]>2,axis=2)&line_mask))
        if outside>2 or delta[:,:,3].max()>1:
            raise AssertionError(('Mesh layout changed shading or opacity outside contours',case,row))
    for renderer in ('redshift','redshift_toon'):
        # The actual PMX includes dense alpha edges and Matcap interpolation;
        # retain a three-code-value bound rather than claiming pixel identity.
        difference('actual-stockings-'+renderer+'-gpu','actual-stockings-'+renderer+'-cpu',
                   'actual-device-'+renderer,tolerance=3)
    results['passed']=True
    return results


if __name__=='__main__':
    parser=argparse.ArgumentParser();parser.add_argument('directory');args=parser.parse_args()
    result=analyze(args.directory)
    (Path(args.directory)/'pixel-analysis.json').write_text(json.dumps(result,indent=2),encoding='utf8')
    print(json.dumps({'passed':result['passed'],'pairs':len(result['pairs'])}))
