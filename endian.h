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

#ifndef JJ_ENDIAN_H
#define JJ_ENDIAN_H

#include <iostream>
#include <cstdint>

namespace jj {

template <typename T>
struct LittleEndian;

template <typename T>
struct BigEndian {
    static constexpr int numBytes() {
        return sizeof(T);
    }

    static constexpr int numBits() {
        return sizeof(T) * 8;
    }

    uint8_t data[numBytes()];

    BigEndian(T value) {
        for (int i=0; i<numBytes(); ++i) {
            data[i] = static_cast<uint8_t>(value >> (numBits() - (i + 1) * 8));
        }
    }

    BigEndian(const LittleEndian<T>& le) : BigEndian(static_cast<T>(le)) {}

    operator T() const {
        T val = 0;
        for (int i=0; i<numBytes(); ++i) {
            val |= static_cast<uint64_t>(data[i]) << (numBits() - (i + 1) * 8);
        }
        return val;
    }
};

template <typename T>
struct LittleEndian {
    static constexpr int numBytes() {
       return sizeof(T);
    }

    static constexpr int numBits() {
        return sizeof(T) * 8;
    }

    uint8_t data[numBytes()];

    LittleEndian(T value) {
        for (int i=0; i<numBytes(); ++i) {
            data[i] = static_cast<uint8_t>(value >> (i * 8));
        }
    }

    LittleEndian(const BigEndian<T>& be) : LittleEndian(static_cast<T>(be)) {}

    operator T() const {
        T val = 0;
        for (int i=0; i<numBytes(); ++i) {
            val |= static_cast<uint64_t>(data[i]) << (i * 8);
        }
        return val;
    }
};

namespace {

uint32_t floatAsInt(float f) {
    union {
        float fv;
        uint32_t uv;
    } u;
    u.fv = f;
    return u.uv;
}

float intAsFloat(uint32_t v) {
    union {
        float fv;
        uint32_t uv;
    } u;
    u.uv = v;
    return u.fv;
}

uint64_t doubleAsInt(double d) {
    union {
        double dv;
        uint64_t uv;
    } u;
    u.dv = d;
    return u.uv;
}

double intAsDouble(uint64_t v) {
    union {
        double dv;
        uint64_t uv;
    } u;
    u.uv = v;
    return u.dv;
}

}

template <>
struct BigEndian<float> : private BigEndian<uint32_t> {
    using BigEndian<uint32_t>::numBytes;
    using BigEndian<uint32_t>::numBits;

    BigEndian(float val)
        : BigEndian<uint32_t>(floatAsInt(val)) {}

    operator float() const {
        uint32_t val = static_cast<uint32_t>(*this);
        return intAsFloat(val);
    }
};

template <>
struct BigEndian<double> : private BigEndian<uint64_t> {
    using BigEndian<uint64_t>::numBytes;
    using BigEndian<uint64_t>::numBits;

    BigEndian(double val)
        : BigEndian<uint64_t>(doubleAsInt(val)) {}

    operator double() const {
        uint64_t val = static_cast<uint64_t>(*this);
        return intAsDouble(val);
    }
};

template <>
struct LittleEndian<float> : private LittleEndian<uint32_t> {
    using LittleEndian<uint32_t>::numBytes;
    using LittleEndian<uint32_t>::numBits;

    LittleEndian(float val)
        : LittleEndian<uint32_t>(floatAsInt(val)) {}

    operator float() const {
        uint32_t val = static_cast<uint32_t>(*this);
        return intAsFloat(val);
    }
};

template <>
struct LittleEndian<double> : private LittleEndian<uint64_t> {
    using LittleEndian<uint64_t>::numBytes;
    using LittleEndian<uint64_t>::numBits;

    LittleEndian(double val)
        : LittleEndian<uint64_t>(doubleAsInt(val)) {}

    operator double() const {
        uint64_t val = static_cast<uint64_t>(*this);
        return intAsDouble(val);
    }
};

}

#endif
