#include "wccpch.h"
#include "OpenGLObject.h"

namespace WCCEngine
{
	OpenGLObject::OpenGLObject()
		: m_nObjectID(INVALID_OBJECT_ID)
	{
	}

	OpenGLObject::~OpenGLObject()
	{
	}

	constexpr inline unsigned int OpenGLObject::GetObjectID() const
	{
		return m_nObjectID;
	}
}
