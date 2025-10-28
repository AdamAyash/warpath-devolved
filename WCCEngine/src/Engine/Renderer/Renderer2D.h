#pragma once
#include "../Core/Core.h"
#include "Texture2D.h"
#include "../Core/OpenGL/VertexArray.h"
#include "glm.hpp"
#include "Shader/Shader.h"
#include "../Core/Application/Window.h"

namespace WCCEngine
{
	class WCC_API Renderer2D
	{
	public:
		Renderer2D(IN const WindowProperties& oWindowProperties);
		~Renderer2D();

	public:
		void RenderTexture(IN const Ref<Texture2D>& oTexture, IN const glm::vec2& oPosition, OPTIONAL const glm::vec2 oSize = glm::vec2(),
			OPTIONAL float fRotation = 0.0f, OPTIONAL glm::vec3 oColor = glm::vec3(1.0f));

		void ClearBackgroundColor();
		void SetBackgroundColor(IN const glm::vec4& oBackgroundColor);

	private:
		const bool Initialize();

		const glm::mat4 CreateModelMatrix(IN const glm::vec2& oPosition, IN const glm::vec2& oSize,
			IN const float fRotation, IN const glm::vec3& oColor);

	private:
		const WindowProperties& m_oWindowProperties;
		Scope<VertexArray> m_pVertexArray;
		Ref<Shader> m_oTexture2DShader;
		Ref<Shader> m_oLine2DShader;
		glm::vec4 m_oBackgroundColor;
	};
}
