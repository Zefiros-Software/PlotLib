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

#include "plot/kdePlot.h"



PLOTLIB_INLINE KDEPlot::KDEPlot( const Vec &data, const Vec &data2 )
{
    mStream << "sns.kdeplot( np.array(" << ToArray( data ) << "), np.array(" << ToArray( data2 ) << ")";
}

PLOTLIB_INLINE KDEPlot::KDEPlot( const Vec &data )
{
    mStream << "sns.kdeplot(np.array(" << ToArray( data ) << ")";
}

PLOTLIB_INLINE std::string KDEPlot::ToString()
{
    return mStream.str() + " )";
}

PLOTLIB_INLINE KDEPlot &KDEPlot::Vertical( bool vertical )
{
    AddArgument( "vertical", GetBool( vertical ) );
    return *this;
}

PLOTLIB_INLINE KDEPlot &KDEPlot::SetKernel( Kernel kernel )
{
    AddArgument( "kernel", GetString( GetKernel( kernel ) ) );
    return *this;
}

PLOTLIB_INLINE KDEPlot &KDEPlot::SetBW( const std::pair<double, double> &scalars )
{
    AddArgument( "bw", ToTuple( scalars.first, scalars.second ) );
    return *this;
}

PLOTLIB_INLINE KDEPlot &KDEPlot::SetBW( double scalar )
{
    AddArgument( "bw", scalar );
    return *this;
}

PLOTLIB_INLINE KDEPlot &KDEPlot::SetBW( BW bw )
{
    AddArgument( "bw", GetString( GetBW( bw ) ) );
    return *this;
}

PLOTLIB_INLINE KDEPlot &KDEPlot::SetGridSize( size_t size )
{
    AddArgument( "gridsize", size );
    return *this;
}

PLOTLIB_INLINE KDEPlot &KDEPlot::SetCut( double cut )
{
    AddArgument( "cut", cut );
    return *this;
}

PLOTLIB_INLINE KDEPlot &KDEPlot::SetClip( const std::pair<double, double> &clipx,
                                          const std::pair<double, double> &clipy )
{
    AddArgument( "clip", ToTuple( ToTuple( clipx.first, clipx.second ), ToTuple( clipy.first, clipy.second ) ) );
    return *this;
}

PLOTLIB_INLINE KDEPlot &KDEPlot::SetClip( const std::pair<double, double> &clip )
{
    AddArgument( "clip", ToTuple( clip.first, clip.second ) );
    return *this;
}

PLOTLIB_INLINE KDEPlot &KDEPlot::Legend( bool legend )
{
    AddArgument( "legend", GetBool( legend ) );
    return *this;
}

PLOTLIB_INLINE KDEPlot &KDEPlot::Cumulative( bool cumulative )
{
    AddArgument( "cumulative", GetBool( cumulative ) );
    return *this;
}

PLOTLIB_INLINE KDEPlot &KDEPlot::ShadeLowest( bool shadeLowest )
{
    AddArgument( "shade_lowest", GetBool( shadeLowest ) );
    return *this;
}

PLOTLIB_INLINE std::string KDEPlot::GetBW( BW bw )
{
    switch ( bw )
    {
    case BW::Scott:
        return "scott";

    case BW::Silverman:
        return "silverman";
    }

    return "";
}

PLOTLIB_INLINE std::string KDEPlot::GetKernel( Kernel kernel )
{
    switch ( kernel )
    {
    case Kernel::Gauss:
        return "gau";

    case Kernel::Cos:
        return "cos";

    case Kernel::Biw:
        return "biw";

    case Kernel::Epa:
        return "epa";

    case Kernel::Tri:
        return "tri";

    case Kernel::Triw:
        return "triw";
    }

    return "";
}