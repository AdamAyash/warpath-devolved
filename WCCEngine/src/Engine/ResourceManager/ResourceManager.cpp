#include "wccpch.h"
#include "ResourceManager.h"
#include "stb_image.cpp"


namespace WCCEngine
{
	ResourceManager* ResourceManager::m_pResourceManager = nullptr;

	ResourceManager::ResourceManager()
	{
	}

	ResourceManager::~ResourceManager()
	{
		Clear();
	}

	constexpr ResourceManager& ResourceManager::GetResourceManagerInstance()
	{
		if (m_pResourceManager == nullptr)
			m_pResourceManager = new ResourceManager();

		return *m_pResourceManager;
	}

	const Ref<Texture2D> ResourceManager::LoadTexture2D(IN const std::string& strResourceName, IN const std::string& strTexturePath)
	{
		int nWidth = 0;
		int nHeight = 0;
		int nChannels = 0;

		PBYTE pTextureData = stbi_load(strTexturePath.c_str(), &nWidth, &nHeight, &nChannels, 0);
		if (!pTextureData)
			WCC_CORE_ERROR("An error ocurred while trying to load texture at: {0}", strTexturePath);

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
