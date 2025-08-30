#include "wccpch.h"
#include "ResourceManager.h"
#include "stb_image.cpp"


namespace WCCEngine
{
	ResourceManager* ResourceManager::m_pResourceManager = nullptr;
	std::mutex ResourceManager::m_oMutex;

	ResourceManager::ResourceManager()
	{
	}

	ResourceManager::~ResourceManager()
	{
		Clear();
	}

	constexpr ResourceManager& ResourceManager::GetResourceManagerInstance()
	{
		std::lock_guard<std::mutex> oLock(m_oMutex);
		if (m_pResourceManager == nullptr)
			m_pResourceManager = new ResourceManager();

		return *m_pResourceManager;
	}

	const Ref<Texture2D> ResourceManager::LoadTexture2D(IN const std::string& strResourceName, IN const std::string& strTexturePath)
	{
		int nWidth = 0;
		int nHeight = 0;
		int nChannels = 0;

		const PBYTE const pTextureData = stbi_load(strTexturePath.c_str(), &nWidth, &nHeight, &nChannels, 0);
		if (!pTextureData)
			WCC_CORE_ERROR(LOAD_TEXTURE_ERROR_MESSAGE, strTexturePath);

		Texture2D oTexture2D(nWidth, nHeight, pTextureData);
		Ref<Texture2D> pTexture2D = CreateRef<Texture2D>(oTexture2D);

		m_ResourcesMap[strResourceName] = pTexture2D;
		return pTexture2D;
	}

	void ResourceManager::Clear()
	{
		m_ResourcesMap.clear();
	}
}
