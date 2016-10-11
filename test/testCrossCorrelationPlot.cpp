/**
 * @cond ___LICENSE___
 *
 * Copyright (c) 2016 Mick van Duijn, Koen Visscher and Paul Visscher
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

TEST( CrossCorrelationPlot, CrossCorrelationPlot )
{
    TestPlot< CrossCorrelationPlot >( "CrossCorrelationPlot", []()
    {
        vec xVec = randu( 200 );
        vec yVec = randu( 200 );
        CrossCorrelationPlot f( xVec, yVec );
        return f;
    } );
}

TEST( CrossCorrelationPlot, SetHold )
{
    TestPlot< CrossCorrelationPlot >( "CrossCorrelationPlot_SetHold", []()
    {
        vec xVec = randu( 200 );
        vec yVec = randu( 200 );
        CrossCorrelationPlot f( xVec, yVec );
        f.SetLineWidth( 3 )
        .SetColour( "b" )
        .Hold( false )
        .Normed( true );
        return f;
    } );
}

TEST( CrossCorrelationPlot, SetVLines )
{
    TestPlot< CrossCorrelationPlot >( "CrossCorrelationPlot_SetVLines", []()
    {
        vec xVec = randu( 200 );
        vec yVec = randu( 200 );
        CrossCorrelationPlot f( xVec, yVec );
        f.SetMarker( "." )
        .VLines( false )
        .SetMaxLags( 100 )
        .SetDetrend( CrossCorrelationPlot::Detrend::Linear );
        return f;
    } );
}