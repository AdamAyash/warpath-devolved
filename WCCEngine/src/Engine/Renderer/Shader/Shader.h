#pragma once
#include "string"
#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "../../Core/Core.h"

namespace WCCEngine
{
	class WCC_API Shader
	{
	public:
		Shader(IN const std::string& strVertexShaderSourceFilePath, IN const std::string& strFragmentShaderSourceFilePath);
		~Shader();

	public:
		void Bind();

	private:
		const bool Create(IN const std::string& strVertexShaderSourceFilePath, IN const std::string& strFragmentShaderSourceFilePath);

	private:
		GLuint m_nShaderProgramID;
	};
};
