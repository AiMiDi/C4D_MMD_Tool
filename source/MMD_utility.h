#ifndef __MMD_UTILITY_H__
#define __MMD_UTILITY_H__

#include "main.h"

namespace mmd {
	/* Converts Euler rotation to quaternion rotation. */
	extern maxon::Vector4d32 EulerToQuaternion(const maxon::Vector& euler);
	/* Converts quaternion rotation to Euler rotation. */
	extern maxon::Vector QuaternionToEuler(const maxon::Vector4d32& quaternion);
	/*  Converts "SHIFT_JIS" to "UTF-8". */
	extern Bool SJIStoUTF8(char* strin, String& strout, Int64 char_length = -1);
	/*  Converts "UTF-8" to "SHIFT_JIS". */
	extern Bool UTF8toSJIS(const String& strin, char* strout);

	extern Bool ReadPMXText(BaseFile* const file, const Char& text_encoding, String& out_string);
	extern Int32 ReadPMXIndex(BaseFile* const file, const Char& index_size);
	extern UInt32 ReadPMXUIndex(BaseFile* const file, const Char& index_size);
	extern maxon::Result<void> SelectSuffixImportFile(Filename& fn, BaseFile* file, const String& suffix);
	typedef maxon::Vec2<Float32> Vector2d32;

	struct LocalData : public maxon::ParallelFor::BreakContext
	{
		maxon::Int localCount = 0;
	};

	/* MMD style interpolator. */
	class VMDInterpolator
	{
	private:
		UChar ax, ay, bx, by;
	public:
		/* Partial types of interpolator data */
		enum class PartType { ax, ay, bx, by };
		/* Constructor function */
		VMDInterpolator(UChar ax_ = 20U, UChar ay_ = 20U, UChar bx_ = 107U, UChar by_ = 107U) : ax(ax_), ay(ay_), bx(bx_), by(by_) {}
		/* Sets the value of the interpolator. If the parameter is empty, set the default value. */
		void SetValue(UChar ax_ = 20U, UChar ay_ = 20U, UChar bx_ = 107U, UChar by_ = 107U)
		{
			this->ax = ax_;
			this->ay = ay_;
			this->bx = bx_;
			this->by = by_;
		}
		/* Gets the interpolator value. */
		UChar GetValue(const PartType& part) const
		{
			switch (part)
			{
			case (PartType::ax):
			{
				return this->ax;
			}
			case (PartType::bx):
			{
				return this->bx;
			}
			case (PartType::ay):
			{
				return this->ay;
			}
			case (PartType::by):
			{
				return this->by;
			}
			default:
				return UChar(-1);
			}
		}
		/* Hash function */
		maxon::HashInt GetHashCode() const
		{
			return  MAXON_HASHCODE(this->ax, this->ay, this->bx, this->by);
		}
		/* Read bone interpolator information from a file */
		Bool ReadBoneInterpolator(BaseFile* const file)
		{
			if (!file->ReadUChar(&this->ax))
				return false;
			file->Seek(3);
			if (!file->ReadUChar(&this->ay))
				return false;
			file->Seek(3);
			if (!file->ReadUChar(&this->bx))
				return false;
			file->Seek(3);
			if (!file->ReadUChar(&this->by))
				return false;
			file->Seek(3);
			return true;
		}
		/* Read the camera interpolator information from the file. */
		Bool ReadCameraInterpolator(BaseFile* const file)
		{
			UInt32 tmp = 0;
			if (!file->ReadUInt32(&tmp))
				return false;
			this->ax = UChar(((tmp & 0xFF) ^ 0x80) - 0x80);
			this->bx = UChar((((tmp & 0xFF00) >> 8) ^ 0x80) - 0x80);
			this->ay = UChar((((tmp & 0xFF0000) >> 16) ^ 0x80) - 0x80);
			this->by = UChar((((tmp & 0xFF000000) >> 24) ^ 0x80) - 0x80);
			return true;
		}
		/* Write the bone interpolator information to the file. */
		Bool WriteBoneInterpolator(BaseFile* const file) const
		{
			if (!file->WriteUChar(this->ax))
				return false;
			if (!file->WriteUChar(this->ax))
				return false;
			if (!file->WriteUChar(this->ax))
				return false;
			if (!file->WriteUChar(this->ax))
				return false;
			if (!file->WriteUChar(this->ay))
				return false;
			if (!file->WriteUChar(this->ay))
				return false;
			if (!file->WriteUChar(this->ay))
				return false;
			if (!file->WriteUChar(this->ay))
				return false;
			if (!file->WriteUChar(this->bx))
				return false;
			if (!file->WriteUChar(this->bx))
				return false;
			if (!file->WriteUChar(this->bx))
				return false;
			if (!file->WriteUChar(this->bx))
				return false;
			if (!file->WriteUChar(this->by))
				return false;
			if (!file->WriteUChar(this->by))
				return false;
			if (!file->WriteUChar(this->by))
				return false;
			if (!file->WriteUChar(this->by))
				return false;
			return true;
		}
		/* Write the camera interpolator information to the file. */
		Bool WriteCameraInterpolator(BaseFile* const file) const
		{
			if (!file->WriteUChar(this->ax))
				return false;
			if (!file->WriteUChar(this->bx))
				return false;
			if (!file->WriteUChar(this->ay))
				return false;
			if (!file->WriteUChar(this->by))
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