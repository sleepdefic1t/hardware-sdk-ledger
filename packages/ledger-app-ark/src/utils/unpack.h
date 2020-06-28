/*******************************************************************************
 * This file is part of the ARK Ledger App.
 *
 * Copyright (c) ARK Ecosystem <info@ark.io>
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * -----
 * 
 * Parts of this software are based on Ledger Nano SDK
 * 
 * (c) 2017 Ledger
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#ifndef ARK_UTILS_UNPACK_H
#define ARK_UTILS_UNPACK_H

#if defined(HAVE_BOLOS_SDK)
// The Ledger SDK implements 2 and 4-byte little-endian integer unpacking.
// We only need to implement the 8-byte equivalent.
#include <os.h>

////////////////////////////////////////////////////////////////////////////////
#define U8LE(buf, off)                                                              \
        (((uint64_t)(U4LE(buf, off))                    & 0xFFFFFFFF)           |   \
         ((uint64_t)(U4LE(buf, off + sizeof(uint32_t))  & 0xFFFFFFFF) << 32U))
#else  // if not HAVE_BOLOS_SDK
// If not using the Ledger SDK, we need to implement the unpacking macros.

#include <stddef.h>
#include <stdint.h>

////////////////////////////////////////////////////////////////////////////////
static const uint8_t U1_MAX         = 0xFF;
static const uint16_t U2_MAX        = 0xFFFF;
static const uint32_t U4_MAX        = 0xFFFFFFFF;
static const uint64_t U8_MAX        = 0xFFFFFFFFFFFFFFFF;

static const size_t U1_SIZE         = sizeof(uint8_t);
static const size_t U2_SIZE         = sizeof(uint16_t);
static const size_t U4_SIZE         = sizeof(uint32_t);

static const uint16_t U1_SHIFT      = 8U;
static const uint32_t U2_SHIFT      = 16UL;
static const uint64_t U4_SHIFT      = 32ULL;

////////////////////////////////////////////////////////////////////////////////
#define U2LE(src, offset)                                                               \
    ((((uint16_t)(((src)[(offset)])                     & U1_MAX))                  |   \
     (((uint16_t)(((src)[((offset) + U1_SIZE)])         & U1_MAX)   << U1_SHIFT)))      \
                                                        & U2_MAX)

#define U4LE(src, offset)                                                               \
    ((((uint32_t)((U2LE((src), (offset)))               & U2_MAX))                  |   \
     (((uint32_t)((U2LE((src), ((offset) + U2_SIZE)))   & U2_MAX)   << U2_SHIFT)))      \
                                                        & U4_MAX)

#define U8LE(src, offset)                                                               \
    ((((uint64_t)((U4LE((src), (offset)))               & U4_MAX))                  |   \
     (((uint64_t)((U4LE((src), ((offset) + U4_SIZE)))   & U4_MAX)   << U4_SHIFT)))      \
                                                        & U8_MAX)
#endif  // HAVE_BOLOS_SDK

#endif  // ARK_UTILS_UNPACK_H
