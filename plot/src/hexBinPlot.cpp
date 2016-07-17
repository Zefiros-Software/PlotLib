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

#include "plot/hexBinPlot.h"



PLOTLIB_INLINE HexBinPlot::HexBinPlot( const Vec &x, const Vec &y )
{
    mStream << "plt.hexbin(" << ToArray( x ) << ", " << ToArray( y );
}

PLOTLIB_INLINE std::string HexBinPlot::ToString()
{
    return mStream.str() + " )\nplt.colorbar()";
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetGridSize( size_t size )
{
    mStream << ", gridsize=" << size;
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetGridSize( const std::pair< size_t, size_t > &size )
{
    mStream << ", gridsize=(" << size.first << "," << size.second << ")";
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetBins( const Vec &bins )
{
    mStream << ", bins=" << ToArray( bins );
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetBins( BinType type )
{
    mStream << ", bins=" << ( type == BinType::Logarithmic ? "'log'" : "None" );
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetBins( size_t bins )
{
    mStream << ", bins=" << bins;
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetXScale( Scale scale )
{
    mStream << ", xscale=" << GetScale( scale );
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetScale( Scale scale )
{
    mStream << ", scale=" << GetScale( scale );
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetMinCount( size_t minCount )
{
    mStream << ", mincnt=" << minCount;
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetMarginals( bool marginals )
{
    mStream << ", marginals=" << GetBool( marginals );
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetExtent( size_t left, size_t right, size_t bottom, size_t top )
{
    mStream << ", extent=(" << left << "," << right << "," << bottom << "," << top << ")";
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetColourMap( Palette pallet )
{
    pallet.SetColourMap( true );
    mStream << ", cmap=" << pallet.ToString();
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetMinValue( double value )
{
    mStream << ", vmin=" << value;
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetMaxValue( double value )
{
    mStream << ", vmax=" << value;
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetLineWidths( double value )
{
    mStream << ", linewidths=" << value;
    return *this;
}

PLOTLIB_INLINE HexBinPlot &HexBinPlot::SetAlpha( double value )
{
    mStream << ", alpha=" << value;
    return *this;
}

PLOTLIB_INLINE std::string HexBinPlot::GetScale( Scale scale )
{
    switch ( scale )
    {
    case Scale::Linear:
        return "'linear'";

    case Scale::Logarithmic:
        return "'log'";
    }

    return "";
}
