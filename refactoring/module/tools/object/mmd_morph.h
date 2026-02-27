#pragma once

#include <c4d.h>
#include "module/core/cmt_marco.h"

class MMDModelManagerObject;

enum class MMDMorphType : uint8_t
{
	DEFAULT = 0,
	GROUP = 1,
	FLIP = 1 << 1,
	MESH = 1 << 2,
	BONE = 1 << 3
};

class IMorph
{
protected:
	String m_name;
	DescID m_strength_id;
public:
	explicit IMorph(String name = {}, DescID strength_id = {});
	IMorph(const IMorph&) = delete;
	IMorph(IMorph&& other) noexcept;
	virtual ~IMorph() = default;

	IMorph& operator=(const IMorph&) = delete;
	IMorph& operator=(IMorph&& other) noexcept = default;
 
	[[nodiscard]] const String& GetName() const { return m_name; }
	Float GetStrength(SDK2024_Const GeListNode* node) const;
	Bool SetStrength(GeListNode* node, const Float& strength) const;
	DescID GetStrengthDescID();
	bool operator==(const IMorph& other) const;
	virtual MMDMorphType GetType() const = 0;
	virtual void AddMorphUI(MMDModelManagerObject& model, Int morph_id) = 0;
	virtual void DeleteMorphUI(MMDModelManagerObject& model) = 0;
	void RenameMorph(const String& name);
	virtual void UpdateMorph(MMDModelManagerObject& model) = 0;
	virtual void AddSubMorph(MMDModelManagerObject* model, Int id, Float weight) {}
	virtual void AddSubMorphNoCheck(Int id, Float weight) {}
	virtual void DeleteSubMorph(const Int id) {}
	virtual void RenameSubMorph(const Int old_id, const Int new_id) {}
	virtual maxon::HashMap<Int, Float>* GetSubMorphDataWritable() { return nullptr; }
	virtual Bool Read(HyperFile* hf);
	virtual Bool Write(HyperFile* hf) SDK2024_Const;
	virtual Bool CopyTo(IMorph* dest) const;
};

class GroupMorph final : public IMorph
{
	DescID m_grp_id;
	DescID m_button_grp_id;
	DescID m_button_editor_id;
	DescID m_button_delete_id;
	DescID m_button_rename_id;

	maxon::HashMap<Int, Float> m_data;
public:
	~GroupMorph() override = default;
	GroupMorph(const GroupMorph&) = delete;
	explicit GroupMorph(String name = {},
	                    DescID grp_id = {},
	                    DescID strength_id = {},
	                    DescID button_grp_id = {},
	                    DescID button_editor_id = {},
	                    DescID button_delete_id = {},
	                    DescID button_rename_id = {});
	GroupMorph(GroupMorph&& other) noexcept;

	GroupMorph& operator=(const GroupMorph&) = delete;
	GroupMorph& operator=(GroupMorph&& other) noexcept = default;

	void UpdateMorph(MMDModelManagerObject& model) override;
	void AddMorphUI(MMDModelManagerObject& model, Int morph_id) override;
	void DeleteMorphUI(MMDModelManagerObject& model) override;
	void AddSubMorph(MMDModelManagerObject* model, Int id, Float weight) override;
	void AddSubMorphNoCheck(Int id, Float weight) override;
	void DeleteSubMorph(const Int id) override { m_data.Erase(id); }
	void RenameSubMorph(const Int old_id, const Int new_id) override;
	Bool Read(HyperFile* hf) override;
	Bool Write(HyperFile* hf) SDK2024_Const override;
	Bool CopyTo(IMorph* dest) const override;
	maxon::HashMap<Int, Float>* GetSubMorphDataWritable() override { return &m_data; }
	MMDMorphType GetType() const override { return MMDMorphType::GROUP; }
};

class FlipMorph final : public IMorph
{
	DescID m_grp_id;
	DescID m_button_grp_id;
	DescID m_button_editor_id;
	DescID m_button_delete_id;
	DescID m_button_rename_id;
	maxon::HashMap<Int, Float> m_data;
public:
	~FlipMorph() override = default;
	FlipMorph(const FlipMorph&) = delete;
	explicit FlipMorph(String name = {},
	                   DescID strength_id = {},
	                   DescID grp_id = {},
	                   DescID button_grp_id = {},
	                   DescID button_editor_id = {},
	                   DescID button_delete_id = {},
	                   DescID button_rename_id = {});
	FlipMorph(FlipMorph&& other) noexcept;

	FlipMorph& operator=(const FlipMorph&) = delete;
	FlipMorph& operator=(FlipMorph&& other) noexcept = default;

	void UpdateMorph(MMDModelManagerObject& model) override;
	void AddMorphUI(MMDModelManagerObject& model, Int morph_id) override;
	void DeleteMorphUI(MMDModelManagerObject& model) override;
	void AddSubMorph(MMDModelManagerObject* model, Int id, Float weight) override;
	void AddSubMorphNoCheck(Int id, Float weight) override;
	void DeleteSubMorph(const Int id) override { m_data.Erase(id); }
	void RenameSubMorph(const Int old_id, const Int new_id) override;
	Bool Read(HyperFile* hf) override;
	Bool Write(HyperFile* hf) SDK2024_Const override;
	Bool CopyTo(IMorph* dest) const override;
	maxon::HashMap<Int, Float>* GetSubMorphDataWritable() override { return &m_data; }
	MMDMorphType GetType() const override { return MMDMorphType::FLIP; }
};

class MeshMorph final : public IMorph
{
public:
	explicit MeshMorph(String name = {}, DescID strength_id = {});
	MeshMorph(const MeshMorph&) = delete;
	MeshMorph(MeshMorph&& other) noexcept;
	~MeshMorph() override = default;

	MeshMorph& operator=(const MeshMorph&) = delete;
	MeshMorph& operator=(MeshMorph&& other) noexcept = default;

	void UpdateMorph(MMDModelManagerObject& model) override;
	void AddMorphUI(MMDModelManagerObject& model, Int morph_id) override;
	void DeleteMorphUI(MMDModelManagerObject& model) override;
	MMDMorphType GetType() const override { return MMDMorphType::MESH; }
};

class BoneMorph final : public IMorph
{
public:
	explicit BoneMorph(String name = {}, DescID strength_id = {});
	BoneMorph(const BoneMorph&) = delete;
	BoneMorph(BoneMorph&& other) noexcept;
	~BoneMorph() override = default;

	BoneMorph& operator=(const BoneMorph&) = delete;
	BoneMorph& operator=(BoneMorph&& other) noexcept = default;

	void UpdateMorph(MMDModelManagerObject& model) override;
	void AddMorphUI(MMDModelManagerObject& model, Int morph_id) override;
	void DeleteMorphUI(MMDModelManagerObject& model) override;
	MMDMorphType GetType() const override { return MMDMorphType::BONE; }
};
