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
#ifndef __PLOT_H__
#define __PLOT_H__

#include "plot/properties/scaleProperties.h"
#include "plot/abstractPlot.h"
#include "plot/palette.h"

#include <sstream>
#include <fstream>

class CustomLegend;

class Plot
{
public:

    enum Style
    {
        DarkGrid,
        WhiteGrid,
        Dark,
        White,
        Ticks
    };

    enum Context
    {
        Paper,
        Notebook,
        Talk,
        Poster
    };

    enum Location
    {
        Best,
        UpperRight,
        UpperLeft,
        LowerLeft,
        LowerRight,
        Right,
        CentreLeft,
        CentreRight,
        LowerCentre,
        UpperCentre,
        Centre
    };

    Plot();

    Plot(Context context);

    Plot(const AbstractPlot &plot);

    Plot &AxisStyle(Style style, const std::vector< std::pair< std::string, std::string >> &params = {});

    Plot &Set(Context context, const std::vector< std::pair< std::string, std::string >> &params = {});

    Plot &Set(Context context, double fontScale, const std::vector< std::pair< std::string, std::string >> &params = {});

    Plot &SetColourCodes();

    Plot &SetColourCodes(Palette::Seaborn seaborn);

    Plot &SetXLabel(const std::string &xlabel, size_t fontSize);

    Plot &SetYLabel(const std::string &ylabel, size_t fontSize);

    Plot &SetZLabel(const std::string &zlabel, size_t fontSize);

    Plot &SetXLimit(double xmin, double xmax);

    Plot &SetYLimit(double ymin, double ymax);

    Plot &SetTitle(const std::string &title, size_t fontSize);

    Plot &SetSupTitle(const std::string &title, size_t fontSize);

    Plot &SetLegend(const std::vector<std::string> &titles, size_t fontSize);

    Plot &SetXLabel(const std::string &xlabel);

    Plot &SetYLabel(const std::string &ylabel);

    Plot &SetZLabel(const std::string &zlabel);

    Plot &SetTitle(const std::string &title);

    Plot &SetSupTitle(const std::string &title);

    Plot &SetLegend(const std::vector<std::string> &titles);

    template< typename tT, typename tFunc >
    Plot &SetLegend(const std::vector<tT> &titleData, const tFunc &titleFunc)
    {
        std::vector<std::string> titles;

        for (const tT &title : titleData)
        {
            titles.push_back(titleFunc(title));
        }

        SetLegend(titles, Location::Best);

        return *this;
    }

    Plot &SetLegend(const std::vector<std::string> &titles, Location location);

    Plot &SetLegend(Location location);

    Plot &SetXKCD();

    Plot &ResetDefaults();

    Plot &ResetOrig();

    Plot &AxisLabels(const std::string &xlabel, const std::string &ylabel);

    Plot &SetPalette(const Palette &palette);

    template< typename tScale >
    Plot &SetYScale(const tScale &scale)
    {
        mStream << const_cast< tScale & >(scale).ToString() << "\n";

        return *this;
    }

    Plot &AddPlot(AbstractPlot &plot);

    Plot &AddPlot(const AbstractPlot &plot);

    Plot &AddColourCycler(const Palette &palette);

    std::string GetColourCycler() const;

    Plot &AddCustomLegend(CustomLegend &legend);

    Plot &AddCustomLegend(const CustomLegend &legend);

    Plot &SetSize(size_t width, size_t height);

    Plot &Despine();

    Plot &Show();

    Plot &SetTightLayout();

    Plot &EnableLaTeX();

    Plot &Save(const std::string &fname,  const std::string &pythonName = "plot.in");

    Plot &Figure(size_t n);

    Plot &Figure();

    Plot &SubPlot(size_t y, size_t x, size_t n);

    template< typename tT >
    Plot &operator<<(const tT &t)
    {
        mStream << t;

        return *this;
    }

    Plot &AddCustomPython(const std::string &str);

protected:

    std::stringstream mInitStream;
    std::stringstream mStream;
    std::string mPython;

    bool mHasColourCycler;

    void SetPythonPath();

    static std::string GetContext(Context context);

    static std::string GetLocation(Location location);

    static std::string GetStyle(Style style);

    static std::string GetDictionary(const std::vector< std::pair< std::string, std::string >> &params);

};

#ifndef PLOTLIB_NO_HEADER_ONLY
#   include "../../src/plot.cpp"
#endif

#endif