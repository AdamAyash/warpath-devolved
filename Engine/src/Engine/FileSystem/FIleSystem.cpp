#include "wccpch.h"
#include "FileSystem.h"
#include "../Core/Core.h"

namespace WCCEngine
{
	const std::string FileSystem:: ReadFileContents(const std::string& strFilePath)
	{
		std::string strFileContents;
		std::ifstream oInputStream(strFilePath, std::ios::in | std::ios::binary); // ifstream closes itself due to RAII
		if (oInputStream)
		{
			oInputStream.seekg(0, std::ios::end);
			const size_t nnFileSize = oInputStream.tellg();
			if (nnFileSize)
			{
				strFileContents.resize(nnFileSize);
				oInputStream.seekg(0, std::ios::beg);
				oInputStream.read(&strFileContents[0], nnFileSize);
			}
			else
			{
				WCC_CORE_ERROR("Could not read from file '{0}'", strFilePath);
			}
		}
		else
		{
			WCC_CORE_ERROR("Could not open file '{0}'", strFilePath);
		}

		return strFileContents;
	}
}