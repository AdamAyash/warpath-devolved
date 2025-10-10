#include "wccpch.h"
#include "Renderer2D.h"
#include "glad/glad.h"
#include "../Core/OpenGL/VertexBuffer.h" 
#include <gtc/matrix_transform.hpp>
#include "../Core/Utilities.h"

#define TEXTURE_QUAD_VERTECES_SIZE 6
#define TEXTURE_VERTEX_BUFFER_SIZE 24
#define TEXTURE_VERTEX_BUFFER_LAYOUT_OFFSET 4
#define TEXTURE_CENTER_OFFSET 0.5f

#define LINE_VERTEX_BUFFER_SIZE 4
		
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

	void Renderer2D::RenderTexture(IN const Ref<Texture2D>& oTexture, IN const glm::vec2& oPosition, OPTIONAL const glm::vec2* oSize /*= nullptr*/, 
		OPTIONAL float fRotation /*= 0*/, OPTIONAL glm::vec3 oColor /* = glm::vec3(1.f)*/)
	{
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

	void Renderer2D::RenderLine(IN const glm::vec2& oStartPosition, IN const glm::vec2& oEndPosition
		, OPTIONAL float fLineThickness /*= 1.f*/
		, OPTIONAL glm::vec3 oColor /*= glm::vec3(1.f)*/)
	{
		const glm::vec2 oNormalizedStartPosition = Utilities::TransformPixelCoordinatesToNDC(oStartPosition, m_oWindowProperties.m_nWidth,
			m_oWindowProperties.m_nHeight);

		const glm::vec2 oNormalizedEndPosition = Utilities::TransformPixelCoordinatesToNDC(oEndPosition, m_oWindowProperties.m_nWidth,
			m_oWindowProperties.m_nHeight);

		float oVertices[] =
		{
			oNormalizedStartPosition.x, oNormalizedStartPosition.y,
			oNormalizedEndPosition.x, oNormalizedEndPosition.y,
		};

		m_oLine2DShader->Bind();
		m_oLine2DShader->SetVector3("oInputColor", oColor);

		auto oVertexArray = CreateScope<VertexArray>();
		oVertexArray->Bind();

		VertexBuffer oVertexBuffer;
		oVertexBuffer.Pack<float[4]>(oVertices, GL_STATIC_DRAW);
		oVertexBuffer.AddLayout(2 * sizeof(float), 2, GL_FLOAT, GL_FALSE);

		glLineWidth(fLineThickness);
		glDrawArrays(GL_LINES, 0, 2);
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

		VertexBuffer oVertexBuffer;
		oVertexBuffer.Pack<float[TEXTURE_VERTEX_BUFFER_SIZE]>(oVertices, GL_STATIC_DRAW);
		oVertexBuffer.AddLayout(TEXTURE_VERTEX_BUFFER_LAYOUT_OFFSET * sizeof(float));

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
