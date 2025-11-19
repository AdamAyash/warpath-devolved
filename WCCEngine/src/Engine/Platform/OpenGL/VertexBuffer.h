#pragma once
#include "OpenGLObject.h"
#include "../../Core/Core.h"
#include "OpenGLTypes.h"

#define FOUR_COMPONENT_SIZE 4

namespace WCCEngine
{
	class VertexBuffer : public OpenGLObject
	{
		class VertexBufferLayout NESTED_CLASS : public OpenGLObject
		{
		public:
			VertexBufferLayout(unsigned int nIndex, std::size_t nnStrideSize, int nComponentSize = FOUR_COMPONENT_SIZE,
				GLenum eComponentType = GL_FLOAT, GLboolean bNormalized = GL_FALSE, const void* pCurrentStideOffset = (void*)0);

			~VertexBufferLayout();

		public:
			virtual void Create() override;
			virtual void Bind() const override;
			virtual void UnBind() const override;
			virtual void Destroy() override;

		private:
			unsigned int m_nIndex;
			int m_nComponentSize;
			GLenum m_eComponentType;
			GLboolean m_bNormalized;
			std::size_t m_nnStrideSize;
			const void* m_pCurrentStideOffset;
		};

	public:
		VertexBuffer();
		~VertexBuffer();

	public:
		virtual void Create() override; 
		virtual void Bind() const override;
		virtual void UnBind() const override;
		virtual void Destroy() override;

		void AddLayout(IN const std::size_t nnStrideSize, OPTIONAL const  int nComponentSize = FOUR_COMPONENT_SIZE, OPTIONAL const GLenum eComponentType = GL_FLOAT,
			OPTIONAL const GLboolean bNormalized = GL_FALSE, const void* pCurrentStideOffset = (void*)0);

		template<class DataType>
		void Pack(IN DataType& pData, IN const OpenGLDrawTypes eDrawType)
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(pData), pData, static_cast<GLenum>(eDrawType));
		}

		void SetData(const void* pData, uint32_t nSize)
		{
			Bind();
			glBindBuffer(GL_ARRAY_BUFFER, m_nObjectID);
			glBufferSubData(GL_ARRAY_BUFFER, 0, nSize, pData);
		}

		void Allocate(IN const size_t nBufferSize, OPTIONAL const OpenGLDrawTypes eDrawType = OpenGLDrawTypes::DrawTypeDynamic)
		{
			glBufferData(GL_ARRAY_BUFFER, nBufferSize, nullptr, static_cast<GLenum>(eDrawType));
		}

	private:
		std::vector<Ref<VertexBufferLayout>> m_oVertexBufferLayoutArray;
		unsigned int m_nBufferLayoutCounter;
	};
}

