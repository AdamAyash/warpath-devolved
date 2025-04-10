#pragma once
#include "OpenGLObject.h"
#include "../Core.h"

namespace WCCEngine
{
	class VertexBuffer : public OpenGLObject
	{
	public:
		VertexBuffer();
		~VertexBuffer();

	public:
		virtual void Generate() override; 

		template<class DataType>
		void Pack(IN DataType& pData, IN const GLenum usage)
		{
			glBufferData(GL_ARRAY_BUFFER, sizeof(pData), pData, usage);
		}

		virtual void Bind() const override;
	};
}

