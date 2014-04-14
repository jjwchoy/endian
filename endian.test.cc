// The MIT License (MIT)
// 
// Copyright (c) 2014 Jason Choy
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "endian.h"

#include <cassert>
#include <cstdlib>
#include <cstring>

int main() {
    using jj::BigEndian;
    using jj::LittleEndian;

    uint16_t val16 = 0x1234;
    int16_t sval16 = 0x1234;

    BigEndian<uint16_t> val16Be = val16;
    LittleEndian<uint16_t> val16Le = val16;
    BigEndian<int16_t> sval16Be = sval16;
    LittleEndian<int16_t> sval16Le = sval16;

    uint8_t exp16Be[] = {0x12, 0x34};
    uint8_t exp16Le[] = {0x34, 0x12};

    assert(sizeof(uint16_t) == sizeof(BigEndian<uint16_t>));
    assert(sizeof(uint16_t) == sizeof(LittleEndian<uint16_t>));
    assert(sizeof(int16_t) == sizeof(BigEndian<int16_t>));
    assert(sizeof(int16_t) == sizeof(LittleEndian<int16_t>));
    assert(0 == memcmp(exp16Be, &val16Be, sizeof(exp16Be)));
    assert(0 == memcmp(exp16Le, &val16Le, sizeof(exp16Le)));
    assert(0 == memcmp(exp16Be, &sval16Be, sizeof(exp16Be)));
    assert(0 == memcmp(exp16Le, &sval16Le, sizeof(exp16Le)));

    uint32_t val32 = 0x12345678;
    int32_t sval32 = 0x12345678;

    BigEndian<uint32_t> val32Be = val32;
    LittleEndian<uint32_t> val32Le = val32;
    BigEndian<int32_t> sval32Be = val32;
    LittleEndian<int32_t> sval32Le = val32;

    uint8_t exp32Be[] = {0x12, 0x34, 0x56, 0x78};
    uint8_t exp32Le[] = {0x78, 0x56, 0x34, 0x12};

    assert(sizeof(uint32_t) == sizeof(BigEndian<uint32_t>));
    assert(sizeof(uint32_t) == sizeof(LittleEndian<uint32_t>));
    assert(sizeof(int32_t) == sizeof(BigEndian<int32_t>));
    assert(sizeof(int32_t) == sizeof(LittleEndian<int32_t>));
    assert(0 == memcmp(exp32Be, &val32Be, sizeof(exp32Be)));
    assert(0 == memcmp(exp32Le, &val32Le, sizeof(exp32Le)));
    assert(0 == memcmp(exp32Be, &sval32Be, sizeof(exp32Be)));
    assert(0 == memcmp(exp32Le, &sval32Le, sizeof(exp32Le)));

    uint64_t val64 = 0x123456789abcdef0;
    int64_t sval64 = 0x123456789abcdef0;

    BigEndian<uint64_t> val64Be = val64;
    LittleEndian<uint64_t> val64Le = val64;
    BigEndian<int64_t> sval64Be = val64;
    LittleEndian<int64_t> sval64Le = val64;

    uint8_t exp64Be[] = {0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0};
    uint8_t exp64Le[] = {0xf0, 0xde, 0xbc, 0x9a, 0x78, 0x56, 0x34, 0x12};

    assert(sizeof(uint64_t) == sizeof(BigEndian<uint64_t>));
    assert(sizeof(uint64_t) == sizeof(LittleEndian<uint64_t>));
    assert(sizeof(int64_t) == sizeof(BigEndian<int64_t>));
    assert(sizeof(int64_t) == sizeof(LittleEndian<int64_t>));
    assert(0 == memcmp(exp64Be, &val64Be, sizeof(exp64Be)));
    assert(0 == memcmp(exp64Le, &val64Le, sizeof(exp64Le)));
    assert(0 == memcmp(exp64Be, &sval64Be, sizeof(exp64Be)));
    assert(0 == memcmp(exp64Le, &sval64Le, sizeof(exp64Le)));

    float fval = *reinterpret_cast<float*>(&val32);

    BigEndian<float> fvalBe = fval;
    LittleEndian<float> fvalLe = fval;

    assert(sizeof(float) == sizeof(BigEndian<float>));
    assert(sizeof(float) == sizeof(LittleEndian<float>));
    assert(0 == memcmp(exp32Be, &fvalBe, sizeof(exp32Be)));
    assert(0 == memcmp(exp32Le, &fvalLe, sizeof(exp32Le)));

    double dval = *reinterpret_cast<double*>(&val64);

    BigEndian<double> dvalBe = dval;
    LittleEndian<double> dvalLe = dval;

    assert(sizeof(double) == sizeof(BigEndian<double>));
    assert(sizeof(double) == sizeof(LittleEndian<double>));
    assert(0 == memcmp(exp64Be, &dvalBe, sizeof(exp64Be)));
    assert(0 == memcmp(exp64Le, &dvalLe, sizeof(exp64Le)));
}
