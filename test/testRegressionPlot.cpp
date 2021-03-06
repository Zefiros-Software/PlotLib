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

TEST(RegressionPlot, RegressionPlot)
{
    TestPlot< RegressionPlot >("RegressionPlot", []()
    {
        vec x = 2 + randn(100);
        vec y = 2 + 1.5 * x + 2 * randn(100);
        RegressionPlot f(x, y);
        f.Truncate(true)
        .Robust(true)
        .SetXConfidenceInterval(91);
        return f;
    });
}

TEST(RegressionPlot, RegressionPlot2)
{
    TestPlot< RegressionPlot >("RegressionPlot2", []()
    {
        vec x = 2 + randn(100);
        vec y = 2 + 1.5 * x + 2 * randn(100);
        RegressionPlot f(x, y);
        f.FitRegression(true)
        .Lowess(false)
        .SetConfidenceInterval(91);
        return f;
    });
}

TEST(RegressionPlot, RegressionPlot3)
{
    TestPlot< RegressionPlot >("RegressionPlot3", []()
    {
        vec x = 2 + randn(100);
        vec y = 2 + 1.5 * x + 2 * randn(100);
        RegressionPlot f(x, y);
        f.SetXBins({0, 2, 3, 10, 15});
        return f;
    });
}