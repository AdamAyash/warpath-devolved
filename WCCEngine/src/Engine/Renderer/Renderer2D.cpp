#include "wccpch.h"
#include "Renderer2D.h"
#include <ext/matrix_transform.hpp>
#include <ext/matrix_clip_space.hpp>

namespace WCCEngine
{
	Renderer2D::Renderer2D(const WindowProperties& oWindowsProperties)
		: m_pVertexDataBase(nullptr)
		, m_pVertexDataCurrent(nullptr)
		, m_lVerticesCount(0)
		, m_TrianglesCount(0)
		, m_nMaxSupportedTextures(0)
		, m_oWindowProperties(oWindowsProperties)
	{
		Initialize();
	}

	Renderer2D::~Renderer2D()
	{
	}

	void Renderer2D::BeginBatch()
	{
		m_lVerticesCount = 0;
		m_TrianglesCount = 0;
		m_pVertexDataCurrent = m_pVertexDataBase;
	}

	void Renderer2D::EndBatch()
	{
		Flush();
	}

	void Renderer2D::Flush()
	{
		m_oTexture2DShader->Bind();
		
		const uint32_t nDataSize = (uint32_t)((uint8_t*)m_pVertexDataCurrent - (uint8_t*)m_pVertexDataBase);

		m_pVertexBuffer->SetData(m_pVertexDataBase, nDataSize);
		glDrawArrays(GL_TRIANGLES, 0, m_lVerticesCount);
	}

	void Renderer2D::ShutDown()
	{
		delete[] m_pVertexDataBase;
	}

	void Renderer2D::DrawQuad(IN const Ref<Texture2D> pTexture, IN const glm::vec2 oPosition)
	{
		WCC_ASSERT(m_pVertexDataCurrent);

		if (m_lVerticesCount >= s_nMaxVertexCount)
		{
			Flush();
			BeginBatch();
		}

		constexpr glm::vec2 oTextureCoordinates[] = 
		{ 
			{ 0.0f, 1.0f }, 
			{ 1.0f, 0.0f }, 
			{ 0.0f, 0.0f },
			{ 0.0f, 1.0f }, 
			{ 1.0f, 1.0f }, 
			{ 1.0f, 0.0f }
		};
		 
		const glm::vec2 oSize = glm::vec2(32, 32);

		const auto oModelMatrix = CreateModelMatrix(oPosition, oSize, 0);

		const auto nQuadVertexCount = 6;

		for (auto nIndex = 0; nIndex < nQuadVertexCount; ++nIndex)
		{
			m_pVertexDataCurrent->oPosition = oModelMatrix * glm::vec4(m_oQuadVertexPositions[nIndex], 0, 1);
			m_pVertexDataCurrent->oTextureCoordinates = oTextureCoordinates[nIndex];
			m_pVertexDataCurrent++;
		}

		m_lVerticesCount += nQuadVertexCount;
	}

	void Renderer2D::Initialize()
	{
		WCC_ASSERT(!m_pVertexDataBase);

		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

		m_pVertexDataBase = new Vertex[s_nMaxVertexCount];

		m_pVertexArray = CreateRef<VertexArray>();
		m_pVertexBuffer = CreateRef<VertexBuffer>();

		m_pVertexArray->AddVertexBuffer(m_pVertexBuffer);

		m_pVertexBuffer->Allocate(s_nMaxVertexCount * sizeof(Vertex)); // TODO Should it be template like sizeof(Vertex) to get from template
		m_pVertexBuffer->AddLayout(sizeof(Vertex), 2, GL_FLOAT, GL_FALSE, (const void*)offsetof(Vertex, oPosition));
		m_pVertexBuffer->AddLayout(sizeof(Vertex), 2, GL_FLOAT, GL_FALSE, (const void*)offsetof(Vertex, oTextureCoordinates));

		m_oQuadVertexPositions[0] = { 0.0f, 1.0f };
		m_oQuadVertexPositions[1] = { 1.0f, 0.0f };
		m_oQuadVertexPositions[2] = { 0.0f, 0.0f };
		m_oQuadVertexPositions[3] = { 0.0f, 1.0f };
		m_oQuadVertexPositions[4] = { 1.0f, 1.0f };
		m_oQuadVertexPositions[5] = { 1.0f, 0.0f };

		glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &m_nMaxSupportedTextures);

		glm::mat4 oProjectionMatrix = glm::ortho(0.0f, static_cast<float>(m_oWindowProperties.m_nWidth),
			static_cast<float>(m_oWindowProperties.m_nHeight), 0.0f, -1.0f, 1.0f);

		m_oTexture2DShader = CreateRef<Shader>("assets/shaders/ExampleVertexShader.glsl"
			, "assets/shaders/ExampleFragmentShader.glsl"
			, "Default texture shader");

		m_oTexture2DShader->SetMatrix("oProjectionMaxtrix", oProjectionMatrix, true);

		WCC_CORE_INFO("Renderer was initialized successfully.");
	}

	const glm::mat4 Renderer2D::CreateModelMatrix(IN const glm::vec2& oPosition, IN const glm::vec2& oSize, IN const float fRotation)
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