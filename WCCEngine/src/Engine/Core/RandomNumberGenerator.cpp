#include "wccpch.h"
#include <random>

#include "RandomNumberGenerator.h"

namespace WCCEngine
{
    RandomNumberGenerator::RandomNumberGenerator()
    {
    }

    RandomNumberGenerator::~RandomNumberGenerator()
    {
    }

    const UINT RandomNumberGenerator::GetNextUnsignedInt(IN const UINT nBeginRange, IN const UINT nEndRange)
    {
        std::random_device oRandomDevice;
        std::mt19937 oRange(oRandomDevice());
        std::uniform_int_distribution<std::mt19937::result_type> oDistribution(nBeginRange, nEndRange);

        return oDistribution(oRange);
    }
}