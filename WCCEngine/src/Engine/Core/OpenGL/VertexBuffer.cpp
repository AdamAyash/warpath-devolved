#include "wccpch.h"
#include "VertexBuffer.h"

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