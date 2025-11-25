#pragma once
#include "../Core/Core.h"
#include "glm.hpp"
#include "../Platform/OpenGL/VertexArray.h"
#include "Texture2D.h"
#include "Shader/Shader.h"
#include "../Core/Application/Window.h"

namespace WCCEngine
{
	struct Vertex
	{
		Vertex()
			: oPosition(0)
			, oTextureCoordinates(0)
			, oColor(0)
		{
			WCCSecureZeroMemory;
		}

	public:
		glm::vec4 oPosition;
		glm::vec2 oTextureCoordinates;
		glm::vec4 oColor;
	};

	class Renderer2D final
	{
	public:
		Renderer2D(const WindowProperties& oWindowsProperties);
		~Renderer2D();

	public:
		void BeginBatch();
		void EndBatch();

		void Flush();
		void DrawQuad(IN const Ref<Texture2D> pTexture, IN const glm::vec2 oPosition);

	private:
		void Initialize();

		const glm::mat4 CreateModelMatrix(IN const glm::vec2& oPosition, IN const glm::vec2& oSize,
			IN const float fRotation);

		void ShutDown();

	private:
		static const long s_nMaxVertexCount = 50;

		int m_nMaxSupportedTextures;
		long m_lVerticesCount;
		long m_TrianglesCount;

		Vertex* m_pVertexDataBase;
		Vertex* m_pVertexDataCurrent;

		glm::vec2 m_oQuadVertexPositions[6];
		std::vector<Ref<Texture2D>> m_oTextureSlots;

		Ref<VertexBuffer> m_pVertexBuffer;
		Ref<VertexArray> m_pVertexArray;       
		Ref<Shader> m_oTexture2DShader;

		WindowProperties m_oWindowProperties;
	};
}