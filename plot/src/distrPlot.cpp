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

#include "plot/distrPlot.h"
#include "plot/pvec.h"

PLOTLIB_INLINE DistrPlot::DistrPlot(const PVec &a)
{
    mStream << "sns.distplot(" << this->ToArray(a);
}

PLOTLIB_INLINE std::string DistrPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetBins(const PVec &bins)
{
    this->AddArgument("bins", this->ToArray(bins));
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetBins(size_t value)
{
    this->AddArgument("bins", value);
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::Hist(bool hist)
{
    this->AddArgument("hist", GetBool(hist));
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::KDE(bool kde)
{
    this->AddArgument("kde", GetBool(kde));
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::RUG(bool rug)
{
    this->AddArgument("rug", GetBool(rug));
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::Vertical(bool vertical)
{
    this->AddArgument("vertical", GetBool(vertical));
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::NormHist(bool normHist)
{
    this->AddArgument("norm_hist", GetBool(normHist));
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetLabel(const std::string &label)
{
    this->AddArgument("label", this->GetString(label));
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetAxisLabel(const std::string &label)
{
    this->AddArgument("axlabel", this->GetString(label));
    return *this;
}

PLOTLIB_INLINE DistrPlot &DistrPlot::SetColour(const std::string &colour)
{
    this->AddArgument("color", this->GetString(colour));

    return *this;
}
