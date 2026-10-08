"""Native negative paths and UI/production contracts for the Toon proposal.

Fault cases require an explicit CMT_ENABLE_RUNTIME_REGRESSION build. Shipping
checks use the same production transport with all fault controls compiled out.
"""

from pathlib import Path
import json


def private_fault(target, stage):
    data = target.GetDataInstance()
    private = data.GetContainer(1068715)
    private.SetInt32(9001, stage)
    data.SetContainer(1068715, private)


def signature(suite):
    """Compare persistent model links, mesh assignments and attribute identities."""
    import maxon
    import native_toon_test as toon
    c4d,ids = suite.c4d,suite.ids
    model = suite.nodes(1056724)[0] if suite.nodes(1056724) else None
    materials = suite.doc.GetMaterials()
    rows = []
    for mat in materials:
        metadata = mat.GetDataInstance().GetContainer(1068715)
        node = mat.GetNodeMaterialReference()
        graph = node.GetGraph(maxon.Id(toon.SPACE)) if node.HasSpace(maxon.Id(toon.SPACE)) else None
        rows.append({"name":mat.GetName(),"profile":metadata.GetInt32(170),"token":metadata.GetString(102),
                     "nodes":sorted(str(n.GetId()) for n in graph.GetRoot().GetChildren()) if graph else []})
    links = []
    if model:
        previous = model[ids["MODEL_MATERIAL_LIST"]]
        for index in range(2):
            model[ids["MODEL_MATERIAL_LIST"]] = index
            material = model[ids["MODEL_MATERIAL_LINK"]]
            mesh = model[ids["MODEL_MATERIAL_MESH_LINK"]]
            links.append((material.GetName() if material else None,mesh.GetName() if mesh else None))
        model[ids["MODEL_MATERIAL_LIST"]] = previous
    meshes = []
    for mesh in suite.nodes(c4d.Opolygon):
        attributes = []
        for did,entry in mesh.GetUserDataContainer():
            value = mesh[did]
            value = suite.vector(value) if isinstance(value,c4d.Vector) else str(value)
            attributes.append((str(did),entry.GetString(c4d.DESC_NAME),value))
        tags = [(tag.GetMaterial().GetName() if tag.GetMaterial() else None,tag[c4d.TEXTURETAG_RESTRICTION])
                for tag in mesh.GetTags() if tag.CheckType(c4d.Ttexture)]
        meshes.append({"name":mesh.GetName(),"attributes":attributes,"assignments":tags})
    return {"materials":rows,"links":links,"meshes":meshes,
            "renderer":suite.doc.GetActiveRenderData()[c4d.RDATA_RENDERENGINE],"fps":suite.doc.GetFps()}


