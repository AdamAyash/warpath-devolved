#include "pch.h"
#include "CppUnitTest.h"
#include "Engine/Core/MemoryManagement/MemoryManagedArray.h"

#define EXPECTED_ARRAY_LENGHT 3

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoreUnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		TEST_METHOD(GetArrayLenght)
		{
			long lFirstValue = 1;
			long lSecondValue = 2;
			long lThirdValue = 3;

			WCCEngine::MemoryManagedArray<long> oMemoryManagedArray;
			oMemoryManagedArray.Add(lFirstValue);
			oMemoryManagedArray.Add(lSecondValue);
			oMemoryManagedArray.Add(lThirdValue);

			Assert::IsTrue(EXPECTED_ARRAY_LENGHT == static_cast<int>(oMemoryManagedArray.GetLenght()));
		}
	};
}
