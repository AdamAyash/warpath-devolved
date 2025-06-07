#pragma once
#include "map"
#include <string>
#include "../Core/Core.h"
#include "../Core/OpenGL/OpenGLObject.h"
#include "../Renderer/Texture2D.h"

namespace WCCEngine
{
	class WCC_API ResourceManager final
	{
	private:
		ResourceManager();

	public:
		~ResourceManager();

	public:
		ResourceManager(IN ResourceManager& otherResourceManager) = delete;

	public:
		void operator = (const ResourceManager&) = delete;

	public:
		constexpr static ResourceManager& GetResourceManagerInstance();
		const Ref<Texture2D> LoadTexture2D(IN const std::string& strResourceName, IN const std::string& strTexturePath);

		template<typename ResourceType>
		constexpr bool LoadResource(IN const std::string& strResourceName, IN ResourceType& oResourceType)
		{
			WCC_ASSERT(dynamic_cast<OpenGLObject*>(&oResourceType) != nullptr)
			m_ResourcesMap[strResourceName] = CreateRef<ResourceType>(oResourceType);

			return true;
		}

		template<typename ResourceType>
		constexpr Ref<ResourceType> GetResource(IN const std::string& strResourceName)
		{
			return std::dynamic_pointer_cast<ResourceType>(m_ResourcesMap[strResourceName]);
		}

	private:
		void Clear();

	private:
		std::map <std::string, Ref<OpenGLObject>> m_ResourcesMap;
		static ResourceManager* m_pResourceManager;
		static std::mutex m_oMutex;
	};
}
