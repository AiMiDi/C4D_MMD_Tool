"""Bounded real-model physics/replay checks and read-only build-tool inventory.

Load inside Cinema 4D with runpy, then call one ExtendedNativeValidation stage
per MCP request. Importing this module does not create or evaluate documents.
Host Python can run --inventory without Cinema 4D.
"""
from array import array
from pathlib import Path
import argparse
import contextlib
import hashlib
import json
import math
import os
import shutil
import statistics
import struct
import sys
import time
import traceback

try:
    import c4d
except ImportError:
    c4d = None

REPOSITORY = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPOSITORY/'scripts'))
import c4d_runtime_regression as regression
DEFAULT_MANIFEST = REPOSITORY / '_build_msvc/validation/real-assets-and-materials/native/manifest.json'
DEFAULT_INVENTORY = REPOSITORY / '_build_msvc/validation/real-assets-and-materials/motion-inventory.json'
RUN_NAMES = ('reference', 'seek_replay', 'initial_reopen', 'end_reopen', 'physics_disabled')


def source_identity(repository):
    digest = hashlib.sha256()
    for directory in ('source', 'res/S24_up'):
        for path in sorted((Path(repository)/directory).rglob('*')):
            if path.is_file():
                digest.update(path.relative_to(repository).as_posix().encode('utf-8'))
                digest.update(path.read_bytes())
    return digest.hexdigest()


def percentile(values, fraction):
    ordered = sorted(values)
    return ordered[math.ceil((len(ordered)-1)*fraction)] if ordered else None


def matrix_values(matrix):
    values = [float(value) for vector in (matrix.off, matrix.v1, matrix.v2, matrix.v3)
              for value in (vector.x, vector.y, vector.z)]
    if not all(math.isfinite(value) for value in values):
        raise AssertionError('Non-finite runtime bone matrix')
    return values


def numeric_difference(left, right):
    if len(left) != len(right):
        raise AssertionError('Compared numeric arrays have different lengths')
    return max((abs(a-b) for a,b in zip(left,right)), default=0.)


def position_distance(left, right):
    return math.sqrt(sum((a-b)**2 for a,b in zip(left[:3],right[:3])))


def capture_control_inputs(suite):
    """Read control deltas and synchronized bases without evaluating the document."""
    controls = []
    identity = c4d.Matrix()
    for bone in suite.bones():
        tag = bone.GetTag(regression.BONE_TAG_ID)
        control = tag[suite.ids['PMX_BONE_CONTROL_LINK']]
        if not isinstance(control,c4d.BaseObject):
            continue
        relative = control.GetRelMl()
        identity_error = max((relative.off-identity.off).GetLength(),
                             (relative.v1-identity.v1).GetLength(),
                             (relative.v2-identity.v2).GetLength(),
                             (relative.v3-identity.v3).GetLength())
        controls.append({'bone_index':int(tag[suite.ids['PMX_BONE_INDEX']]),
            'name':control.GetName(),'relative_matrix':matrix_values(relative),
            'frozen_local_matrix':matrix_values(control.GetFrozenMln()),
            'global_matrix':matrix_values(control.GetMg()),
            'inactive_by_native_identity_tolerance':identity_error<=1e-5,
            'relative_identity_error':identity_error})
    return {'controls':sorted(controls,key=lambda item:item['bone_index']),
            'inactive_count':sum(item['inactive_by_native_identity_tolerance'] for item in controls),
            'count':len(controls)}


