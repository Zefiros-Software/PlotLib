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

#pragma once
#ifndef __PAIRPLOT_H__
#define __PAIRPLOT_H__

#include "plot/abstractPlot.h"
#include "plot/mat.h"

class PairPlot
    : public AbstractPlot
{
public:

    enum Type
    {
        Scatter,
        Regression
    };

    enum DiagonalType
    {
        Histogram,
        KernelDensity
    };

    PairPlot(const PMat &mat, const std::vector< std::string > &names);

    PairPlot(const std::vector< PMat > &mats, const std::vector< std::string > &names,
             const std::vector< std::string > &hue);

    virtual std::string ToString() override;

    PairPlot &SetXVars(const std::vector< std::string > &xvars);

    PairPlot &SetYVars(const std::vector< std::string > &yvars);

    PairPlot &SetType(Type type);

    PairPlot &SetDiagonalType(DiagonalType type);

    PairPlot &SetMarker(const std::string &marker);

    PairPlot &SetMarkers(const std::vector<std::string> &marker);

    PairPlot &SetSize(double size);

    PairPlot &SetAspect(double aspect);
};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/pairPlot.cpp"
#endif

#endif