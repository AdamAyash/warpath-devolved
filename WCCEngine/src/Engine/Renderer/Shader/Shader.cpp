#include "wccpch.h"
#include "Shader.h"
#include "../../FileSystem/FileSystem.h"
#include "../../Core/Timer.h"
#include "glm.hpp"
#include <gtc/type_ptr.hpp>


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

	Shader::~Shader()
	{
		glDeleteProgram(m_nObjectID);
	}

	void Shader::Generate()
	{
	}

	void Shader::Bind() const
	{
		glUseProgram(m_nObjectID);
	}

	void Shader::SetMatrix(IN const std::string& strName, IN const glm::mat4& oMatrix, OPTIONAL bool bBind /*= false*/)
	{
		if (bBind)
			Bind();

		glUniformMatrix4fv(glGetUniformLocation(m_nObjectID, strName.c_str()), 1, false, glm::value_ptr(oMatrix));
	}

	void Shader::SetVector3(IN const std::string& strName, IN const glm::vec3& oVector3, OPTIONAL bool bBind /*= false*/)
	{
		if (bBind)
			Bind();

		glUniform3f(glGetUniformLocation(this->m_nObjectID, strName.c_str()), oVector3.x, oVector3.y, oVector3.z);
	}

	void Shader::SetInteger(IN const std::string& strName, IN const int nInteger, OPTIONAL bool bBind /*= false*/)
	{
		if (bBind)
			Bind();
		glUniform1i(glGetUniformLocation(this->m_nObjectID, strName.c_str()), nInteger);
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
			glGetShaderInfoLog(nFragmentShaderProgram, SHADER_COMPILATION_INFO_BUFFER_SIZE, NULL, shaderCompilationInfoBuffer);
			WCC_CORE_ERROR(shaderCompilationInfoBuffer);
			return false;
		}

		m_nObjectID = glCreateProgram();
		glAttachShader(m_nObjectID, nVertexShaderProgram);
		glAttachShader(m_nObjectID, nFragmentShaderProgram);
		glLinkProgram(m_nObjectID);

		glGetProgramiv(m_nObjectID, GL_LINK_STATUS, &bIsSuccessful);
		if (!bIsSuccessful)
		{
			glGetProgramInfoLog(m_nObjectID, SHADER_COMPILATION_INFO_BUFFER_SIZE, NULL, shaderCompilationInfoBuffer);
			WCC_CORE_ERROR(shaderCompilationInfoBuffer);
			return false;
		}

		glDeleteShader(nVertexShaderProgram);
		glDeleteShader(nFragmentShaderProgram);

		return true;
	}
};
