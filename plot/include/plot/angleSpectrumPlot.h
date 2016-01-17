/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016 Koen Visscher, Paul Visscher and individual contributors.
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
#ifndef __ANGLESPECTRUMPLOT_H__
#define __ANGLESPECTRUMPLOT_H__

#include "plot/abstractPlot.h"

#include <string>

class AngleSpectrumPlot
    : public AbstractPlot
{
public:

    enum class Sides
    {
        Default,
        OneSided,
        TwoSided
    };

    AngleSpectrumPlot( const Vec &vec )
    {
        mStream << "plt.angle_spectrum(" << ToArray( vec );
    }

    virtual std::string ToString() const override
    {
        return mStream.str() + " )";
    }

    AngleSpectrumPlot &SetSamplingFrequency( double fs )
    {
        mStream << ", Fs=" << fs;
        return *this;
    }

    AngleSpectrumPlot &SetSides( Sides sides )
    {
        mStream << ", sides=" << GetSides( sides );
        return *this;
    }

    AngleSpectrumPlot &SetCenterFrequence( int32_t fc )
    {
        mStream << ", Fc=" << fc;
        return *this;
    }

    AngleSpectrumPlot &SetPadTo( int32_t pad )
    {
        mStream << ", pad_to=" << pad;
        return *this;
    }

private:

    std::stringstream mStream;

    std::string GetSides( Sides sides )
    {
        switch ( sides )
        {
        case Sides::Default:
            return "'default'";

        case Sides::OneSided:
            return "'onesided'";

        case Sides::TwoSided:
            return "'twosided'";
        }
    }

};

#endif