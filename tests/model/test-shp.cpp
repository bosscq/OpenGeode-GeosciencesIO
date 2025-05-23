/*
 * Copyright (c) 2019 - 2025 Geode-solutions
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

#include <geode/tests_config.hpp>

#include <geode/basic/assert.hpp>
#include <geode/basic/logger.hpp>

#include <geode/model/representation/core/section.hpp>
#include <geode/model/representation/io/section_input.hpp>

#include <geode/geosciences_io/model/common.hpp>

int main()
{
    try
    {
        geode::GeosciencesIOModelLibrary::initialize();
        const auto section = geode::load_section(
            absl::StrCat( geode::DATA_PATH, "toulouse.shz" ) );
        OPENGEODE_EXCEPTION(
            section.nb_corners() == 7, "[Test] Wrong number of corners" );
        OPENGEODE_EXCEPTION(
            section.nb_lines() == 10, "[Test] Wrong number of lines" );
        OPENGEODE_EXCEPTION(
            section.nb_surfaces() == 12, "[Test] Wrong number of surfaces" );

        const auto section2 =
            geode::load_section( absl::StrCat( geode::DATA_PATH, "test.shp" ) );
        OPENGEODE_EXCEPTION(
            section2.nb_corners() == 0, "[Test] Wrong number of corners" );
        OPENGEODE_EXCEPTION(
            section2.nb_lines() == 0, "[Test] Wrong number of lines" );
        OPENGEODE_EXCEPTION(
            section2.nb_surfaces() == 1, "[Test] Wrong number of surfaces" );

        geode::Logger::info( "TEST SUCCESS" );
        return 0;
    }
    catch( ... )
    {
        return geode::geode_lippincott();
    }
}