def run_faults(c4d, output):
    import shader_binding_test as binding
    import native_toon_test as toon
    from c4d_runtime_regression import load_resource_ids,loaded_plugin_binary
    output = Path(output)
    output.mkdir(parents=True,exist_ok=True)
    fixtures = toon.prepare(output)
    suite = binding.production_suite(c4d,{"output":str(output),"fixtures":fixtures,
        "resource_ids":load_resource_ids(Path(__file__).resolve().parents[2])},material_type="standard")
    receipt = {"module":loaded_plugin_binary(),"fault_build_required":True,"cases":[],"passed":False}
    try:
        suite.new_model("toon-binding.pmx")
        model,ids = suite.model,suite.ids
        model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
        model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = False
        model[ids["MODEL_MATERIAL_LIST"]] = 0
        model.GetDescription(c4d.DESCFLAGS_DESC_0)
        for stage in (2,3,4,5):
            suite.doc.FlushUndoBuffer()
            private_fault(model,stage)
            before = signature(suite)
            (output/"fault-before.json").write_text(json.dumps(before,indent=2),encoding="utf8")
            if model.GetDataInstance().GetContainer(1068715).GetInt32(9001) != stage:
                raise AssertionError("Fixture authoring cleared the fault flag")
            accepted = c4d.CallButton(model,ids["MODEL_MATERIAL_CONVERT_TOON"])
            model = suite.model = suite.nodes(1056724)[0]
            diagnostic = str(model[ids["MODEL_MATERIAL_TOON_STATUS"]])
            observed = suite.doc.GetDataInstance().GetContainer(1068715).GetInt32(9002)
            receipt["last_observed_fault"] = observed
            after = signature(suite)
            if after != before:
                raise AssertionError("Conversion fault left persistent changes at stage "+str(stage))
            if observed != stage:
                raise AssertionError("Fault branch was not exercised: "+str((observed,stage,diagnostic)))
            if "Injected" not in diagnostic:
                raise AssertionError("Rollback erased the failure diagnostic: "+diagnostic)
            receipt["cases"].append({"stage":stage,"observed":observed,"state_restored":True,
                                     "diagnostic":diagnostic,"failure_diagnostic_retained":"Injected" in diagnostic})
        private_fault(model,0)
        # An actual ambiguous assignment is rejected before candidate insertion.
        mesh = model[ids["MODEL_MATERIAL_MESH_LINK"]]
        restriction = model[ids["MODEL_MATERIAL_SELECTION"]]
        selection = next(tag for tag in mesh.GetTags() if tag.CheckType(c4d.Tpolygonselection)
                         and tag.GetName()==restriction)
        duplicate = selection.GetClone(c4d.COPYFLAGS_NONE)
        mesh.InsertTag(duplicate)
        before = signature(suite)
        c4d.CallButton(model,ids["MODEL_MATERIAL_CONVERT_TOON"])
        if signature(suite) != before:
            raise AssertionError("Ambiguous polygon selection changed assignments")
        duplicate.Remove()
        receipt["ambiguous_selection_preserved"] = True
        # Simulate a host lacking required assets, including cached UI reads.
        private_fault(suite.doc,1)
        before = signature(suite)
        caps = suite.production_call("mmdtool_capabilities",{})
        if "redshift_toon" in caps["material_types"]:
            raise AssertionError("Unavailable host advertised Toon")
        handle = next(item["handle"] for item in caps["documents"] if item["active"])
        import contextlib,io,uuid
        from mmdtool_mcp.host import fixed_host_code
        namespace = {}
        with contextlib.redirect_stdout(io.StringIO()):
            exec(fixed_host_code("mmdtool_import_pmx",{"document":handle,"path":str(output/"toon-binding.pmx"),
                "material_type":"redshift_toon","materials":True},str(uuid.uuid4())),namespace)
        result = namespace["_result"]
        if result["success"] or signature(suite) != before:
            raise AssertionError("Unavailable host left a half-imported model")
        model[ids["MODEL_MATERIAL_CREATE_TYPE"]] = 4
        if "no required RS Toon assets" not in str(model[ids["MODEL_MATERIAL_TOON_STATUS"]]):
            # Conversion populates the user-visible reason even if a prior
            # failure diagnostic is still shown by the status callback.
            c4d.CallButton(model,ids["MODEL_MATERIAL_CONVERT_TOON"])
        if "no required RS Toon assets" not in str(model[ids["MODEL_MATERIAL_TOON_STATUS"]]):
            raise AssertionError("UI did not expose unavailable-host reason")
        receipt["unsupported_enabled_import"] = {"code":result["code"],"state_restored":True,"not_advertised":True}
        private_fault(suite.doc,0)
        disabled = []
        for multipart in (False,True):
            bypass = binding.production_suite(c4d,{"output":str(output),"fixtures":fixtures,"resource_ids":ids},
                material_type="redshift_toon",import_options={"materials":False,"multipart":multipart})
            try:
                bypass.new_document("Unavailable renderer with disabled materials")
                private_fault(bypass.doc,1)
                bypass.call("import_model",str(output/"toon-binding.pmx"))
                if bypass.doc.GetMaterials() or not bypass.nodes(1056724):
                    raise AssertionError("Disabled materials still required Toon capability")
                bypass.model = bypass.nodes(1056724)[0]
                bypass.reopen("unavailable-disabled-"+str(multipart))
                if bypass.doc.GetMaterials():
                    raise AssertionError("Disabled import created materials after reopen")
                disabled.append({"multipart":multipart,"unavailable":True,"model_imported":True,"save_reopen":True})
            finally:
                bypass.close()
        receipt["unsupported_disabled_import"] = disabled
        c4d.documents.SetActiveDocument(suite.doc)
        receipt["undo_redo_reopen"] = toon.conversion_roundtrip(suite,cycles=3)
        receipt["passed"] = True
        return receipt
    finally:
        suite.close()
        (output/"receipt.json").write_text(json.dumps(receipt,indent=2,default=str),encoding="utf8")


