���k      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��ID:\C4D_MMD_Tool\sdk_r23\frameworks\geom.framework\source\maxon\celldata.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/apibase.h�hhh]��quote��"��template�Nubh()��}�(h�maxon/string.h�hhh]�h-h.h/Nubh()��}�(h�maxon/vector.h�hhh]�h-h.h/Nubh()��}�(h�maxon/range.h�hhh]�h-h.h/Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhK�hK	hKubh�ubhhh]�(h �Class���)��}�(hh�CellEdge�����}�(hKhh)��}�(hhhMehKhKubh�ubhh<h]�(h �Function���)��}�(h�constructor�hhGh]��
simpleName�hT�access��public��kind�hTh/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���static���explicit���deleted���retType��void��const���params�]��
observable�N�result�NubhQ)��}�(hhThhGh]�hVhThWhXhYhTh/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hghhhi�hj]�(h �	Parameter���)��}�(h�Int�hh�start�����}�(hKhh)��}�(hhhM�hKhKubh�ub�default�N�pack���input���output��ubhu)��}�(h�Int�hh�end�����}�(hKhh)��}�(hhhM�hKhKubh�ubhNh��h��h��ubhu)��}�(h�Int�hh�nextEdgeOfFace�����}�(hKhh)��}�(hhhM�hKhK#ubh�ubhNh��h��h��ubhu)��}�(h�Int�hh�prevEdgeOfFace�����}�(hKhh)��}�(hhhM�hKhK7ubh�ubhNh��h��h��ubhu)��}�(h�Int�hh�reverseEdge�����}�(hKhh)��}�(hhhM�hKhKKubh�ubhNh��h��h��ubehlNhmNubhQ)��}�(hh�ToString�����}�(hKhh)��}�(hhhM�hKhK	ubh�ubhhGh]�hVh�hWhXhY�function�h/NhZNhNh[Nh\Nh]K h^]�(h�./// Returns a readable string of the content.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�j/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�-/// @return												The converted result.
�����}�(hKhh)��}�(hhhMShKhKubh�ubeh`��/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
/// @return												The converted result.
�ha}�hc�hd�he�hf�hg�String�hi�hj]�hu)��}�(h�const FormatStatement*�hh�formatStatement�����}�(hKhh)��}�(hhhMhKhK)ubh�ubh�nullptr�h��h��h��ubahlNhmNubh �Variable���)��}�(hh�_start�����}�(hKhh)��}�(hhhM6hKhKubh�ubhhGh]�hVh�hWhXhY�variable�h/NhZNh�Int�h[Nh\Nh]K h^]�h`h	ha}�hc�hd�ubh�)��}�(hh�_end�����}�(hKhh)��}�(hhhMKhK hKubh�ubhhGh]�hVh�hWhXhYh�h/NhZNh�Int�h[Nh\Nh]K h^]�h`h	ha}�hc�hd�ubh�)��}�(hh�_nextEdgeOfFace�����}�(hKhh)��}�(hhhM^hK!hKubh�ubhhGh]�hVh�hWhXhYh�h/NhZNh�Int�h[Nh\Nh]K h^]�h`h	ha}�hc�hd�ubh�)��}�(hh�_prevEdgeOfFace�����}�(hKhh)��}�(hhhM|hK"hKubh�ubhhGh]�hVh�hWhXhYh�h/NhZNh�Int�h[Nh\Nh]K h^]�h`h	ha}�hc�hd�ubh�)��}�(hh�_reverseEdge�����}�(hKhh)��}�(hhhM�hK#hKubh�ubhhGh]�hVj	  hWhXhYh�h/NhZNh�Int�h[Nh\Nh]K h^]�h`h	ha}�hc�hd�ubehVhKhWhXhY�class�h/NhZNhNh[Nh\Nh]K h^]�(h�y/// CellEdge struct respresents an edge in the Voronoi Cell data. It saves indices to the start and endpoint of the edge
�����}�(hKhh)��}�(hhhMhKhKubh�ubh��/// as well as indices to other edges, that are somehow related to the current edge (reverse, next edge of face and next edge of vertex)
�����}�(hKhh)��}�(hhhMzhKhKubh�ubeh`X  /// CellEdge struct respresents an edge in the Voronoi Cell data. It saves indices to the start and endpoint of the edge
/// as well as indices to other edges, that are somehow related to the current edge (reverse, next edge of face and next edge of vertex)
�ha}�hc��bases�]��	interface�N�refKind�Nhd��refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubh�)��}�(hh�POINT_FUSE_EPS�����}�(hKhh)��}�(hhhM�hK&hKubh�ubhh<h]�hVj<  hWhXhYh�h/NhZNh�const Float�h[Nh\Nh]K h^]�h`h	ha}�hc�hd�ubhF)��}�(hh�CellData�����}�(hKhh)��}�(hhhM�hK+hKubh�ubhh<h]�(hQ)��}�(hhThjD  h]�hVhThWh�public�����}�(hKhh)��}�(hhhMhK.hKubh�ubhYhTh/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hghhhi�hj]�hlNhmNubhQ)��}�(hhThjD  h]�hVhThWjR  hYhTh/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hghhhi�hj]�hu)��}�(h�
CellData&&�hh�src�����}�(hKhh)��}�(hhhMqhK1hKubh�ubhNh��h��h��ubahlNhmNubhQ)��}�(hh�CopyFrom�����}�(hKhh)��}�(hhhMU
hK<hKubh�ubhjD  h]�hVjl  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�1/// Copies the contents of src into this object.
�����}�(hKhh)��}�(hhhM#	hK7hKubh�ubh�3/// @param[in] src								The object to copy from.
�����}�(hKhh)��}�(hhhMU	hK8hKubh�ubh�;/// @param[in] resizeFlags				Resize flag for collections.
�����}�(hKhh)��}�(hhhM�	hK9hKubh�ubh�&/// @return												OK on success.
�����}�(hKhh)��}�(hhhM�	hK:hKubh�ubeh`��/// Copies the contents of src into this object.
/// @param[in] src								The object to copy from.
/// @param[in] resizeFlags				Resize flag for collections.
/// @return												OK on success.
�ha}�hc�hd�he�hf�hg�Result<void>�hi�hj]�(hu)��}�(h�const CellData&�hh�src�����}�(hKhh)��}�(hhhMn
hK<hK(ubh�ubhNh��h��h��ubhu)��}�(h�COLLECTION_RESIZE_FLAGS�hh�resizeFlags�����}�(hKhh)��}�(hhhM�
hK<hKEubh�ubh�$COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE�h��h��h��ubehlNhm�void�ubhQ)��}�(hh�Reset�����}�(hKhh)��}�(hhhM�hKAhKubh�ubhjD  h]�hVj�  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�h�'/// Resets this cell to an empty cell.
�����}�(hKhh)��}�(hhhMhK?hKubh�ubah`�'/// Resets this cell to an empty cell.
�ha}�hc�hd�he�hf�hg�void�hi�hj]�hlNhmNubhQ)��}�(hh�Flush�����}�(hKhh)��}�(hhhM�hKFhKubh�ubhjD  h]�hVj�  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�h�6/// Resets this cell to an empty cell (keeps memory).
�����}�(hKhh)��}�(hhhMhKDhKubh�ubah`�6/// Resets this cell to an empty cell (keeps memory).
�ha}�hc�hd�he�hf�hg�void�hi�hj]�hlNhmNubhQ)��}�(hh�	ScaleCell�����}�(hKhh)��}�(hhhMhKMhKubh�ubhjD  h]�hVj�  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�1/// Scales the current cell by a specific value.
�����}�(hKhh)��}�(hhhMhKIhKubh�ubh�D/// @param[in] scaleValue					the amout the cell will be scaled by.
�����}�(hKhh)��}�(hhhM?hKJhKubh�ubh�0/// @return												if the scaling succeded.
�����}�(hKhh)��}�(hhhM�hKKhKubh�ubeh`��/// Scales the current cell by a specific value.
/// @param[in] scaleValue					the amout the cell will be scaled by.
/// @return												if the scaling succeded.
�ha}�hc�hd�he�hf�hg�Result<Bool>�hi�hj]�hu)��}�(h�Float�hh�
scaleValue�����}�(hKhh)��}�(hhhM.hKMhKubh�ubhNh��h��h��ubahlNhm�Bool�ubhQ)��}�(hh�FixGeometry�����}�(hKhh)��}�(hhhM�hKShKubh�ubhjD  h]�hVj�  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�G/// This cell checks the current cell data structure and optimizes it.
�����}�(hKhh)��}�(hhhM�hKPhKubh�ubh�G/// @return												true if everything worked out, otherwise false.
�����}�(hKhh)��}�(hhhM�hKQhKubh�ubeh`��/// This cell checks the current cell data structure and optimizes it.
/// @return												true if everything worked out, otherwise false.
�ha}�hc�hd�he�hf�hg�Result<Bool>�hi�hj]�hlNhm�Bool�ubhQ)��}�(hh�GetVertices�����}�(hKhh)��}�(hhhM�hKYhKubh�ubhjD  h]�hVj  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�2/// Gets the vertex list of this cell (writable).
�����}�(hKhh)��}�(hhhM�hKVhKubh�ubh�2/// @return												Reference to vertex array.
�����}�(hKhh)��}�(hhhM2hKWhKubh�ubeh`�d/// Gets the vertex list of this cell (writable).
/// @return												Reference to vertex array.
�ha}�hc�hd�he�hf�hg�BaseArray<Vector>&�hi�hj]�hlNhmNubhQ)��}�(hh�GetEdges�����}�(hKhh)��}�(hhhMhK_hKubh�ubhjD  h]�hVj-  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�0/// Gets the edge list of this cell (writable).
�����}�(hKhh)��}�(hhhMAhK\hKubh�ubh�0/// @return												Reference to edge array.
�����}�(hKhh)��}�(hhhMrhK]hKubh�ubeh`�`/// Gets the edge list of this cell (writable).
/// @return												Reference to edge array.
�ha}�hc�hd�he�hf�hg�BaseArray<CellEdge>&�hi�hj]�hlNhmNubhQ)��}�(hh�GetFaces�����}�(hKhh)��}�(hhhMLhKehKubh�ubhjD  h]�hVjG  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�0/// Gets the face list of this cell (writable).
�����}�(hKhh)��}�(hhhM~hKbhKubh�ubh�0/// @return												Reference to face array.
�����}�(hKhh)��}�(hhhM�hKchKubh�ubeh`�`/// Gets the face list of this cell (writable).
/// @return												Reference to face array.
�ha}�hc�hd�he�hf�hg�BaseArray<Int>&�hi�hj]�hlNhmNubhQ)��}�(hh�GetAdjacentCells�����}�(hKhh)��}�(hhhM�hKkhKubh�ubhjD  h]�hVja  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�9/// Gets the adjacent cell list of this cell (writable).
�����}�(hKhh)��}�(hhhM�hKhhKubh�ubh�=/// @return												Reference to the adjacent cell array.
�����}�(hKhh)��}�(hhhM�hKihKubh�ubeh`�v/// Gets the adjacent cell list of this cell (writable).
/// @return												Reference to the adjacent cell array.
�ha}�hc�hd�he�hf�hg�BaseArray<Int32>&�hi�hj]�hlNhmNubhQ)��}�(hh�GetVertices�����}�(hKhh)��}�(hhhM�hKqhKubh�ubhjD  h]�hVj{  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�6/// Gets the vertex list of this cell (not writable).
�����}�(hKhh)��}�(hhhMhKnhKubh�ubh�;/// @return												Constant reference to vertex array.
�����}�(hKhh)��}�(hhhMEhKohKubh�ubeh`�q/// Gets the vertex list of this cell (not writable).
/// @return												Constant reference to vertex array.
�ha}�hc�hd�he�hf�hg�const BaseArray<Vector>&�hi�hj]�hlNhmNubhQ)��}�(hh�GetEdges�����}�(hKhh)��}�(hhhMOhKwhKubh�ubhjD  h]�hVj�  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�4/// Gets the edge list of this cell (not writable).
�����}�(hKhh)��}�(hhhMihKthKubh�ubh�9/// @return												Constant reference to edge array.
�����}�(hKhh)��}�(hhhM�hKuhKubh�ubeh`�m/// Gets the edge list of this cell (not writable).
/// @return												Constant reference to edge array.
�ha}�hc�hd�he�hf�hg�const BaseArray<CellEdge>&�hi�hj]�hlNhmNubhQ)��}�(hh�GetFaces�����}�(hKhh)��}�(hhhM�hK}hKubh�ubhjD  h]�hVj�  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�4/// Gets the face list of this cell (not writable).
�����}�(hKhh)��}�(hhhM�hKzhKubh�ubh�9/// @return												Constant reference to face array.
�����}�(hKhh)��}�(hhhM�hK{hKubh�ubeh`�m/// Gets the face list of this cell (not writable).
/// @return												Constant reference to face array.
�ha}�hc�hd�he�hf�hg�const BaseArray<Int>&�hi�hj]�hlNhmNubhQ)��}�(hh�GetAdjacentCells�����}�(hKhh)��}�(hhhMhK�hKubh�ubhjD  h]�hVj�  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�=/// Gets the adjacent cell list of this cell (not writable).
�����}�(hKhh)��}�(hhhMhK�hKubh�ubh�B/// @return												Constant reference to adjacent cell array.
�����}�(hKhh)��}�(hhhMNhK�hKubh�ubeh`�/// Gets the adjacent cell list of this cell (not writable).
/// @return												Constant reference to adjacent cell array.
�ha}�hc�hd�he�hf�hg�const BaseArray<Int32>&�hi�hj]�hlNhmNubhQ)��}�(hh�	IsComplex�����}�(hKhh)��}�(hhhMMhK�hKubh�ubhjD  h]�hVj�  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�=/// Returns if this cell is complex (most likely not convex)
�����}�(hKhh)��}�(hhhM}hK�hKubh�ubh�0/// @return												Reference to face array.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubeh`�m/// Returns if this cell is complex (most likely not convex)
/// @return												Reference to face array.
�ha}�hc�hd�he�hf�hg�Bool�hi�hj]�hlNhmNubhQ)��}�(hh�TestPointWithCell�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhjD  h]�hVj�  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�3/// Tests if a passed point is inside of the cell.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�:/// @param[in] point							Point to test if it is inside.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�F/// @return												True if point is inside cell, otherwise false.
�����}�(hKhh)��}�(hhhM-hK�hKubh�ubeh`��/// Tests if a passed point is inside of the cell.
/// @param[in] point							Point to test if it is inside.
/// @return												True if point is inside cell, otherwise false.
�ha}�hc�hd�he�hf�hg�Bool�hi�hj]�hu)��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhM�hK�hK'ubh�ubhNh��h��h��ubahlNhmNubhQ)��}�(hh�
MergeCells�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhjD  h]�hVj&  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�'/// Merges another cell into this one.
�����}�(hKhh)��}�(hhhMahK�hKubh�ubh�N/// @param[in] thisCellFaces			The faces of this cell that should be removed.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�E/// @param[in] neighbourCell			The other cell to fuse into this one.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�G/// @param[in] otherCellFaces			The faces of the other cell to remove.
�����}�(hKhh)��}�(hhhMhK�hKubh�ubh�&/// @return												OK on success.
�����}�(hKhh)��}�(hhhMfhK�hKubh�ubeh`X'  /// Merges another cell into this one.
/// @param[in] thisCellFaces			The faces of this cell that should be removed.
/// @param[in] neighbourCell			The other cell to fuse into this one.
/// @param[in] otherCellFaces			The faces of the other cell to remove.
/// @return												OK on success.
�ha}�hc�hd�he�hf�hg�Result<void>�hi�hj]�(hu)��}�(h�const BaseArray<Int>&�hh�thisCellFaces�����}�(hKhh)��}�(hhhMhK�hK0ubh�ubhNh��h��h��ubhu)��}�(h�const CellData&�hh�neighbourCell�����}�(hKhh)��}�(hhhM6hK�hKOubh�ubhNh��h��h��ubhu)��}�(h�const BaseArray<Int>&�hh�otherCellFaces�����}�(hKhh)��}�(hhhM[hK�hKtubh�ubhNh��h��h��ubehlNhm�void�ubhQ)��}�(hh�	FuseCells�����}�(hKhh)��}�(hhhM�!hK�hKubh�ubhjD  h]�hVjn  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�c/// Fuses another cell into this one. The wall between the cells is removed if they are neighbors.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�@/// @param[in] thisCellIndex			The external index of this cell.
�����}�(hKhh)��}�(hhhM. hK�hKubh�ubh�G/// @param[in] neighbourCell			The neighbor cell that should be fused.
�����}�(hKhh)��}�(hhhMo hK�hKubh�ubh�I/// @param[in] otherCellIndex			The external index of the neighbor cell.
�����}�(hKhh)��}�(hhhM� hK�hKubh�ubh�&/// @return												OK on success.
�����}�(hKhh)��}�(hhhM!hK�hKubh�ubeh`XY  /// Fuses another cell into this one. The wall between the cells is removed if they are neighbors.
/// @param[in] thisCellIndex			The external index of this cell.
/// @param[in] neighbourCell			The neighbor cell that should be fused.
/// @param[in] otherCellIndex			The external index of the neighbor cell.
/// @return												OK on success.
�ha}�hc�hd�he�hf�hg�Result<void>�hi�hj]�(hu)��}�(h�Int�hh�thisCellIndex�����}�(hKhh)��}�(hhhM�!hK�hKubh�ubhNh��h��h��ubhu)��}�(h�	CellData&�hh�neighbourCell�����}�(hKhh)��}�(hhhM�!hK�hK6ubh�ubhNh��h��h��ubhu)��}�(h�Int�hh�otherCellIndex�����}�(hKhh)��}�(hhhM�!hK�hKIubh�ubhNh��h��h��ubehlNhm�void�ubhQ)��}�(hh�CreateCellFaceNormal�����}�(hKhh)��}�(hhhM[#hK�hK	ubh�ubhjD  h]�hVj�  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�;/// Calculates the Normal of a pointloop face of the cell.
�����}�(hKhh)��}�(hhhM;"hK�hKubh�ubh�P/// @param[in] faceIndex					The index of the cell to calculate the normal for.
�����}�(hKhh)��}�(hhhMw"hK�hKubh�ubh�//// @return												The normal of the face.
�����}�(hKhh)��}�(hhhM�"hK�hKubh�ubeh`��/// Calculates the Normal of a pointloop face of the cell.
/// @param[in] faceIndex					The index of the cell to calculate the normal for.
/// @return												The normal of the face.
�ha}�hc�hd�he�hf�hg�Vector�hi�hj]�hu)��}�(h�Int�hh�	faceIndex�����}�(hKhh)��}�(hhhMt#hK�hK"ubh�ubhNh��h��h��ubahlNhmNubhQ)��}�(hh�AddCellData�����}�(hKhh)��}�(hhhM%hK�hKubh�ubhjD  h]�hVj�  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�K/// Adds the data of a different cell to this one. Indices are translated.
�����}�(hKhh)��}�(hhhM�#hK�hKubh�ubh�G/// @param[in] otherCell					The other cell whose data should be added
�����}�(hKhh)��}�(hhhM0$hK�hKubh�ubh�&/// @return												OK on success.
�����}�(hKhh)��}�(hhhMx$hK�hKubh�ubeh`��/// Adds the data of a different cell to this one. Indices are translated.
/// @param[in] otherCell					The other cell whose data should be added
/// @return												OK on success.
�ha}�hc�hd�he�hf�hg�Result<void>�hi�hj]�hu)��}�(h�const CellData&�hh�	otherCell�����}�(hKhh)��}�(hhhM$%hK�hK+ubh�ubhNh��h��h��ubahlNhm�void�ubhQ)��}�(hh�GetBoundingBox�����}�(hKhh)��}�(hhhMt&hK�hKubh�ubhjD  h]�hVj	  hWjR  hYh�h/NhZNhNh[Nh\Nh]K h^]�(h�F/// Calculates and returns the Axis Aligned Bounding Box of the cell.
�����}�(hKhh)��}�(hhhM�%hK�hKubh�ubh�4/// @return												The Bounding Box of the cell
�����}�(hKhh)��}�(hhhM�%hK�hKubh�ubeh`�z/// Calculates and returns the Axis Aligned Bounding Box of the cell.
/// @return												The Bounding Box of the cell
�ha}�hc�hd�he�hf�hg�Range<Vector>�hi�hj]�hlNhmNubhQ)��}�(hh�MarkAllUsedPoints�����}�(hKhh)��}�(hhhM�&hK�hKubh�ubhjD  h]�hVj#  hWh�private�����}�(hKhh)��}�(hhhM�&hK�hKubh�ubhYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�void�hi�hj]�(hu)��}�(h�BaseArray<Int>&�hh�pointUseless�����}�(hKhh)��}�(hhhM�&hK�hK)ubh�ubhNh��h��h��ubhu)��}�(h�Int�hh�mark�����}�(hKhh)��}�(hhhM�&hK�hK;ubh�ubh�NOTOK�h��h��h��ubehlNhmNubhQ)��}�(hh�MarkAllDoublePoints�����}�(hKhh)��}�(hhhM�&hK�hKubh�ubhjD  h]�hVjI  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�void�hi�hj]�(hu)��}�(h�BaseArray<Int>&�hh�pointUseless�����}�(hKhh)��}�(hhhM	'hK�hK+ubh�ubhNh��h��h��ubhu)��}�(h�Bool&�hh�pointRemoved�����}�(hKhh)��}�(hhhM'hK�hK?ubh�ubhNh��h��h��ubhu)��}�(h�Float�hh�epsilonOverride�����}�(hKhh)��}�(hhhM1'hK�hKSubh�ubh�0.0�h��h��h��ubehlNhmNubhQ)��}�(hh�MarkAllColinearPoints�����}�(hKhh)��}�(hhhMW'hK�hKubh�ubhjD  h]�hVjr  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<Bool>�hi�hj]�(hu)��}�(h�BaseArray<Int>&�hh�pointUseless�����}�(hKhh)��}�(hhhM}'hK�hK5ubh�ubhNh��h��h��ubhu)��}�(h�Bool&�hh�pointRemoved�����}�(hKhh)��}�(hhhM�'hK�hKIubh�ubhNh��h��h��ubhu)��}�(h�Float�hh�epsilonOverride�����}�(hKhh)��}�(hhhM�'hK�hK]ubh�ubh�0.0�h��h��h��ubehlNhm�Bool�ubhQ)��}�(hh�MarkAllUselessPoints�����}�(hKhh)��}�(hhhM�'hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<Bool>�hi�hj]�(hu)��}�(h�BaseArray<Int>&�hh�pointUseless�����}�(hKhh)��}�(hhhM�'hK�hK4ubh�ubhNh��h��h��ubhu)��}�(h�Bool&�hh�pointRemoved�����}�(hKhh)��}�(hhhM(hK�hKHubh�ubhNh��h��h��ubehlNhm�Bool�ubhQ)��}�(hh� ReCreateCellWithOnlyUsefulPoints�����}�(hKhh)��}�(hhhM!(hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<Bool>�hi�hj]�hu)��}�(h�BaseArray<Int>&�hh�pointUseless�����}�(hKhh)��}�(hhhMR(hK�hK@ubh�ubhNh��h��h��ubahlNhm�Bool�ubhQ)��}�(hh�CalcAllFaceNormals�����}�(hKhh)��}�(hhhMo(hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<void>�hi�hj]�hu)��}�(h�BaseArray<Vector>&�hh�faceNormals�����}�(hKhh)��}�(hhhM�(hK�hK5ubh�ubhNh��h��h��ubahlNhm�void�ubhQ)��}�(hh�SetupReverseEdges�����}�(hKhh)��}�(hhhM�(hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Bool�hi�hj]�hlNhmNubhQ)��}�(hh�CleanupUnusedPoints�����}�(hKhh)��}�(hhhM�(hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<void>�hi�hj]�hlNhm�void�ubhQ)��}�(hh�TestCurrentDataStructure�����}�(hKhh)��}�(hhhM�(hK�hKubh�ubhjD  h]�hVj  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Bool�hi�hj]�hu)��}�(h�BaseArray<Char>&�hh�faceRemoved�����}�(hKhh)��}�(hhhM)hK�hK1ubh�ubhNh��h��h��ubahlNhmNubhQ)��}�(hh�ExpandCellByValue�����}�(hKhh)��}�(hhhM0)hK�hKubh�ubhjD  h]�hVj  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<void>�hi�hj]�(hu)��}�(h�const BaseArray<Vector>&�hh�planeNormals�����}�(hKhh)��}�(hhhM\)hK�hK;ubh�ubhNh��h��h��ubhu)��}�(h�const BaseArray<Int32>&�hh�edgeToFaceBelonging�����}�(hKhh)��}�(hhhM�)hK�hKaubh�ubhNh��h��h��ubhu)��}�(h�Float�hh�offset�����}�(hKhh)��}�(hhhM�)hK�hK|ubh�ubhNh��h��h��ubhu)��}�(h�BaseArray<Vector>&�hh�pointDisplacements�����}�(hKhh)��}�(hhhM�)hK�hK�ubh�ubhNh��h��h��ubehlNhm�void�ubhQ)��}�(hh�ShrinkCellByValue�����}�(hKhh)��}�(hhhM�)hK�hKubh�ubhjD  h]�hVjM  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<Bool>�hi�hj]�(hu)��}�(h�const BaseArray<Vector>&�hh�planeNormals�����}�(hKhh)��}�(hhhM*hK�hK;ubh�ubhNh��h��h��ubhu)��}�(h�Float�hh�offset�����}�(hKhh)��}�(hhhM*hK�hKOubh�ubhNh��h��h��ubehlNhm�Bool�ubhQ)��}�(hh�CutCellOnPlane�����}�(hKhh)��}�(hhhM2*hK�hKubh�ubhjD  h]�hVjm  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<Bool>�hi�hj]�(hu)��}�(h�const Pair<Vector, Vector>&�hh�plane�����}�(hKhh)��}�(hhhM]*hK�hK:ubh�ubhNh��h��h��ubhu)��}�(h�Int32�hh�planeNeighborIndex�����}�(hKhh)��}�(hhhMj*hK�hKGubh�ubh�NOTOK�h��h��h��ubehlNhm�Bool�ubhQ)��}�(hh�CutFaceOnPlane�����}�(hKhh)��}�(hhhM�*hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<Bool>�hi�hj]�(hu)��}�(h�Int�hh�	faceIndex�����}�(hKhh)��}�(hhhM�*hK�hK"ubh�ubhNh��h��h��ubhu)��}�(h�const Pair<Vector, Vector>&�hh�plane�����}�(hKhh)��}�(hhhM�*hK�hKIubh�ubhNh��h��h��ubhu)��}�(h�const BaseArray<Float>&�hh�pointToCutPlaneDistance�����}�(hKhh)��}�(hhhM�*hK�hKhubh�ubhNh��h��h��ubhu)��}�(h�const BaseArray<Int>&�hh�edgeIntesection�����}�(hKhh)��}�(hhhM+hK�hK�ubh�ubhNh��h��h��ubhu)��}�(h�const BaseArray<Int>&�hh�pointTranslateMap�����}�(hKhh)��}�(hhhMD+hK�hK�ubh�ubhNh��h��h��ubhu)��}�(h�BaseArray<CellEdge>&�hh�newEdges�����}�(hKhh)��}�(hhhMl+hK�hK�ubh�ubhNh��h��h��ubhu)��}�(h�BaseArray<CellEdge>&�hh�newFaceEdges�����}�(hKhh)��}�(hhhM�+hK�hMubh�ubhNh��h��h��ubehlNhm�Bool�ubhQ)��}�(hh�ProcessInsideFaceAndAddToEdges�����}�(hKhh)��}�(hhhM�+hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<Bool>�hi�hj]�(hu)��}�(h�const BaseArray<CellEdge>&�hh�newFaceEdges�����}�(hKhh)��}�(hhhM�+hK�hKIubh�ubhNh��h��h��ubhu)��}�(h�Int�hh�
pointCount�����}�(hKhh)��}�(hhhM�+hK�hK[ubh�ubhNh��h��h��ubhu)��}�(h�BaseArray<CellEdge>&�hh�newEdges�����}�(hKhh)��}�(hhhM,hK�hK|ubh�ubhNh��h��h��ubehlNhm�Bool�ubhQ)��}�(hh�IntersectEdgeOnPlane�����}�(hKhh)��}�(hhhM-,hK�hKubh�ubhjD  h]�hVj  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<Int>�hi�hj]�(hu)��}�(h�const Pair<Vector, Vector>&�hh�planeBaseArray�����}�(hKhh)��}�(hhhM^,hK�hK?ubh�ubhNh��h��h��ubhu)��}�(h�Int�hh�	edgeIndex�����}�(hKhh)��}�(hhhMr,hK�hKSubh�ubhNh��h��h��ubhu)��}�(h�BaseArray<Vector>&�hh�	newPoints�����}�(hKhh)��}�(hhhM�,hK�hKqubh�ubhNh��h��h��ubehlNhm�Int�ubhQ)��}�(hh�MergePointsInCutData�����}�(hKhh)��}�(hhhM�,hK�hKubh�ubhjD  h]�hVj-  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<void>�hi�hj]�(hu)��}�(h�BaseArray<Vector>&�hh�	newPoints�����}�(hKhh)��}�(hhhM�,hK�hK7ubh�ubhNh��h��h��ubhu)��}�(h�BaseArray<CellEdge>&�hh�newEdges�����}�(hKhh)��}�(hhhM�,hK�hKWubh�ubhNh��h��h��ubhu)��}�(h�BaseArray<Int>&�hh�newFaces�����}�(hKhh)��}�(hhhM-hK�hKqubh�ubhNh��h��h��ubhu)��}�(h�BaseArray<CellEdge>&�hh�newFaceEdges�����}�(hKhh)��}�(hhhM+-hK�hK�ubh�ubhNh��h��h��ubehlNhm�void�ubhQ)��}�(hh�RemoveIsolatedPoints�����}�(hKhh)��}�(hhhMH-hK�hKubh�ubhjD  h]�hVj_  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<void>�hi�hj]�hlNhm�void�ubhQ)��}�(hh�
FusePoints�����}�(hKhh)��}�(hhhMn-hK�hKubh�ubhjD  h]�hVjm  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<void>�hi�hj]�hu)��}�(h�BaseArray<Int>&�hh�affectedPoints�����}�(hKhh)��}�(hhhM�-hK�hK*ubh�ubhNh��h��h��ubahlNhm�void�ubhQ)��}�(hh�
RemoveFace�����}�(hKhh)��}�(hhhM�-hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�hd�he�hf�hg�Result<void>�hi�hj]�(hu)��}�(h�Int�hh�	faceIndex�����}�(hKhh)��}�(hhhM�-hK�hKubh�ubhNh��h��h��ubhu)��}�(h�BaseArray<Int>&�hh�affectedPoints�����}�(hKhh)��}�(hhhM�-hK�hK9ubh�ubhNh��h��h��ubehlNhm�void�ubh�)��}�(hh�_verticesPreIndex�����}�(hKhh)��}�(hhhM�-hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNh�BaseArray<Int>�h[Nh\Nh]K h^]�h`h	ha}�hc�hd�ubh�)��}�(hh�	_vertices�����}�(hKhh)��}�(hhhM.hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNh�BaseArray<Vector>�h[Nh\Nh]K h^]�h`h	ha}�hc�hd�ubh�)��}�(hh�_edges�����}�(hKhh)��}�(hhhM=.hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNh�BaseArray<CellEdge>�h[Nh\Nh]K h^]�h`h	ha}�hc�hd�ubh�)��}�(hh�_faces�����}�(hKhh)��}�(hhhMW.hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNh�BaseArray<Int>�h[Nh\Nh]K h^]�h`h	ha}�hc�hd�ubh�)��}�(hh�_adjacentCell�����}�(hKhh)��}�(hhhMr.hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNh�BaseArray<Int32>�h[Nh\Nh]K h^]�h`h	ha}�hc�hd�ubh�)��}�(hh�
_isComplex�����}�(hKhh)��}�(hhhM�.hK�hKubh�ubhjD  h]�hVj�  hWj*  hYh�h/NhZNh�Bool�h[Nh\Nh]K h^]�h`h	ha}�hc�hd�ubehVjH  hWhXhYj  h/NhZNhNh[Nh\Nh]K h^]�h�M/// CellData struct is a datacontainer that represents a single Voronoi Cell
�����}�(hKhh)��}�(hhhM<hK)hKubh�ubah`�M/// CellData struct is a datacontainer that represents a single Voronoi Cell
�ha}�hc�j!  ]�j#  Nj$  Nhd�j%  Nj&  Nj'  �j(  �j)  �j*  �j+  �j,  �j-  �j.  �j/  Nj0  �j1  �j2  ]�j4  ]�j6  }�ubehVh@hWhXhY�	namespace�h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc��preprocessorConditions�]��root�hh N�containsResourceId���registry���usings����minIndentation�K �maxIndentation�K �firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�.hK�hKubh�ububehVhhWhXhYj�  h/NhZNhNh[Nh\Nh]K h^]�h`h	ha}�hc�j�  ]�j�  hh ]�(hh)h0h4h8h<hGj8  jD  j  ej�  �j�  �j�  ���hxx1�N�hxx2�N�snippets�}�j�  K j   K j  �ub.