/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016-2018 Zefiros Software.
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
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @endcond
 */

#include "plot/plotting.h"

#include "helper.h"

TEST(ContourfPlot, ContourfPlot)
{
    TestPlot< ContourfPlot >("ContourfPlot", []()
    {
        mat m = zeros(300, 300);

        for (uint32_t i = 0; i < 300; ++i)
        {
            for (uint32_t j = 0; j < 300; ++j)
            {
                m(i, j) = cos((i / 300.0) * 4 * datum::pi) + cos((j / 300.0) * 4 * datum::pi);
            }
        }

        ContourfPlot f(m);
        f.SetColourMap(ColourMap::Sequential::YlGnBu);
        return f;
    });
}


TEST(ContourfPlot, ContourfPlot2)
{
    TestPlot< ContourfPlot >("ContourfPlot2", []()
    {
        mat m = zeros(300, 300);

        for (uint32_t i = 0; i < 300; ++i)
        {
            for (uint32_t j = 0; j < 300; ++j)
            {
                m(i, j) = cos((i / 300.0) * 4 * datum::pi) + cos((j / 300.0) * 4 * datum::pi);
            }
        }

        ContourfPlot f(m, 10);
        f.SetColourMap(ColourMap::Uniform::Viridis);
        return f;
    });
}

TEST(ContourfPlot, ContourfPlot3)
{
    TestPlot< ContourfPlot >("ContourfPlot3", []()
    {
        mat m = zeros(300, 300);

        for (uint32_t i = 0; i < 300; ++i)
        {
            for (uint32_t j = 0; j < 300; ++j)
            {
                m(i, j) = cos((i / 300.0) * 4 * datum::pi) + cos((j / 300.0) * 4 * datum::pi);
            }
        }

        ContourfPlot f(m, { 0, 1, 4 });
        f.SetColourMap(ColourMap::Sequential::Oranges);
        return f;
    });
}

TEST(ContourfPlot, ContourfPlot4)
{
    TestPlot< ContourfPlot >("ContourfPlot4", []()
    {
        mat m = zeros(300, 300);

        for (uint32_t i = 0; i < 300; ++i)
        {
            for (uint32_t j = 0; j < 300; ++j)
            {
                m(i, j) = cos((i / 300.0) * 4 * datum::pi) + cos((j / 300.0) * 4 * datum::pi);
            }
        }

        ContourfPlot f((vec)(linspace(-15, 15, 300)),
                       (vec)(linspace(-15, 15, 300)),
                       m, 3);
        f.SetColourMap(ColourMap::Uniform::Viridis);
        return f;
    });
}

TEST(ContourfPlot, ContourfPlot5)
{
    TestPlot< ContourfPlot >("ContourfPlot5", []()
    {
        mat m = zeros(300, 300);

        for (uint32_t i = 0; i < 300; ++i)
        {
            for (uint32_t j = 0; j < 300; ++j)
            {
                m(i, j) = cos((i / 300.0) * 4 * datum::pi) + cos((j / 300.0) * 4 * datum::pi);
            }
        }

        ContourfPlot f((vec)(linspace(-15, 15, 300)),
                       (vec)(linspace(-15, 15, 300)),
                       m, { 0, 0.5, 1 });
        f.SetColourMap(ColourMap::Uniform::Viridis);
        return f;
    });
}

TEST(ContourfPlot, ContourfPlot6)
{
    TestPlot< ContourfPlot >("ContourfPlot6", []()
    {
        mat m = zeros(300, 300);

        for (uint32_t i = 0; i < 300; ++i)
        {
            for (uint32_t j = 0; j < 300; ++j)
            {
                m(i, j) = cos((i / 300.0) * 4 * datum::pi) + cos((j / 300.0) * 4 * datum::pi);
            }
        }

        ContourfPlot f((vec)(linspace(0, 15, 300)),
                       (vec)(linspace(0, 15, 300)), m);
        f.SetColourMap(ColourMap::Uniform::Viridis);
        return f;
    });
}