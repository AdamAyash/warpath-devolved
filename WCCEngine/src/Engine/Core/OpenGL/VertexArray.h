#pragma once
#include <vector>
#include "OpenGLObject.h"
#include "VertexBuffer.h"

namespace WCCEngine
{
	class WCC_API VertexArray : public OpenGLObject
	{
	public:
		VertexArray();
		~VertexArray();

	public:
		virtual void Generate() override;
		virtual void Bind() const override;
		virtual void UnBind() const override;

		void AddVertexBuffer(Ref<VertexBuffer> pVertrexBuffer);

	private:
		std::vector<Ref<VertexBuffer>> m_oVertexBufferArray;
	};
}
