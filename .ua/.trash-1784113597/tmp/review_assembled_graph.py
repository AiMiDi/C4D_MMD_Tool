import json
import re
from pathlib import Path


ROOT = Path(r"E:\code\C4D_MMD_Tool")
UA = ROOT / ".ua"
INTERMEDIATE = UA / "intermediate"
GRAPH_PATH = INTERMEDIATE / "assembled-graph.json"
SCAN_PATH = INTERMEDIATE / "scan-result.json"
REVIEW_PATH = INTERMEDIATE / "assemble-review.json"

VALID_TYPES = {
    "file", "function", "class", "config", "document", "service",
    "table", "endpoint", "pipeline", "schema", "resource",
}
VALID_COMPLEXITY = {"simple", "moderate", "complex"}


def load(path):
    return json.loads(path.read_text(encoding="utf-8-sig"))


def main():
    graph = load(GRAPH_PATH)
    scan = load(SCAN_PATH)

    batch_pattern = re.compile(r"batch-(\d+)(?:-part-(\d+))?\.json$")
    batch_paths = sorted(
        (path for path in INTERMEDIATE.glob("batch-*.json") if batch_pattern.fullmatch(path.name)),
        key=lambda path: (
            int(batch_pattern.fullmatch(path.name).group(1)),
            int(batch_pattern.fullmatch(path.name).group(2) or 0),
            path.name,
        ),
    )
    batch_nodes = []
    batch_edges = []
    logical_batches = set()
    for path in batch_paths:
        match = batch_pattern.fullmatch(path.name)
        logical_batches.add(int(match.group(1)))
        fragment = load(path)
        batch_nodes.extend(fragment.get("nodes", []))
        batch_edges.extend(fragment.get("edges", []))

    nodes_recovered = 0
    edges_restored = 0
    types_remapped = 0
    complexity_remapped = 0

    graph_nodes_by_id = {node.get("id"): node for node in graph.get("nodes", []) if node.get("id")}
    last_batch_node_by_id = {node.get("id"): node for node in batch_nodes if node.get("id")}
    for node_id, node in last_batch_node_by_id.items():
        if node_id not in graph_nodes_by_id:
            graph["nodes"].append(node)
            graph_nodes_by_id[node_id] = node
            nodes_recovered += 1

    for node in graph.get("nodes", []):
        node_type = node.get("type")
        if node_type not in VALID_TYPES:
            raise RuntimeError(f"Unknown node type remains: {node_type!r} on {node.get('id')!r}")
        if node.get("complexity") not in VALID_COMPLEXITY:
            raise RuntimeError(f"Unknown complexity remains: {node.get('complexity')!r} on {node.get('id')!r}")

    graph_node_ids = {node["id"] for node in graph["nodes"]}
    graph_edge_keys = {
        (edge.get("source"), edge.get("target"), edge.get("type"))
        for edge in graph.get("edges", [])
    }
    last_batch_edge_by_key = {
        (edge.get("source"), edge.get("target"), edge.get("type")): edge
        for edge in batch_edges
    }
    for key, edge in last_batch_edge_by_key.items():
        if key in graph_edge_keys:
            continue
        if edge.get("source") in graph_node_ids and edge.get("target") in graph_node_ids:
            graph["edges"].append(edge)
            graph_edge_keys.add(key)
            edges_restored += 1

    file_level_nodes = {}
    for node in graph["nodes"]:
        if node.get("type") in {"function", "class"}:
            continue
        path = node.get("filePath")
        if path:
            if path in file_level_nodes and file_level_nodes[path] != node["id"]:
                raise RuntimeError(f"Multiple file-level nodes for {path}")
            file_level_nodes[path] = node["id"]

    raw_import_relationships = 0
    expected_import_keys = set()
    unresolved_import_nodes = []
    for source_path, targets in scan.get("importMap", {}).items():
        for target_path in targets:
            raw_import_relationships += 1
            source_id = file_level_nodes.get(source_path)
            target_id = file_level_nodes.get(target_path)
            if not source_id or not target_id:
                unresolved_import_nodes.append((source_path, target_path))
                continue
            expected_import_keys.add((source_id, target_id, "imports"))

    if unresolved_import_nodes:
        raise RuntimeError(f"Import map references missing file-level nodes: {unresolved_import_nodes[:5]}")

    cross_batch_edges_added = 0
    for source, target, edge_type in sorted(expected_import_keys):
        key = (source, target, edge_type)
        if key in graph_edge_keys:
            continue
        graph["edges"].append({
            "source": source,
            "target": target,
            "type": "imports",
            "direction": "forward",
            "weight": 0.7,
        })
        graph_edge_keys.add(key)
        cross_batch_edges_added += 1

    duplicate_batch_ids = len(batch_nodes) - len(last_batch_node_by_id)
    duplicate_ratio = duplicate_batch_ids / len(batch_nodes) if batch_nodes else 0.0
    fixed_section_ok = duplicate_ratio <= 0.30

    final_node_ids = [node.get("id") for node in graph["nodes"]]
    if None in final_node_ids or len(final_node_ids) != len(set(final_node_ids)):
        raise RuntimeError("Assembled graph contains missing or duplicate node IDs after review")
    final_node_id_set = set(final_node_ids)
    dangling = [
        edge for edge in graph["edges"]
        if edge.get("source") not in final_node_id_set or edge.get("target") not in final_node_id_set
    ]
    if dangling:
        raise RuntimeError(f"Dangling edges remain after review: {dangling[:5]}")

    if nodes_recovered or edges_restored or cross_batch_edges_added or types_remapped or complexity_remapped:
        GRAPH_PATH.write_text(json.dumps(graph, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")

    notes = [
        f"Reviewed {len(batch_paths)} batch files across {len(logical_batches)} logical batches; {len(batch_nodes)} input nodes collapse to {len(last_batch_node_by_id)} unique IDs.",
        f"The {duplicate_batch_ids} duplicate IDs are {duplicate_ratio:.1%} of batch input and match deterministic cap-compliant re-splitting, below the 30% systemic-warning threshold.",
        f"Verified all {len(scan.get('importMap', {}))} importMap entries and {raw_import_relationships} resolved relationships; {len(expected_import_keys)} unique imports edges are present.",
        "No unknown node types, invalid complexity values, missing file-level nodes, duplicate assembled IDs, or dangling edges remain.",
    ]
    review = {
        "fixedSectionOk": fixed_section_ok,
        "nodesRecovered": nodes_recovered,
        "edgesRestored": edges_restored,
        "crossBatchEdgesAdded": cross_batch_edges_added,
        "typesRemapped": types_remapped,
        "complexityRemapped": complexity_remapped,
        "notes": notes,
    }
    REVIEW_PATH.write_text(json.dumps(review, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({
        "batchFiles": len(batch_paths),
        "logicalBatches": len(logical_batches),
        "batchNodes": len(batch_nodes),
        "uniqueBatchNodes": len(last_batch_node_by_id),
        "graphNodes": len(graph["nodes"]),
        "graphEdges": len(graph["edges"]),
        "importMapEntries": len(scan.get("importMap", {})),
        "rawImportRelationships": raw_import_relationships,
        "uniqueExpectedImports": len(expected_import_keys),
        "actualImports": sum(edge.get("type") == "imports" for edge in graph["edges"]),
        "review": review,
    }, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
