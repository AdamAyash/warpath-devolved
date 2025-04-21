#include "wccpch.h"
#include "VertexBuffer.h"

#define BUFFER_LAYOUT_COUNTER_DEFAULT_VALUE 0

namespace WCCEngine
{
	VertexBuffer::VertexBufferLayout::VertexBufferLayout(unsigned int nIndex, std::size_t nnStrideSize, int nComponentSize /*= FOUR_COMPONENT_SIZE*/,
		GLenum eComponentType/* = GL_FLOAT*/, GLboolean bNormalized /*= GL_FALSE*/, const void* pCurrentStideOffset /*= (void*)0*/)
		: m_nIndex(nIndex)
		, m_nnStrideSize(nnStrideSize)
		, m_nComponentSize(nComponentSize)
		, m_eComponentType(eComponentType)
		, m_bNormalized(bNormalized)
		, m_pCurrentStideOffset(pCurrentStideOffset)
	{
		Generate();
	}

	VertexBuffer::VertexBufferLayout::~VertexBufferLayout()
	{
	}

	void VertexBuffer::VertexBufferLayout::Bind() const
	{
	}

	void VertexBuffer::VertexBufferLayout::Generate()
	{
		glVertexAttribPointer(m_nIndex, m_nComponentSize, m_eComponentType, m_bNormalized, m_nnStrideSize, m_pCurrentStideOffset);
		glEnableVertexAttribArray(m_nIndex);
	}

	VertexBuffer::VertexBuffer()
		: m_nBufferLayoutCounter(BUFFER_LAYOUT_COUNTER_DEFAULT_VALUE)
	{
		Generate();
		Bind();
	}

	VertexBuffer::~VertexBuffer()
	{
		m_oVertexBufferLayoutArray.clear();
	}

	void VertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_nObjectID);
	}

	void VertexBuffer::Generate()
	{
		glGenBuffers(1, &m_nObjectID);
	}

	void VertexBuffer::AddLayout(std::size_t nnStrideSize, int nComponentSize /*= FOUR_COMPONENT_SIZE*/, GLenum eComponentType /*= GL_FLOAT*/, GLboolean bNormalized /*= GL_FALSE*/, const void* pCurrentStideOffset /*= (void*)0*/)
	{
		const auto oBufferLayout = CreateRef<VertexBufferLayout>(m_nBufferLayoutCounter++, nnStrideSize, nComponentSize, eComponentType, bNormalized, pCurrentStideOffset);
		m_oVertexBufferLayoutArray.push_back(oBufferLayout);
	}
}