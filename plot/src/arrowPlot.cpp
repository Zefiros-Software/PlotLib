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

#include "plot/arrowPlot.h"



PLOTLIB_INLINE ArrowPlot::ArrowPlot(double x, double y, double dx, double dy)
{
    mStream << "plt.arrow(" << x << "," << y << "," << dx << "," << dy;
}

PLOTLIB_INLINE std::string ArrowPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE ArrowPlot &ArrowPlot::SetWidth(double width)
{
    this->AddArgument("width", width);
    return *this;
}

PLOTLIB_INLINE ArrowPlot &ArrowPlot::LengthIncludesHead(bool includes)
{
    this->AddArgument("length_includes_head", GetBool(includes));
    return *this;
}

PLOTLIB_INLINE ArrowPlot &ArrowPlot::SetHeadWidth(double width)
{
    this->AddArgument("head_width", width);
    return *this;
}

PLOTLIB_INLINE ArrowPlot &ArrowPlot::SetHeadLength(double length)
{
    this->AddArgument("head_length", length);
    return *this;
}

PLOTLIB_INLINE ArrowPlot &ArrowPlot::SetShape(Shape shape)
{
    this->AddArgument("shape", GetShape(shape));
    return *this;
}

PLOTLIB_INLINE ArrowPlot &ArrowPlot::SetOverhang(double overhang)
{
    this->AddArgument("overhang", overhang);
    return *this;
}

PLOTLIB_INLINE ArrowPlot &ArrowPlot::HeadStartsAtZero(bool starts)
{
    this->AddArgument("head_starts_at_zero", GetBool(starts));
    return *this;
}

PLOTLIB_INLINE std::string ArrowPlot::GetShape(Shape shape)
{
    switch (shape)
    {
    case Shape::Full:
        return "'full'";

    case Shape::Left:
        return "'left'";

    case Shape::Right:
        return "'right'";
    }

    return "''";
}