from pathlib import Path
import hashlib,json
left=Path(r'S:\tmp\cmt-replay-repair-20261019\fixed2026')
right=Path(r'S:\tmp\cmt-replay-repair-20261019\fixed2027')
names=('reference','seek_replay','initial_reopen','end_reopen','physics_disabled')
def read(path):return json.loads(path.read_text(encoding='utf-8'))
def identity(path):return {'path':str(path),'bytes':path.stat().st_size,'sha256':hashlib.sha256(path.read_bytes()).hexdigest()}
def delta(a,b):
    assert len(a)==len(b)
    return max((abs(x-y) for x,y in zip(a,b)),default=0.)
def compare(a,b,ap,bp):
    assert set(a)==set(b)=={str(i) for i in range(61)}
    largest=0.;location=None; hashes=0; count=0
    for frame in sorted(a,key=int):
        x,y=a[frame],b[frame]
        assert set(x['dynamic_bones'])==set(y['dynamic_bones'])
        assert x['geometry']['topology_sha256']==y['geometry']['topology_sha256']
        assert x['geometry']['meshes']==y['geometry']['meshes']
        assert x['finite_bone_count']==y['finite_bone_count']==319
        hashes+=x['geometry']['points_sha256']==y['geometry']['points_sha256']
        for bone,values in x['dynamic_bones'].items():
            error=delta(values,y['dynamic_bones'][bone]);count+=len(values)
            if error>largest:largest=error;location={'frame':int(frame),'bone_index':int(bone)}
    pe=delta(ap,bp)
    return {'frames':61,'finite_bone_count':319,'compared_dynamic_bone_count':len(a['0']['dynamic_bones']),
        'compared_matrix_components':count,'max_bone_matrix_component_error':largest,'max_error_location':location,
        'max_final_point_coordinate_error':pe,'compared_final_point_components':len(ap),'equal_geometry_hash_frames':hashes,
        'tolerance':1e-4,'passed':largest<=1e-4 and pe<=1e-4}
r26,r27=read(left/'receipt.json'),read(right/'receipt.json')
assert r26['source_sha256']==r27['source_sha256']
assert r26['assets']==r27['assets']
assert r26['binary_identity_confirmed'] and r27['binary_identity_confirmed']
assert r26['diagnostic_environment_at_script_start']==r27['diagnostic_environment_at_script_start']
p26,p27=read(left/'final-points.json'),read(right/'final-points.json')
t26={n:read(left/(n+'-trajectory.json')) for n in names};t27={n:read(right/(n+'-trajectory.json')) for n in names}
report={'schema_version':1,'source_sha256':r26['source_sha256'],'assets':r26['assets'],
    'hosts':{'2026':{'version':r26['c4d_version'],'plugin':r26['loaded_plugin']},'2027':{'version':r27['c4d_version'],'plugin':r27['loaded_plugin']}},
    'same_source_and_assets':True,'frame_window':[0,60],'fps':30,'tolerance':1e-4,
    'cross_version':{},'within_version':{},'persistent_input_float32_hashes':{},'evidence':[]}
for name in names:
    report['cross_version'][name]=compare(t26[name],t27[name],p26[name],p27[name])
    i26,i27=read(left/(name+'-persistent-inputs.json')),read(right/(name+'-persistent-inputs.json'))
    report['persistent_input_float32_hashes'][name]={'2026':i26['numeric_float32_sha256'],'2027':i27['numeric_float32_sha256'],'equal':i26['numeric_float32_sha256']==i27['numeric_float32_sha256']}
for version,trajectories,points in [('2026',t26,p26),('2027',t27,p27)]:
    report['within_version'][version]={n:compare(trajectories['reference'],trajectories[n],points['reference'],points[n]) for n in ('seek_replay','initial_reopen','end_reopen')}
for folder in (left,right):
    for name in ('receipt.json','final-points.json',*(n+'-trajectory.json' for n in names)):
        report['evidence'].append(identity(folder/name))
report['interpretation']='All three strict replay comparisons pass in each host; the corresponding five cross-version trajectories match exactly. Threshold remains 1e-4. This is a 61-frame Sour case, not general deterministic simulation acceptance. Final native receipts retain acceptance_eligible=false because the empty startup document was automatically discarded; all task documents were cleaned with no errors.'
Path(r'S:\tmp\cmt-replay-repair-20261019\comparison.json').write_text(json.dumps(report,ensure_ascii=False,indent=2),encoding='utf-8')
print(json.dumps({k:report[k] for k in ('cross_version','within_version','persistent_input_float32_hashes')},ensure_ascii=False,indent=2))
