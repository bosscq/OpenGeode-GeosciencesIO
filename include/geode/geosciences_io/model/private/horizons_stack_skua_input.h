/*
 * Copyright (c) 2019 - 2023 Geode-solutions
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
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
 */

#pragma once

#include <geode/geosciences/implicit/representation/io/horizons_stack_input.h>

#include <geode/geosciences_io/model/common.h>

namespace geode
{
    namespace detail
    {
        template < index_t dimension >
        class HorizonStackSKUAInput final
            : public HorizonsStackInput< dimension >
        {
        public:
            HorizonStackSKUAInput( absl::string_view filename )
                : HorizonsStackInput< dimension >( filename )
            {
            }

            static absl::string_view extension()
            {
                static constexpr auto ext = "xml";
                return ext;
            }

            HorizonsStack< dimension > read() final;
        };
        ALIAS_2D_AND_3D( HorizonStackSKUAInput );
    } // namespace detail
} // namespace geode