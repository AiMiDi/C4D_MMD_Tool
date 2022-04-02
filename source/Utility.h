#ifndef __MMD_UTILITY_H__
#define __MMD_UTILITY_H__

#include "main.h"

typedef maxon::Vec2<Float32> Vector2d32;
namespace utility {
	struct LocalData : public maxon::ParallelFor::BreakContext
	{
		maxon::Int localCount = 0;
	};

	/* Converts Euler rotation to quaternion rotation. */
	extern maxon::Vector4d32 EulerToQuaternion(const maxon::Vector& euler);
	/* Converts quaternion rotation to Euler rotation. */
	extern maxon::Vector QuaternionToEuler(const maxon::Vector4d32& quaternion);
	/*  Converts "SHIFT_JIS" to "UTF-8". */
	extern Bool SJIStoUTF8(char* strin, String& strout, Int64 char_length = -1);
	/*  Converts "UTF-8" to "SHIFT_JIS". */
	extern Bool UTF8toSJIS(const String& strin, char* strout);


	extern maxon::Result<void> SelectSuffixImportFile(Filename& fn, BaseFile* file, const String& suffix);
	

	class RenameDialog : public GeDialog
	{
		Bool CreateLayout() override;
		Bool Command(Int32 id, const BaseContainer& msg) override;
	public:
		String Rename;
		RenameDialog() {}
		~RenameDialog() {}
	};
}
namespace tool {
	enum class DescType
	{
		REAL_STRENGTH,
		BUTTON_EDITOR,
		BUTTON_DELETE,
		BUTTON_RENAME
	};
}
namespace mmd {
	extern Bool ReadPMXText(BaseFile* const file, const Char& text_encoding, String& out_string);
	extern Int32 ReadPMXIndex(BaseFile* const file, const Char& index_size);
	extern UInt32 ReadPMXUIndex(BaseFile* const file, const Char& index_size);
	/* MMD style interpolator. */
	class VMDInterpolator
	{
	private:
		UChar m_ax, m_ay, m_bx, m_by;
		Bool m_isLinear;
	public:
		/* Partial types of interpolator data */
		enum class PartType { ax, ay, bx, by };
		/* Constructor function */
		VMDInterpolator(UChar ax = 20U, UChar ay = 20U, UChar bx = 107U, UChar by = 107U) : m_ax(ax), m_ay(ay), m_bx(bx), m_by(by)
		{
			m_isLinear = m_ax == m_ay && m_bx == m_by;
		}
		VMDInterpolator(const VMDInterpolator& other) noexcept
		{
			m_ax = other.m_ax;
			m_ay = other.m_ay;
			m_bx = other.m_bx;
			m_by = other.m_by;
			m_isLinear = other.m_isLinear;
		}
		VMDInterpolator(VMDInterpolator&& other) noexcept
		{
			m_ax = std::move(other.m_ax);
			m_ay = std::move(other.m_ay);
			m_bx = std::move(other.m_bx);
			m_by = std::move(other.m_by);
			m_isLinear = std::move(other.m_isLinear);
		}
		VMDInterpolator& operator=(const VMDInterpolator& other) noexcept
		{
			m_ax = other.m_ax;
			m_ay = other.m_ay;
			m_bx = other.m_bx;
			m_by = other.m_by;
			m_isLinear = other.m_isLinear;
			return *this;
		}
		VMDInterpolator& operator=(VMDInterpolator&& other) noexcept
		{
			if (this != &other) {
				m_ax = std::move(other.m_ax);
				m_ay = std::move(other.m_ay);
				m_bx = std::move(other.m_bx);
				m_by = std::move(other.m_by);
				m_isLinear = std::move(other.m_isLinear);
			}
			return *this;
		}
		Bool IsLinear() const
		{
			return m_isLinear;
		}
		/* Sets the value of the interpolator. If the parameter is empty, set the default value. */
		void SetValue(UChar ax = 20U, UChar ay = 20U, UChar bx = 107U, UChar by = 107U)
		{
			this->m_ax = ax;
			this->m_ay = ay;
			this->m_bx = bx;
			this->m_by = by;
			m_isLinear = m_ax == m_ay && m_bx == m_by;
		}
		/* Gets the interpolator value. */
		UChar GetValue(const PartType& part) const
		{
			switch (part)
			{
			case (PartType::ax):
			{
				return this->m_ax;
			}
			case (PartType::bx):
			{
				return this->m_bx;
			}
			case (PartType::ay):
			{
				return this->m_ay;
			}
			case (PartType::by):
			{
				return this->m_by;
			}
			default:
				return UChar(-1);
			}
		}
		/* Hash function */
		maxon::HashInt GetHashCode() const
		{
			return  MAXON_HASHCODE(this->m_ax, this->m_ay, this->m_bx, this->m_by);
		}
		/* Read bone interpolator information from a file */
		Bool ReadBoneInterpolator(BaseFile* const file)
		{
			if (!file->ReadUChar(&this->m_ax))
				return false;
			file->Seek(3);
			if (!file->ReadUChar(&this->m_ay))
				return false;
			file->Seek(3);
			if (!file->ReadUChar(&this->m_bx))
				return false;
			file->Seek(3);
			if (!file->ReadUChar(&this->m_by))
				return false;
			file->Seek(3);
			m_isLinear = m_ax == m_ay && m_bx == m_by;
			return true;
		}
		/* Read the camera interpolator information from the file. */
		Bool ReadCameraInterpolator(BaseFile* const file)
		{
			UInt32 tmp = 0;
			if (!file->ReadUInt32(&tmp))
				return false;
			this->m_ax = UChar(((tmp & 0xFF) ^ 0x80) - 0x80);
			this->m_bx = UChar((((tmp & 0xFF00) >> 8) ^ 0x80) - 0x80);
			this->m_ay = UChar((((tmp & 0xFF0000) >> 16) ^ 0x80) - 0x80);
			this->m_by = UChar((((tmp & 0xFF000000) >> 24) ^ 0x80) - 0x80);
			m_isLinear = m_ax == m_ay && m_bx == m_by;
			return true;
		}
		/* Write the bone interpolator information to the file. */
		Bool WriteBoneInterpolator(BaseFile* const file) const
		{
			if (!file->WriteUChar(this->m_ax))
				return false;
			if (!file->WriteUChar(this->m_ax))
				return false;
			if (!file->WriteUChar(this->m_ax))
				return false;
			if (!file->WriteUChar(this->m_ax))
				return false;
			if (!file->WriteUChar(this->m_ay))
				return false;
			if (!file->WriteUChar(this->m_ay))
				return false;
			if (!file->WriteUChar(this->m_ay))
				return false;
			if (!file->WriteUChar(this->m_ay))
				return false;
			if (!file->WriteUChar(this->m_bx))
				return false;
			if (!file->WriteUChar(this->m_bx))
				return false;
			if (!file->WriteUChar(this->m_bx))
				return false;
			if (!file->WriteUChar(this->m_bx))
				return false;
			if (!file->WriteUChar(this->m_by))
				return false;
			if (!file->WriteUChar(this->m_by))
				return false;
			if (!file->WriteUChar(this->m_by))
				return false;
			if (!file->WriteUChar(this->m_by))
				return false;
			return true;
		}
		/* Write the camera interpolator information to the file. */
		Bool WriteCameraInterpolator(BaseFile* const file) const
		{
			if (!file->WriteUChar(this->m_ax))
				return false;
			if (!file->WriteUChar(this->m_bx))
				return false;
			if (!file->WriteUChar(this->m_ay))
				return false;
			if (!file->WriteUChar(this->m_by))
				return false;
			return true;
		}
	};
	/* Non collision group mask(2 bytes) */
	struct PMXRigidBodyNonCollisionGroup
	{
		Bool	G1 : 1;
		Bool	G2 : 1;
		Bool	G3 : 1;
		Bool	G4 : 1;
		Bool	G5 : 1;
		Bool	G6 : 1;
		Bool	G7 : 1;
		Bool	G8 : 1;
		Bool	G9 : 1;
		Bool	G10 : 1;
		Bool	G11 : 1;
		Bool	G12 : 1;
		Bool	G13 : 1;
		Bool	G14 : 1;
		Bool	G15 : 1;
		Bool	G16 : 1;

		PMXRigidBodyNonCollisionGroup(
			Bool G1_ = 0,
			Bool G2_ = 0,
			Bool G3_ = 0,
			Bool G4_ = 0,
			Bool G5_ = 0,
			Bool G6_ = 0,
			Bool G7_ = 0,
			Bool G8_ = 0,
			Bool G9_ = 0,
			Bool G10_ = 0,
			Bool G11_ = 0,
			Bool G12_ = 0,
			Bool G13_ = 0,
			Bool G14_ = 0,
			Bool G15_ = 0,
			Bool G16_ = 0)
		{
			this->G1 = G1_;
			this->G2 = G2_;
			this->G3 = G3_;
			this->G4 = G4_;
			this->G5 = G5_;
			this->G6 = G6_;
			this->G7 = G7_;
			this->G8 = G8_;
			this->G9 = G9_;
			this->G10 = G10_;
			this->G11 = G11_;
			this->G12 = G12_;
			this->G13 = G13_;
			this->G14 = G14_;
			this->G15 = G15_;
			this->G16 = G16_;
		}
	};
}
#endif //__MMD_UTILITY_H__