#include <stdint.h>
#include <stdio.h>
#include <climits>

#include "FuzzedDataProvider.h"
namespace dcmqi
{
    class Helper
    {
    public:
        static std::string floatToStr(float f);
    };
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    float f = provider.ConsumeFloatingPoint<float>();
    dcmqi::Helper::floatToStr(f);

    return 0;
}