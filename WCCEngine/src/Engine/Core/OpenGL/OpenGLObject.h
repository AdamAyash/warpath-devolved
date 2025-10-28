#pragma once
#include "../Core.h"
#include <glad/glad.h>

#define INVALID_OBJECT_ID -1

namespace WCCEngine
{
	class OpenGLObject
	{
	protected:
		OpenGLObject();
		virtual ~OpenGLObject();

	public:
		constexpr inline unsigned int GetObjectID() const;

		virtual void Generate() PURE;
		virtual void Bind() const PURE;
		virtual void UnBind() const PURE;
		virtual void Destroy()	PURE; 

	protected:
		unsigned int m_nObjectID;
	};
}
