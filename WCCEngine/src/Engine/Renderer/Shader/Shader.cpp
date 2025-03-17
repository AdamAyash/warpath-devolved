#include "wccpch.h"
#include "Shader.h"
#include "../../FileSystem/FileSystem.h"
#include "../../Core/Timer.h"

#define SHADER_COMPILATION_INFO_BUFFER_SIZE 512

namespace WCCEngine
{
	Shader::Shader(IN const std::string& strVertexShaderSourceFilePath, IN const std::string& strFragmentShaderSourceFilePath)
	{
		Timer oTimer;
		if (!Create(strVertexShaderSourceFilePath, strFragmentShaderSourceFilePath))
		{
			WCC_CORE_ERROR("Shader creation failed.");
		}

		WCC_CORE_WARN("Shader creation took: {0} ms.", oTimer.ElapsedMilliseconds());
	}

	void Shader::Bind()
	{
		glUseProgram(m_nShaderProgramID);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_nShaderProgramID);
	}

	const bool Shader::Create(IN const std::string& strVertexShaderSourceFilePath, IN const std::string& strFragmentShaderSourceFilePath)
	{
		const std::string strVertexShaderSource = FileSystem::ReadFileContents(strVertexShaderSourceFilePath);
		const char* const pVertexShaderSource = strVertexShaderSource.c_str();

		if (!pVertexShaderSource)
		{
			WCC_ASSERT(pVertexShaderSource)
			return false;
		}

		const std::string strFragmentShaderSource = FileSystem::ReadFileContents(strFragmentShaderSourceFilePath);
		const char* const pFragmentShaderSource = strFragmentShaderSource.c_str();

		if (!pFragmentShaderSource)
		{
			WCC_ASSERT(pFragmentShaderSource)
			return false;
		}

		BOOL bIsSuccessful;
		char shaderCompilationInfoBuffer[SHADER_COMPILATION_INFO_BUFFER_SIZE];

		const GLuint nVertexShaderProgram = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(nVertexShaderProgram, 1, &pVertexShaderSource, NULL);
		glCompileShader(nVertexShaderProgram);

		glGetShaderiv(nVertexShaderProgram, GL_COMPILE_STATUS, &bIsSuccessful);
		if (!bIsSuccessful)
		{
			glGetShaderInfoLog(nVertexShaderProgram, SHADER_COMPILATION_INFO_BUFFER_SIZE, NULL, shaderCompilationInfoBuffer);
			WCC_CORE_ERROR(shaderCompilationInfoBuffer);
			return false;
		}

		const GLuint nFragmentShaderProgram = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(nFragmentShaderProgram, 1, &pFragmentShaderSource, NULL);
		glCompileShader(nFragmentShaderProgram);

		glGetShaderiv(nFragmentShaderProgram, GL_COMPILE_STATUS, &bIsSuccessful);
		if (!bIsSuccessful)
		{
			glGetShaderInfoLog(nFragmentShaderProgram, 512, NULL, shaderCompilationInfoBuffer);
			WCC_CORE_ERROR(shaderCompilationInfoBuffer);
			return false;
		}

		m_nShaderProgramID = glCreateProgram();
		glAttachShader(m_nShaderProgramID, nVertexShaderProgram);
		glAttachShader(m_nShaderProgramID, nFragmentShaderProgram);
		glLinkProgram(m_nShaderProgramID);

		glGetProgramiv(m_nShaderProgramID, GL_LINK_STATUS, &bIsSuccessful);
		if (!bIsSuccessful)
		{
			glGetProgramInfoLog(m_nShaderProgramID, 512, NULL, shaderCompilationInfoBuffer);
			WCC_CORE_ERROR(shaderCompilationInfoBuffer);
			return false;
		}

		glDeleteShader(nVertexShaderProgram);
		glDeleteShader(nFragmentShaderProgram);

		return true;
	}
};
