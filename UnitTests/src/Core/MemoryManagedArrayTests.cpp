#include "pch.h"
#include "CppUnitTest.h"
#include "Engine/Core/MemoryManagement/MemoryManagedArray.h"

#define EXPECTED_ARRAY_LENGHT 3
#define EXPECTED_GET_AT_VALUE 2
#define EXPECTED_LINEAR_SEARCH_SIMPLE_RETURNED_INDEX 1

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CoreUnitTests
{
	TEST_CLASS(MemoryMnagedArrayTests)
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

		TEST_METHOD(ClearArray)
		{
			long lFirstValue = 1;
			long lSecondValue = 2;
			long lThirdValue = 3;

			WCCEngine::MemoryManagedArray<long> oMemoryManagedArray;
			oMemoryManagedArray.Add(lFirstValue);
			oMemoryManagedArray.Add(lSecondValue);
			oMemoryManagedArray.Add(lThirdValue);

			oMemoryManagedArray.Clear();

			Assert::IsTrue(oMemoryManagedArray.GetLenght() == 0);
		}

		TEST_METHOD(GetElement)
		{
			long lFirstValue = 1;
			long lSecondValue = 2;
			long lThirdValue = 3;

			WCCEngine::MemoryManagedArray<long> oMemoryManagedArray;
			oMemoryManagedArray.Add(lFirstValue);
			oMemoryManagedArray.Add(lSecondValue);
			oMemoryManagedArray.Add(lThirdValue);

			long* pFirsElement = oMemoryManagedArray.GetAt(1);


			Assert::IsTrue(pFirsElement && *pFirsElement == EXPECTED_GET_AT_VALUE);
		}
	};
}
