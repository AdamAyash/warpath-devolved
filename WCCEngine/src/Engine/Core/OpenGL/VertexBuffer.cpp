#include "wccpch.h"
#include "VertexBuffer.h"
#include "glad/glad.h"

namespace WCCEngine
{
	VertexBuffer::VertexBuffer()
	{
		Generate();
	}

	VertexBuffer::~VertexBuffer()
	{
	}

	void VertexBuffer::Generate()
	{
		glGenBuffers(1, &m_nObjectID);

	}

	void VertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_nObjectID);
	}
}