#pragma once
#include "OpenGLObject.h"
#include "../Core.h"

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
			virtual void Generate() override;
			virtual void Bind() const override;
			virtual void UnBind() const override;

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
		virtual void Generate() override; 
		virtual void Bind() const override;
		virtual void UnBind() const override;

		void AddLayout(std::size_t nnStrideSize, int nComponentSize = FOUR_COMPONENT_SIZE, GLenum eComponentType = GL_FLOAT,
			GLboolean bNormalized = GL_FALSE, const void* pCurrentStideOffset = (void*)0);

		template<class DataType>
		void Pack(IN DataType& pData, IN const GLenum usage)
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(pData), pData, usage);
		}

	private:
		std::vector<Ref<VertexBufferLayout>> m_oVertexBufferLayoutArray;
		unsigned int m_nBufferLayoutCounter;
	};
}

