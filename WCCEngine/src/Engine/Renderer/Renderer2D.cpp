#include "wccpch.h"
#include "Renderer2D.h"
#include "glad/glad.h"
#include "../Core/OpenGL/VertexBuffer.h" 
#include <gtc/matrix_transform.hpp>

#define TEXTURE_QUAD_VERTECES_SIZE 6
#define TEXTURE_VERTEX_BUFFER_SIZE 24
#define TEXTURE_VERTEX_BUFFER_LAYOUT_OFFSET 4
#define TEXTURE_CENTER_OFFSET 0.5f

#define LINE_VERTEX_BUFFER_SIZE 4
		
namespace WCCEngine 
{
	Renderer2D::Renderer2D(IN const WindowProperties& oWindowProperties)
		: m_oWindowProperties(oWindowProperties)
	{
		Initialize();
	}

	Renderer2D::~Renderer2D()
	{
	}

	void Renderer2D::Render(IN const Ref<Texture2D>& oTexture, IN const glm::vec2& oPosition, OPTIONAL const glm::vec2* oSize /*= nullptr*/, 
		OPTIONAL float fRotation /*= 0*/, OPTIONAL glm::vec3 oColor /* = glm::vec3(1.f)*/)
	{
		ClearBackgroundColor();

		m_oTexture2DShader->Bind();

		const glm::vec2 oComputedSize = oSize != nullptr ? *oSize 
			: glm::vec2(oTexture->GetWidth(), oTexture->GetHeight());

		DoTransformations(oPosition, oComputedSize, fRotation, oColor);

		glActiveTexture(GL_TEXTURE0);
		oTexture->Bind();

		m_pVertexArray->Bind();
		glDrawArrays(GL_TRIANGLES, 0, TEXTURE_QUAD_VERTECES_SIZE);

		delete oSize;
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

		VertexBuffer oVertexBuffer;
		oVertexBuffer.Pack<float[TEXTURE_VERTEX_BUFFER_SIZE]>(oVertices, GL_STATIC_DRAW);
		oVertexBuffer.AddLayout(TEXTURE_VERTEX_BUFFER_LAYOUT_OFFSET * sizeof(float));

		m_oTexture2DShader = CreateRef<Shader>("assets/shaders/ExampleVertexShader.glsl"
			,"assets/shaders/ExampleFragmentShader.glsl"
			, "Default tetxure shader");

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
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer2D::DoTransformations(IN const glm::vec2& oPosition, const glm::vec2& oSize, IN float fRotation, IN glm::vec3& oColor)
	{
		glm::mat4 oModelMatrix = glm::mat4(1.0f);
		oModelMatrix = glm::translate(oModelMatrix, glm::vec3(oPosition, 0));

		oModelMatrix = glm::translate(oModelMatrix, glm::vec3(TEXTURE_CENTER_OFFSET * oSize.x, TEXTURE_CENTER_OFFSET * oSize.y, 0));
		oModelMatrix = glm::rotate(oModelMatrix, glm::radians(fRotation), glm::vec3(0, 0, 1.f));
		oModelMatrix = glm::translate(oModelMatrix, glm::vec3(-TEXTURE_CENTER_OFFSET * oSize.x, -TEXTURE_CENTER_OFFSET * oSize.y, 0));

		oModelMatrix = glm::scale(oModelMatrix, glm::vec3(oSize, 1.f));

		m_oTexture2DShader->SetMatrix("oModelMatrix", oModelMatrix);
		m_oTexture2DShader->SetVector3("oColor", oColor);
	}
}
