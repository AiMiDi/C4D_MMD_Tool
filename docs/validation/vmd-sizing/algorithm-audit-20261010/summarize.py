import csv,json,statistics,sys
from pathlib import Path
root=Path(sys.argv[1]) if len(sys.argv)>1 else Path(__file__).resolve().parent
summary={}
for experiment in ('baseline-results','cleanup-results'):
    variants={}
    for path in sorted((root/experiment).glob('*/frames.tsv')):
        rows=list(csv.DictReader(path.open(encoding='utf-8'),delimiter='\t'))
        stages={}
        for stage in ('4','5','6'):
            selected=[r for r in rows if r['stage']==stage]
            active=[r for r in selected if r['wrist_active']=='1']
            stages[stage]={
                'frames':len(selected),
                'point_pair_violations':sum(int(r['point_hits']) for r in selected),
                'frames_with_point_violations':sum(int(r['point_hits'])>0 for r in selected),
                'point_max_depth_pmx':max(float(r['point_max']) for r in selected),
                'segment_sample_pair_violations':sum(int(r['segment_hits']) for r in selected),
                'segment_max_depth_pmx':max(float(r['segment_max']) for r in selected),
                'wrist_trigger_frames':len(active),
                'active_wrist_gap_max_pmx':max(float(r['target_wrists']) for r in active),
                'active_wrist_gap_mean_pmx':statistics.mean(float(r['target_wrists']) for r in active),
                'selected_frames':{r['frame']:r for r in selected if int(r['frame']) in (167,258,264,313,776,854,1609)},
            }
        variants[path.parent.name]=stages
    summary[experiment]=variants
(root/'metrics.json').write_text(json.dumps(summary,ensure_ascii=False,indent=2),encoding='utf-8')
for experiment,variants in summary.items():
    print(experiment)
    for name,stages in variants.items():
        s=stages['6']
        print(name,s['point_pair_violations'],s['segment_sample_pair_violations'],s['active_wrist_gap_mean_pmx'],s['active_wrist_gap_max_pmx'])
