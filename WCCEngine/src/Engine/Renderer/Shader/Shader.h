#pragma once
#include "string"
#include "../../Core/OpenGL/OpenGLObject.h"
#include "GLFW/glfw3.h"
#include "../../Core/Core.h"
#include "fwd.hpp"

namespace WCCEngine
{
	class WCC_API Shader : public OpenGLObject
	{
	public:
		Shader(IN const std::string& strVertexShaderSourceFilePath, 
				IN const std::string& strFragmentShaderSourceFilePath, const std::string& strShaderName);
		
		~Shader();

	public:
		virtual void Generate() override;
		virtual void Bind() const override;
		virtual void UnBind() const override;
		virtual void Destroy() override;

		void SetMatrix(IN const std::string& strName, IN const glm::mat4& oMatrix, OPTIONAL bool bBind = false);

		void SetVector3(IN const std::string& strName, IN const glm::vec3& oVector3, OPTIONAL bool bBind = false);
		void SetInteger(IN const std::string& strName, IN const int nInteger, OPTIONAL bool bBind = false);

	private:
		const bool Create(IN const std::string& strVertexShaderSourceFilePath, IN const std::string& strFragmentShaderSourceFilePath);

	private:
		std::string m_strShaderName;
	};
};