def run_contracts(c4d, output, shipping=True):
    import maxon
    import shader_binding_test as binding
    import native_toon_test as toon
    from c4d_runtime_regression import load_resource_ids,loaded_plugin_binary
    output = Path(output)
    output.mkdir(parents=True,exist_ok=True)
    fixtures = toon.prepare(output)
    manifest = {"output":str(output),"fixtures":fixtures,"resource_ids":load_resource_ids(Path(__file__).resolve().parents[2])}
    receipt = {"module":loaded_plugin_binary(),"shipping":shipping,"cases":[],"passed":False}

    def fresh(renderer,label):
        suite = binding.production_suite(c4d,manifest,material_type=renderer)
        suite.new_document(label)
        suite.call("import_model",str(output/"toon-binding.pmx"))
        suite.model = suite.nodes(1056724)[0]
        suite.evaluate(0)
        return suite

    try:
        suite = fresh("standard","Selection persistence")
        try:
            model,ids = suite.model,suite.ids
            model[ids["MODEL_MATERIAL_LIST"]] = 0
            description = {did[0].id:data for data,did,_ in model.GetDescription(c4d.DESCFLAGS_DESC_0)}
            cycle = description[ids["MODEL_MATERIAL_CREATE_TYPE"]].GetContainer(c4d.DESC_CYCLE)
            if set(key for key,_ in cycle) != {0,1,2,3,4}:
                raise AssertionError("Material choices were renumbered")
            for value in (0,1,2,3,4,99):
                model[ids["MODEL_MATERIAL_LIST"]] = 0
                if value == 99:
                    # Simulate an unknown serialized value. The native cycle
                    # widget cannot author values outside its advertised menu.
                    model.GetDataInstance().SetInt32(ids["MODEL_MATERIAL_CREATE_TYPE"],value)
                else:
                    model[ids["MODEL_MATERIAL_CREATE_TYPE"]] = value
                suite.reopen("material-choice-"+str(value))
                model = suite.model
                if model[ids["MODEL_MATERIAL_CREATE_TYPE"]] != value:
                    raise AssertionError("Saved material choice changed")
            model[ids["MODEL_MATERIAL_LIST"]] = 0
            before = signature(suite)
            c4d.CallButton(model,ids["MODEL_MATERIAL_CREATE_BUTTON"])
            if signature(suite) != before:
                raise AssertionError("Unknown type silently created another renderer")
            model[ids["MODEL_MATERIAL_CREATE_TYPE"]] = 4
            for mode,preview in ((ids["MODEL_MODE_ANIM"],False),(ids["MODEL_MODE_EDIT"],True)):
                model[ids["MODEL_MODE"]] = mode
                model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = preview
                before = signature(suite)
                c4d.CallButton(model,ids["MODEL_MATERIAL_CONVERT_TOON"])
                if signature(suite) != before:
                    raise AssertionError("Conversion ignored mode/preview gate")
            model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
            model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = False
            c4d.CallButton(model,ids["MODEL_MATERIAL_CREATE_BUTTON"])
            converted = model[ids["MODEL_MATERIAL_LINK"]]
            conversion = {"path":converted.GetDataInstance().GetContainer(1068715).GetString(172),
                          "roles":toon.binding_snapshot(suite)[0]["nodes"]}
            if shipping:
                private_fault(suite.doc,1)
                if "redshift_toon" not in suite.production_call("mmdtool_capabilities",{})["material_types"]:
                    raise AssertionError("Shipping build retained test fault control")
                private_fault(suite.doc,0)
            receipt["selection"] = {"legacy_values":list(range(4)),"new_value":4,"unknown_preserved":99,
                                    "mode_preview_gates":True,"create_uses_conversion":True}
        finally:
            suite.close()
        suite = fresh("redshift_toon","Production graph contracts")
        try:
            # Material ordering differs between creation and import. Compare
            # the plain entry directly, rather than assuming material order.
            suite.model[suite.ids["MODEL_MATERIAL_LIST"]] = 0
            imported = suite.model[suite.ids["MODEL_MATERIAL_LINK"]]
            if imported.GetDataInstance().GetContainer(1068715).GetString(172) != conversion["path"]:
                raise AssertionError("UI creation and import resolved different Toon paths")
            graph = imported.GetNodeMaterialReference().GetGraph(maxon.Id(toon.SPACE))
            roles = sorted(str(n.GetId()) for n in graph.GetRoot().GetChildren() if str(n.GetId()).startswith("cmt_"))
            if roles != conversion["roles"]:
                raise AssertionError("UI creation and production import recipes differ")
            before = signature(suite)
            suite.production_call("mmdtool_capabilities",{})
            if signature(suite) != before:
                raise AssertionError("Capability probe changed the document")
            receipt["entry_import_recipe_equal"] = True
            receipt["capability_document_unchanged"] = True
        finally:
            suite.close()
        for case,asset,removed in (("multiple-surfaces","toonmaterial",None),
                                   ("multiple-outputs",None,None),
                                   ("missing-port",None,None),
                                   ("missing-role",None,"cmt_sphere_matcap"),
                                   ("wrong-asset","rsramp","cmt_toon_contour")):
            suite = fresh("redshift_toon",case)
            try:
                model,ids = suite.model,suite.ids
                model[ids["MODEL_MATERIAL_LIST"]] = 0
                mat = model[ids["MODEL_MATERIAL_LINK"]]
                graph = mat.GetNodeMaterialReference().GetGraph(maxon.Id(toon.SPACE))
                root = graph.GetRoot()
                with graph.BeginTransaction() as transaction:
                    if case=="missing-port":
                        root.FindChild("cmt_toon_surface").GetInputs().FindChild(toon.PREFIX+"toonmaterial.base_color").Remove()
                    if removed:
                        root.FindChild(removed).Remove()
                    if asset or case=="multiple-outputs":
                        graph.AddChild(maxon.Id(removed or "artist_extra"),maxon.Id(toon.PREFIX+asset if asset else toon.OUTPUT))
                    transaction.Commit()
                reader = root.FindChild("cmt_morph_diffuse").GetInputs().FindChild(toon.PREFIX+"rsuserdatacolor.default")
                before = str(reader.GetPortValue())
                model[ids["MODEL_MATERIAL_DIFFUSE_COLOR"]] = c4d.Vector(.7,.6,.5)
                if str(reader.GetPortValue()) != before or not str(model[ids["MODEL_MATMORPH_STATUS"]]):
                    raise AssertionError("Invalid graph was driven: "+case)
                receipt["cases"].append({"case":case,"artist_state_preserved":True,"diagnostic":str(model[ids["MODEL_MATMORPH_STATUS"]])})
            finally:
                suite.close()
        receipt["materials_disabled"] = toon.material_disabled_import_roundtrip(c4d,manifest)
        receipt["passed"] = True
        return receipt
    finally:
        (output/"receipt.json").write_text(json.dumps(receipt,indent=2,default=str),encoding="utf8")
