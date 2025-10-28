#include "wccpch.h"
#include "VertexArray.h"

namespace WCCEngine 
{
	VertexArray::VertexArray()
	{
		Generate();
		Bind();
	}

	VertexArray::~VertexArray()
	{
		Destroy();
	}

	void VertexArray::Generate()
	{
		glGenVertexArrays(1, &m_nObjectID);
	}

	void VertexArray::Bind() const
	{
		glBindVertexArray(m_nObjectID);
	}

	void VertexArray::UnBind() const
	{
		glBindVertexArray(0);
	}

	void VertexArray::Destroy()
	{
		glDeleteVertexArrays(1, &m_nObjectID);
		m_oVertexBufferArray.clear();
	}

	void VertexArray::AddVertexBuffer(Ref<VertexBuffer> pVertrexBuffer)
	{
		m_oVertexBufferArray.push_back(pVertrexBuffer);
	}
}