def capture_persistent_inputs(suite):
    """Read bind/configuration values; do not seek, evaluate or change the scene."""
    def parameters(node, prefix):
        container = node.GetDataInstance()
        result = {}
        for name, parameter in sorted(suite.ids.items()):
            if not name.startswith(prefix):
                continue
            value = container[parameter]
            if isinstance(value,c4d.Vector):
                result[name] = [float(value.x),float(value.y),float(value.z)]
            elif isinstance(value,(str,int,float,bool)):
                result[name] = value
        return result

    bones = []
    for bone in suite.bones():
        tag = bone.GetTag(regression.BONE_TAG_ID)
        bones.append({'index':int(tag[suite.ids['PMX_BONE_INDEX']]),'name':bone.GetName(),
            'frozen_local_matrix':matrix_values(bone.GetFrozenMln()),
            'frozen_position':suite.vector(bone.GetFrozenPos()),
            'frozen_rotation':suite.vector(bone.GetFrozenRot()),
            'frozen_scale':suite.vector(bone.GetFrozenScale()),'tag_parameters':parameters(tag,'PMX_BONE_')})
    result = {'bones':sorted(bones,key=lambda item:item['index']),
        'rigids':[{'name':node.GetName(),'parameters':parameters(node,'RIGID_')}
                  for node in suite.nodes(regression.RIGID_ID)],
        'joints':[{'name':node.GetName(),'parameters':parameters(node,'JOINT_')}
                  for node in suite.nodes(regression.JOINT_ID)],
        'model_physics':parameters(suite.model,'MODEL_PHYSICS_')}
    digest = hashlib.sha256()
    def hash_float32(value, path=''):
        if isinstance(value,dict):
            for key,item in sorted(value.items()):
                hash_float32(item,path+'/'+key)
        elif isinstance(value,list):
            for index,item in enumerate(value):
                hash_float32(item,path+'/'+str(index))
        elif isinstance(value,(float,int,bool)):
            digest.update(path.encode('utf-8'))
            digest.update(struct.pack('<f',float(value)))
    hash_float32(result)
    result['numeric_float32_sha256'] = digest.hexdigest()
    return result


def local_build_inventory(repository=REPOSITORY):
    """Inspect existing paths/caches; never configure, build or run an installer."""
    repository = Path(repository)
    sdks = sorted(path.name for path in repository.iterdir() if path.is_dir() and path.name.startswith('sdk_'))
    graphs = []
    for path in sorted((repository/'_build_msvc').glob('*/CMakeCache.txt')):
        selected = {}
        for line in path.read_text(encoding='utf-8', errors='replace').splitlines():
            if ':' in line and '=' in line and not line.startswith(('#','//')):
                key, value = line.split('=',1)
                key = key.split(':',1)[0]
                if key in ('CMAKE_GENERATOR','CMAKE_HOME_DIRECTORY','CMT_ENABLE_RUNTIME_REGRESSION','CMAKE_GENERATOR_TOOLSET'):
                    selected[key] = value
        graphs.append({'path':str(path), 'cache':selected})
    binaries = [{'path':str(path), 'bytes':path.stat().st_size, 'sha256':regression.sha256(path),
                 'historical_baseline_provenance_confirmed':False}
                for path in sorted((repository/'_build_msvc').glob('*/bin/*/plugins/mmdtool/*.xdl64'))]
    candidates = {Path(path) for path in (
        r'C:\Program Files\Inno Setup 6\ISCC.exe', r'C:\Program Files (x86)\Inno Setup 6\ISCC.exe',
        r'C:\Program Files\Inno Setup 7\ISCC.exe', r'C:\Program Files (x86)\Inno Setup 7\ISCC.exe')}
    on_path = shutil.which('ISCC.exe')
    if on_path:
        candidates.add(Path(on_path))
    if os.name == 'nt':
        import winreg
        for hive in (winreg.HKEY_LOCAL_MACHINE,winreg.HKEY_CURRENT_USER):
            for branch in (r'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall',
                           r'SOFTWARE\WOW6432Node\Microsoft\Windows\CurrentVersion\Uninstall'):
                try:
                    with winreg.OpenKey(hive,branch) as parent:
                        for index in range(winreg.QueryInfoKey(parent)[0]):
                            try:
                                with winreg.OpenKey(parent,winreg.EnumKey(parent,index)) as entry:
                                    name = winreg.QueryValueEx(entry,'DisplayName')[0]
                                    if 'inno setup' in str(name).lower():
                                        location = winreg.QueryValueEx(entry,'InstallLocation')[0]
                                        candidates.add(Path(location)/'ISCC.exe')
                            except OSError:
                                continue
                except OSError:
                    continue
    compilers = [{'path':str(path), 'sha256':regression.sha256(path)} for path in sorted(candidates) if path.is_file()]
    configured = {Path(item['cache'].get('CMAKE_HOME_DIRECTORY','')).name for item in graphs}
    return {'created_utc':regression.utc_now(), 'repository':str(repository), 'sdk_roots':sdks,
            'graphs':graphs, 'unconfigured_sdk_roots':[name for name in sdks if name not in configured],
            'existing_plugin_binaries':binaries, 'inno_compilers':compilers,
            'installer_executed':False, 'historical_performance_baseline_confirmed':False}


