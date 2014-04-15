This project contains template classes to represent big-endian and little-endian values and provides simple conversions between them.

### Conversion from host-endianness

```
using jj::BigEndian;
using jj::LittleEndian;

uint64_t hostVal = 0x0123456789abcdef;
BigEndian<uint64_t> val64Be = hostVal;
LittleEndian<uint64_t> val64Le = hostVal;

const uint8_t expectedBe[] =
  { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef };
const uint8_t expectedLe[] =
  { 0xef, 0xcd, 0xab, 0x89, 0x67, 0x45, 0x23, 0x01 };

assert(0 == memcmp(expectedBe, &val64Be, sizeof(val64Be)));
assert(0 == memcmp(expectedLe, &val64Le, sizeof(val64Le)));
```

### Conversion to host-endianness
```
using jj::BigEndian;
using jj::LittleEndian;

const uint8_t rawBe[] =
  { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef };
const uint8_t rawLe[] =
  { 0xef, 0xcd, 0xab, 0x89, 0x67, 0x45, 0x23, 0x01 };

BigEndian<uint64_t> val64Be = *reinterpret_cast<BigEndian<uint64_t>*>(rawBe);
LittleEndian<uint64_t> val64Le =
  *reinterpret_cast<LittleEndian<uint64_t>*>(rawLe);

uint64_t expectedVal = 0x0123456789abcdef;
assert(expectedVal == static_cast<uint64_t>(val64Be));
assert(expectedVal == static_cast<uint64_t>(val64Le));
```

### Big/Little endian conversion
```
BigEndian<uint64_t> val64Be = ...
LittleEndian<uint64_t> val64Le = val64Be;
```

## Supported types

The following types have been tested:

- `int16_t`
- `uint16_t`
- `int32_t`
- `uint32_t`
- `int64_t`
- `uint64_t`
- `float`
- `double`

## Installation

This is a header only implementation, just copy the header file into your project.

## LICENSE

The MIT License (MIT)

Copyright (c) 2014 Jason Choy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
