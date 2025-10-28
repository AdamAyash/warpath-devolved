#include "wccpch.h"
#include "Renderer2D.h"
#include "glad/glad.h"
#include "../Core/OpenGL/VertexBuffer.h" 
#include <gtc/matrix_transform.hpp>
#include "../Common/Utilities.h"

namespace WCCEngine
{
	Renderer2D::Renderer2D(IN const WindowProperties& oWindowProperties)
		: m_oWindowProperties(oWindowProperties)
		, m_oBackgroundColor(0)
	{
		Initialize();
	}

	Renderer2D::~Renderer2D()
	{
	}

	void Renderer2D::RenderTexture(IN const Ref<Texture2D>& oTexture, IN const glm::vec2& oPosition, OPTIONAL const glm::vec2 oSize /*= vec2()*/, 
		OPTIONAL float fRotation /*= 0*/, OPTIONAL glm::vec3 oColor /* = glm::vec3(1.f)*/)
	{
		auto oModelMatrix = CreateModelMatrix(oPosition, oSize, fRotation, oColor);

		m_oTexture2DShader->Bind();
		m_oTexture2DShader->SetMatrix("oModelMatrix", oModelMatrix);
		m_oTexture2DShader->SetVector3("oColor", oColor);

		glActiveTexture(GL_TEXTURE0);
		oTexture->Bind();

		m_pVertexArray->Bind();

		const auto nTextureQuadVertecesCount = 6;
		glDrawArrays(GL_TRIANGLES, 0, nTextureQuadVertecesCount);
	}

	void Renderer2D::SetBackgroundColor(IN const glm::vec4& oBackgroundColor)
	{
		m_oBackgroundColor = oBackgroundColor;
	}

	const bool Renderer2D::Initialize()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

		float oVertices[] = 
		{
			// pos      // tex
			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,

			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f
		};

		m_pVertexArray = CreateScope<VertexArray>();

		const auto nTextureVertexBufferSize = 24;
		const auto nTextureVertexBufferLayoutOffset = 4;

		VertexBuffer oVertexBuffer;
		oVertexBuffer.Pack<float[nTextureVertexBufferSize]>(oVertices, GL_STATIC_DRAW);
		oVertexBuffer.AddLayout(nTextureVertexBufferLayoutOffset * sizeof(float));

		m_oLine2DShader = CreateRef<Shader>("assets/shaders/ExampleLineVertexShader.glsl"
			, "assets/shaders/ExampleLineFragmentShader.glsl"
			, "Default line shader");

		m_oTexture2DShader = CreateRef<Shader>("assets/shaders/ExampleVertexShader.glsl"
			,"assets/shaders/ExampleFragmentShader.glsl"
			, "Default texture shader");

		m_oTexture2DShader->Bind();

		glm::mat4 oProjectionMatrix = glm::ortho(0.0f, static_cast<float>(m_oWindowProperties.m_nWidth),
			static_cast<float>(m_oWindowProperties.m_nHeight), 0.0f, -1.0f, 1.0f);

		m_oTexture2DShader->SetMatrix("oProjectionMatrix", oProjectionMatrix);
		m_oTexture2DShader->SetInteger("oTexture0", 0);

		WCC_CORE_INFO("Renderer initialized successfully.");
		return true;
	}

	void Renderer2D::ClearBackgroundColor()
	{
		glClearColor(m_oBackgroundColor.x, m_oBackgroundColor.y, m_oBackgroundColor.z, m_oBackgroundColor.w);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	const glm::mat4 Renderer2D::CreateModelMatrix(IN const glm::vec2& oPosition, IN const glm::vec2& oSize,
		IN const float fRotation, IN const glm::vec3& oColor)
	{
		const auto fTextureCenterOffset = 0.5f;

		glm::mat4 oModelMatrix = glm::mat4(1.0f);
		oModelMatrix = glm::translate(oModelMatrix, glm::vec3(oPosition, 0));
		oModelMatrix = glm::translate(oModelMatrix, glm::vec3(fTextureCenterOffset * oSize.x, fTextureCenterOffset * oSize.y, 0));
		oModelMatrix = glm::rotate(oModelMatrix, glm::radians(fRotation), glm::vec3(0, 0, 1.f));
		oModelMatrix = glm::translate(oModelMatrix, glm::vec3(-fTextureCenterOffset * oSize.x, -fTextureCenterOffset * oSize.y, 0));
		oModelMatrix = glm::scale(oModelMatrix, glm::vec3(oSize, 1.f));

		return oModelMatrix;
	}
}