class ExtendedNativeValidation:
    def __init__(self, manifest_path=DEFAULT_MANIFEST, inventory_path=DEFAULT_INVENTORY,
                 output=r'S:\tmp\cmt-extended-validation', end_frame=60):
        if c4d is None:
            raise RuntimeError('Native validation must run inside Cinema 4D')
        if not 1 <= end_frame <= 120:
            raise ValueError('Use a bounded frame window between 1 and 120')
        self.output = Path(output)
        self.output.mkdir(parents=True, exist_ok=True)
        self.manifest = json.loads(Path(manifest_path).read_text(encoding='utf-8'))
        self.manifest['output'] = str(self.output)
        self.inventory = json.loads(Path(inventory_path).read_text(encoding='utf-8'))
        self.motion = next(item for item in self.inventory['files'] if item['counts']['bone_keys'] > 0)
        self.model = self.inventory['model']
        self.suite = regression.Suite(c4d,self.manifest)
        self.retired_documents = []
        self.terminated = False
        self.end_frame = end_frame
        self.runs, self.active_run = {}, None
        self.bone_objects, self.dynamic_indices = {}, []
        self.initial_scene, self.end_scene = self.output/'initial.c4d',self.output/'continuous_end.c4d'
        loaded = regression.loaded_plugin_binary()
        current_source = source_identity(REPOSITORY)
        self.receipt = {'schema_version':1, 'created_utc':regression.utc_now(), 'native_executed':True,
            'status':'running', 'acceptance_eligible':False, 'c4d_version':c4d.GetC4DVersion(),
            'sdk':self.manifest['sdk'],
            'diagnostic_environment_at_script_start':{key:os.environ.get(key)
                for key in ('CMT_RUNTIME_PROFILE','CMT_ANIM_FLOW_DEBUG','CMT_INITIAL_STATE_DEBUG')},
            'loaded_plugin':loaded, 'manifest':str(manifest_path),
            'source_sha256':self.manifest['source_sha256'], 'current_source_sha256':current_source,
            'source_provenance':'prepared manifest; current checkout is checked separately',
            'current_checkout_matches_manifest':current_source==self.manifest['source_sha256'],
            'binary_identity_confirmed':bool(loaded and loaded['sha256']==self.manifest['plugin_binary']['sha256']),
            'assets':[{'path':item['path'],'sha256':item['sha256']} for item in (self.model,self.motion)],
            'frame_window':[0,end_frame], 'simulation_fps':30, 'phases':[], 'runs':{},
            'same_quality_historical_performance_accepted':False, 'assets_modified':False}
        self.receipt['document_owner_run_id'] = self.suite.document_owner_run_id
        self.write_receipt()

    def write_receipt(self):
        self.receipt['runs'] = {name:{key:value for key,value in run.items() if key not in ('states','final_points')}
                                for name,run in self.runs.items()}
        (self.output/'receipt.json').write_text(json.dumps(self.receipt,ensure_ascii=False,indent=2),encoding='utf-8')

    @contextlib.contextmanager
    def active(self):
        previous = c4d.documents.GetActiveDocument()
        if self.suite.doc:
            c4d.documents.SetActiveDocument(self.suite.doc)
        try:
            yield
        finally:
            regression.restore_active_document(c4d,previous)
            c4d.EventAdd()

    def phase(self, name, action):
        if self.terminated:
            raise RuntimeError('This validator has ended; use a new output/run rather than replaying a failed phase')
        started = time.perf_counter()
        try:
            if not self.receipt['binary_identity_confirmed']:
                raise AssertionError('Loaded plugin does not match the prepared binary')
            with self.active():
                result = action()
            self.receipt['phases'].append({'name':name,'status':'passed','seconds':time.perf_counter()-started,'result':result})
        except Exception as error:
            self.receipt['phases'].append({'name':name,'status':'failed','seconds':time.perf_counter()-started,
                                          'error':str(error),'traceback':traceback.format_exc()})
            self.receipt['status'] = 'failed'
            self.receipt['acceptance_eligible'] = False
            self.receipt['failure_scenes'] = self.suite.save_failure_scenes(name)
            # Preserve the failing phase before closing its owned documents.
            # An evidence-write error must not leave those documents open.
            try:
                self.write_receipt()
            except Exception as write_error:
                self.receipt['failure_receipt_write_error'] = str(write_error)
            finally:
                try:
                    cleanup = self.close()
                except Exception as cleanup_error:
                    self.terminated = True
                    cleanup = {'errors':[{'error_type':type(cleanup_error).__name__,'error':str(cleanup_error)}],
                               'original_document_restored':False}
            self.receipt['cleanup'] = cleanup
            try:
                self.write_receipt()
            except Exception as write_error:
                self.receipt['cleanup_receipt_write_error'] = str(write_error)
            raise
        self.write_receipt()
        return result

    def identify_bones(self):
        ids = self.suite.ids
        self.bone_objects = {int(bone.GetTag(regression.BONE_TAG_ID)[ids['PMX_BONE_INDEX']]):bone
                             for bone in self.suite.bones()}
        indices = {int(rigid[ids['RIGID_RELATED_BONE_INDEX']]) for rigid in self.suite.nodes(regression.RIGID_ID)
                   if int(rigid[ids['RIGID_PHYSICS_MODE']]) != 0}
        self.dynamic_indices = sorted(indices.intersection(self.bone_objects))
        if not self.dynamic_indices:
            raise AssertionError('No actual non-static rigid-bound runtime bones were found')
        if len(self.bone_objects) != self.model['bones']:
            raise AssertionError('Real model bone count differs from the input inventory')

    def evaluate(self, frame):
        before = time.perf_counter()
        self.suite.evaluate(frame)
        return (time.perf_counter()-before)*1000.

    def geometry(self):
        points, topology, meshes = array('d'),hashlib.sha256(),[]
        for mesh in self.suite.walk(self.suite.doc.GetFirstObject()):
            if not isinstance(mesh,c4d.PolygonObject):
                continue
            evaluated = mesh.GetDeformCache() or mesh.GetCache()
            if not isinstance(evaluated,c4d.PolygonObject):
                raise AssertionError('Skinned mesh has no evaluated cache in its evaluated document')
            if evaluated.GetPointCount() != mesh.GetPointCount():
                raise AssertionError('Evaluated mesh point count differs from source topology')
            meshes.append({'name':mesh.GetName(),'vertices':mesh.GetPointCount(),'polygons':mesh.GetPolygonCount()})
            topology.update(mesh.GetName().encode('utf-8'))
            for polygon in mesh.GetAllPolygons():
                topology.update(array('i',(polygon.a,polygon.b,polygon.c,polygon.d)).tobytes())
            matrix = mesh.GetMg()
            for point in evaluated.GetAllPoints():
                world = matrix*point
                values = (world.x,world.y,world.z)
                if not all(math.isfinite(value) for value in values):
                    raise AssertionError('Non-finite simulated mesh vertex')
                points.extend(values)
        if not meshes:
            raise AssertionError('The model contains no evaluated polygon mesh')
        return {'meshes':meshes,'topology_sha256':topology.hexdigest(),
                'points_sha256':hashlib.sha256(points.tobytes()).hexdigest()},points

    def snapshot(self):
        all_bones = {str(index):matrix_values(bone.GetMg()) for index,bone in self.bone_objects.items()}
        geometry,points = self.geometry()
        # Authoring rigid objects are configuration, not simulated transforms.
        authoring = [matrix_values(rigid.GetMg()) for rigid in self.suite.nodes(regression.RIGID_ID)]
        return {'dynamic_bones':{str(index):all_bones[str(index)] for index in self.dynamic_indices},
                'finite_bone_count':len(all_bones),'geometry':geometry,
                'authoring_rigid_count':len(authoring)},points

    def save_scene(self, path):
        if not c4d.documents.SaveDocument(self.suite.doc,str(path),c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST,c4d.FORMAT_C4DEXPORT):
            raise AssertionError('Failed to save the task-owned replay input scene')

    def retain_current_document(self):
        # An MCP request can retain its initial document in the host postcheck.
        # Keep prior task documents alive until explicit validator cleanup.
        if self.suite.doc is not None:
            self.suite.register_document(self.suite.doc, 'retained replay document')
            self.retired_documents.append(self.suite.doc)
            self.suite.doc = self.suite.model = None

    def prepare_run(self, name, origin='fresh', physics=True):
        if name not in RUN_NAMES:
            raise ValueError('Choose a documented run name')
        expected_origin = {'reference':'fresh','seek_replay':'seek','initial_reopen':'initial',
                           'end_reopen':'saved','physics_disabled':'initial'}[name]
        if origin != expected_origin or bool(physics) != (name!='physics_disabled'):
            raise ValueError('Run name, reconstruction origin and physics state must follow the documented contract')
        def action():
            if name in self.runs:
                raise ValueError('Use a new validator/output for retrying a completed run')
            for asset in (self.model,self.motion):
                if regression.sha256(asset['path']) != asset['sha256']:
                    raise AssertionError('Source asset identity changed')
            if origin == 'fresh':
                self.retain_current_document()
                self.suite.new_document('extended physics ' + name)
                self.suite.call('import_model',self.model['path'])
                self.suite.model = self.suite.doc.GetActiveObject()
                self.suite.model[self.suite.ids['MODEL_PHYSICS_ENABLED']] = False
                self.suite.call('import_motion',self.motion['path'],ignore_physics=False)
                self.suite.model[self.suite.ids['MODEL_MODE']] = self.suite.ids['MODEL_MODE_ANIM']
            elif origin in ('initial','saved'):
                path = self.initial_scene if origin=='initial' else self.end_scene
                if not path.is_file():
                    raise AssertionError('Replay input scene does not exist: '+str(path))
                reopened = c4d.documents.LoadDocument(str(path),c4d.SCENEFILTER_OBJECTS|c4d.SCENEFILTER_MATERIALS,None)
                if reopened is None:
                    raise AssertionError('Replay scene reconstruction failed')
                self.suite.register_document(reopened, 'extended reopened ' + name)
                self.retain_current_document()
                self.suite.doc = reopened
                c4d.documents.InsertBaseDocument(reopened)
                c4d.documents.SetActiveDocument(reopened)
                models = self.suite.nodes(regression.MODEL_ID)
                if len(models)!=1:
                    raise AssertionError('Reconstructed scene has no unique model')
                self.suite.model = models[0]
            elif origin == 'seek':
                if not self.active_run or not self.runs[self.active_run]['complete']:
                    raise AssertionError('Seek replay requires a completed continuous run')
            else:
                raise ValueError('origin must be fresh, initial, saved or seek')
            self.suite.doc.SetFps(30)
            self.suite.doc.SetActiveObject(self.suite.model)
            ids = self.suite.ids
            if self.suite.model[ids['MODEL_MODE']] != ids['MODEL_MODE_ANIM']:
                raise AssertionError('Replay input must retain ANIM; do not commit the posed state as bind')
            if not self.suite.model[ids['MODEL_PHYSICS_RESET_ON_SEEK']]:
                self.suite.model[ids['MODEL_PHYSICS_RESET_ON_SEEK']] = True
            if bool(self.suite.model[ids['MODEL_PHYSICS_ENABLED']]) != bool(physics):
                self.suite.model[ids['MODEL_PHYSICS_ENABLED']] = bool(physics)
            self.identify_bones()
            persistent = capture_persistent_inputs(self.suite)
            (self.output/(name+'-persistent-inputs.json')).write_text(
                json.dumps(persistent,ensure_ascii=False,indent=2),encoding='utf-8')
            (self.output/(name+'-control-inputs.json')).write_text(
                json.dumps(capture_control_inputs(self.suite),ensure_ascii=False,indent=2),encoding='utf-8')
            elapsed = self.evaluate(0)
            state,points = self.snapshot()
            offsets = [matrix_values(bone.GetMg())[:3] for bone in self.bone_objects.values()]
            extent = math.sqrt(sum((max(point[axis] for point in offsets)-min(point[axis] for point in offsets))**2
                                   for axis in range(3)))
            if extent <= 0.:
                raise AssertionError('Cannot derive a finite model extent for continuity checks')
            self.runs[name] = {'origin':origin,'physics_enabled':bool(physics),'next_frame':1,'complete':False,
                'states':{'0':state},'final_points':points,'evaluate_ms':[elapsed],'model_extent':extent,
                'max_dynamic_step_distance':0.,'dynamic_bone_indices':self.dynamic_indices.copy(),
                'continuity_guard':'one model extent per adjacent 30fps frame; gross divergence only'}
            self.active_run = name
            if name=='reference':
                self.save_scene(self.initial_scene)
            return {'run':name,'origin':origin,'frame':0,'dynamic_bone_count':len(self.dynamic_indices),
                    'finite_bone_count':state['finite_bone_count'],'geometry':state['geometry'],'evaluate_ms':elapsed}
        return self.phase('prepare_'+name,action)

    def advance(self, max_frames=5, max_seconds=30.):
        if not 1 <= max_frames <= 10 or not 0. < max_seconds <= 45.:
            raise ValueError('Each MCP stage permits at most 10 frames and a 45-second soft budget')
        def action():
            if self.active_run is None:
                raise AssertionError('Prepare a run first')
            run,started = self.runs[self.active_run],time.perf_counter()
            processed = []
            while run['next_frame'] <= self.end_frame and len(processed)<max_frames:
                if processed and time.perf_counter()-started >= max_seconds:
                    break
                frame = run['next_frame']
                elapsed = self.evaluate(frame)
                state,points = self.snapshot()
                previous = run['states'][str(frame-1)]
                if state['geometry']['meshes'] != previous['geometry']['meshes'] or state['geometry']['topology_sha256'] != previous['geometry']['topology_sha256']:
                    raise AssertionError('Mesh identity or topology changed during simulation')
                step = max(position_distance(values,previous['dynamic_bones'][index])
                           for index,values in state['dynamic_bones'].items())
                if step > run['model_extent']:
                    raise AssertionError('Gross simulation discontinuity: adjacent step exceeds the entire model extent')
                run['max_dynamic_step_distance'] = max(run['max_dynamic_step_distance'],step)
                run['states'][str(frame)],run['final_points'] = state,points
                run['evaluate_ms'].append(elapsed)
                run['next_frame'] += 1
                processed.append(frame)
            run['complete'] = run['next_frame'] > self.end_frame
            run['timing'] = {'samples':len(run['evaluate_ms']),'median_ms':statistics.median(run['evaluate_ms']),
                             'p95_ms':percentile(run['evaluate_ms'],.95),'max_ms':max(run['evaluate_ms']),
                             'zero_frame_initialization_or_seek_evaluate_ms':run['evaluate_ms'][0],
                             'zero_frame_scope':'time setting and two native passes; includes runtime cold reset if requested; load/import/capture excluded',
                             'measurement':'time setting and two ExecutePasses calls; Python capture/JSON excluded; native diagnostics included'}
            steady = run['evaluate_ms'][10:]
            run['timing']['steady_after_frame_9'] = {'samples':len(steady),
                'median_ms':statistics.median(steady) if steady else None,
                'p95_ms':percentile(steady,.95),'max_ms':max(steady) if steady else None}
            (self.output/(self.active_run+'-trajectory.json')).write_text(
                json.dumps(run['states'],ensure_ascii=False),encoding='utf-8')
            return {'run':self.active_run,'processed_frames':processed,'next_frame':run['next_frame'],
                    'complete':run['complete'],'max_dynamic_step_distance':run['max_dynamic_step_distance'],
                    'timing':run['timing']}
        return self.phase('advance_'+str(self.active_run),action)

    def save_completed_scene(self):
        def action():
            if self.active_run!='reference' or not self.runs['reference']['complete']:
                raise AssertionError('Save the continuous end input after finishing the reference run')
            self.save_scene(self.end_scene)
            return {'scene':str(self.end_scene),'frame':self.end_frame,
                    'acceptance':'persistent inputs will be replayed from frame zero; live Bullet state is not asserted saved'}
        return self.phase('save_continuous_end',action)

    def compare_runs(self, reference='reference', candidate='seek_replay', tolerance=1e-4):
        def action():
            left,right = self.runs[reference],self.runs[candidate]
            if not left['complete'] or not right['complete'] or not left['physics_enabled'] or not right['physics_enabled']:
                raise AssertionError('Compare two completed physics runs from the same initial input')
            if left['dynamic_bone_indices']!=right['dynamic_bone_indices'] or left['states'].keys()!=right['states'].keys():
                raise AssertionError('Reconstructed runtime bone identities or frame coverage changed')
            largest = 0.
            for frame,state in left['states'].items():
                other = right['states'][frame]
                if state['geometry']['meshes']!=other['geometry']['meshes'] or state['geometry']['topology_sha256']!=other['geometry']['topology_sha256']:
                    raise AssertionError('Replay mesh identity/topology changed')
                largest = max(largest,max(numeric_difference(values,other['dynamic_bones'][index])
                                          for index,values in state['dynamic_bones'].items()))
            point_error = numeric_difference(left['final_points'],right['final_points'])
            if largest>tolerance or point_error>tolerance:
                raise AssertionError('Replay differs: bone matrix max='+str(largest)+', final point coordinate max='+str(point_error))
            result = {'reference':reference,'candidate':candidate,'frames':self.end_frame+1,
                      'max_bone_matrix_component_error':largest,'max_final_point_coordinate_error':point_error,
                      'tolerance':tolerance,'same_initial_continuous_replay':True}
            self.receipt.setdefault('replay_comparisons',{})[candidate] = result
            return result
        return self.phase('compare_'+candidate,action)

    def verify_physics_participation(self):
        def action():
            enabled,disabled = self.runs['reference'],self.runs['physics_disabled']
            if not enabled['complete'] or not disabled['complete'] or disabled['physics_enabled']:
                raise AssertionError('Complete the enabled/disabled paired runs first')
            changed,largest = set(),0.
            for frame,state in enabled['states'].items():
                other = disabled['states'][frame]
                for index,values in state['dynamic_bones'].items():
                    error = numeric_difference(values,other['dynamic_bones'][index])
                    largest = max(largest,error)
                    if error>1e-5:
                        changed.add(index)
            if not changed:
                raise AssertionError('Physics did not change any actual non-static rigid-bound bone')
            result = {'affected_runtime_bone_count':len(changed),'max_matrix_component_difference':largest,
                      'affected_runtime_bone_indices':sorted(map(int,changed)),
                      'authoring_rigid_matrices_not_used_as_simulation_proof':True}
            self.receipt['physics_participation'] = result
            return result
        return self.phase('physics_participation',action)

    def check_control_delta(self):
        """Bounded fixed-frame smoke for an existing, task-owned linked control."""
        def action():
            if self.suite.doc is None or self.suite.model is None:
                raise AssertionError('Prepare a task-owned model before testing its controls')
            ids = self.suite.ids
            candidates = []
            for bone in self.suite.bones():
                tag = bone.GetTag(regression.BONE_TAG_ID)
                control = tag[ids['PMX_BONE_CONTROL_LINK']]
                eligible = bool(tag[ids['PMX_BONE_LOCAL_IS_COORDINATE']] or tag[ids['PMX_BONE_IS_FIXED_AXIS']])
                movable = bool(tag[ids['PMX_BONE_TRANSLATABLE']] or tag[ids['PMX_BONE_ROTATABLE']])
                if eligible and movable and isinstance(control,c4d.BaseObject):
                    candidates.append((bool(tag[ids['PMX_BONE_IS_FIXED_AXIS']]),bone,tag,control))
            if not candidates:
                raise AssertionError('No eligible linked control exists in this task model')
            _,bone,tag,control = min(candidates,key=lambda item:item[0])
            original_relative = control.GetRelMl()
            original_frozen_position = control.GetFrozenPos()
            original_frozen_rotation = control.GetFrozenRot()
            original_frozen_scale = control.GetFrozenScale()
            original_physics = bool(self.suite.model[ids['MODEL_PHYSICS_ENABLED']])
            original_time = self.suite.doc.GetTime()
            try:
                if original_physics:
                    self.suite.model[ids['MODEL_PHYSICS_ENABLED']] = False
                control.SetRelMl(c4d.Matrix())
                self.evaluate(0)
                baseline = matrix_values(bone.GetMg())
                baseline_geometry,baseline_points = self.geometry()
                # This lies inside the existing native inactive-control bound.
                control.SetRelMl(c4d.Matrix(off=c4d.Vector(2e-6,0.,0.)))
                self.evaluate(0)
                inactive_error = numeric_difference(baseline,matrix_values(bone.GetMg()))
                inactive_geometry,inactive_points = self.geometry()
                inactive_geometry_error = numeric_difference(baseline_points,inactive_points)
                if inactive_error>1e-5:
                    raise AssertionError('Inactive control perturbed the zero-input pose: '+str(inactive_error))
                if inactive_geometry_error>1e-5:
                    raise AssertionError('Inactive control perturbed evaluated geometry: '+str(inactive_geometry_error))
                active = c4d.utils.HPBToMatrix(c4d.Vector(.17,.23,.11))
                active.off = c4d.Vector(.13,.07,-.09)
                control.SetRelMl(active)
                self.evaluate(0)
                active_error = numeric_difference(baseline,matrix_values(bone.GetMg()))
                active_geometry,active_points = self.geometry()
                if active_error<=1e-5:
                    raise AssertionError('Nonidentity linked control did not change its actual bone pose')
                control.SetRelMl(c4d.Matrix())
                self.evaluate(0)
                reset_error = numeric_difference(baseline,matrix_values(bone.GetMg()))
                if reset_error>1e-5:
                    raise AssertionError('Reset linked control did not recover the zero-input pose: '+str(reset_error))
                geometry,reset_points = self.geometry()
                reset_geometry_error = numeric_difference(baseline_points,reset_points)
                if reset_geometry_error>1e-5:
                    raise AssertionError('Reset linked control did not recover evaluated geometry: '+str(reset_geometry_error))
                result = {'bone_index':int(tag[ids['PMX_BONE_INDEX']]),'control_name':control.GetName(),
                    'fixed_frame':0,'physics_enabled':False,'max_inactive_pose_error':inactive_error,
                    'max_inactive_geometry_error':inactive_geometry_error,
                    'nonidentity_pose_difference':active_error,'max_reset_pose_error':reset_error,
                    'nonidentity_geometry_difference':numeric_difference(baseline_points,active_points),
                    'max_reset_geometry_error':reset_geometry_error,
                    'bone_translatable':bool(tag[ids['PMX_BONE_TRANSLATABLE']]),
                    'bone_rotatable':bool(tag[ids['PMX_BONE_ROTATABLE']]),
                    'finite_evaluated_geometry':{'baseline':baseline_geometry,'inactive':inactive_geometry,
                                                 'active':active_geometry,'reset':geometry}}
                self.receipt['control_delta_smoke'] = result
                return result
            finally:
                control.SetFrozenPos(original_frozen_position)
                control.SetFrozenRot(original_frozen_rotation)
                control.SetFrozenScale(original_frozen_scale)
                control.SetRelMl(original_relative)
                self.suite.doc.SetTime(original_time)
                if bool(self.suite.model[ids['MODEL_PHYSICS_ENABLED']])!=original_physics:
                    self.suite.model[ids['MODEL_PHYSICS_ENABLED']] = original_physics
                for _ in range(2):
                    self.suite.doc.ExecutePasses(None,True,True,True,c4d.BUILDFLAGS_NONE)
        return self.phase('control_delta_smoke',action)

    def finalize(self):
        self.receipt['current_source_sha256_at_start'] = self.receipt['current_source_sha256']
        self.receipt['current_source_sha256'] = source_identity(REPOSITORY)
        self.receipt['current_checkout_matches_manifest'] = (
            self.receipt['current_source_sha256']==self.manifest['source_sha256'])
        complete = all(name in self.runs and self.runs[name]['complete'] for name in RUN_NAMES)
        comparisons = self.receipt.get('replay_comparisons',{})
        complete = complete and all(name in comparisons for name in ('seek_replay','initial_reopen','end_reopen'))
        complete = complete and 'physics_participation' in self.receipt
        failed = any(phase['status']=='failed' for phase in self.receipt['phases'])
        self.receipt['acceptance_eligible'] = complete and not failed and self.receipt['binary_identity_confirmed']
        self.receipt['status'] = 'passed' if self.receipt['acceptance_eligible'] else 'failed' if failed else 'incomplete'
        self.receipt['current_source_accepted'] = self.receipt['acceptance_eligible'] and self.receipt['current_checkout_matches_manifest']
        self.receipt['finished_utc'] = regression.utc_now()
        self.write_receipt()
        return self.receipt

    def close(self):
        self.terminated = True
        cleanup = self.suite.close()
        self.retired_documents = [document for document in self.retired_documents
                                  if any(regression.same_document(document,owned)
                                         for owned in self.suite.owned_documents)]
        self.receipt['cleanup'] = cleanup
        if cleanup['errors'] or not cleanup['original_document_restored']:
            self.receipt['acceptance_eligible'] = False
        c4d.EventAdd()
        return cleanup


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inventory',type=Path,help='Write existing build/tool metadata; no native tests or builds run')
    arguments = parser.parse_args()
    if arguments.inventory:
        report = local_build_inventory()
        arguments.inventory.parent.mkdir(parents=True,exist_ok=True)
        arguments.inventory.write_text(json.dumps(report,ensure_ascii=False,indent=2),encoding='utf-8')
        print(json.dumps(report,ensure_ascii=False,indent=2))
    else:
        parser.print_help()
