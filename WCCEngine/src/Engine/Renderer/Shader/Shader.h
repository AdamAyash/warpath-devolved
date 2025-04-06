#pragma once
#include "string"
#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include "../../Core/Core.h"
#include "../../Core/OpenGL/OpenGLObject.h"

namespace WCCEngine
{
	class WCC_API Shader : public OpenGLObject
	{
	public:
		Shader(IN const std::string& strVertexShaderSourceFilePath, IN const std::string& strFragmentShaderSourceFilePath);
		~Shader();

	public:
		virtual void Generate() override;
		virtual void Bind() const override;

	private:
		const bool Create(IN const std::string& strVertexShaderSourceFilePath, IN const std::string& strFragmentShaderSourceFilePath);

	private:
	};
};
