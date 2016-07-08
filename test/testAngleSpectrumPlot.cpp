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

#include "plot/plotting.h"

#include "helper.h"

TEST( AngleSpectrumPlot, AngleSpectrumPlot )
{
    TestPlot< AngleSpectrumPlot >( "AngleSpectrumPlot", []()
    {
        //! [AngleSpectrumPlot]
        vec randVec = randu( 20 ) ;
        AngleSpectrumPlot f( randVec );
        //! [AngleSpectrumPlot]
        return f;
    } );
}

TEST( AngleSpectrumPlot, Construct )
{
    AngleSpectrumPlot( Vec( { 0 } ) );
}

TEST( AngleSpectrumPlot, ToString )
{
    EXPECT_EQ( "plt.angle_spectrum( [0] )", AngleSpectrumPlot( Vec( { 0 } ) ).ToString() );
}

TEST( AngleSpectrumPlot, SetSamplingFrequency )
{
    TestPlot< AngleSpectrumPlot >( "AngleSpectrumPlot_SamplingFrequency", []()
    {
        //! [AngleSpectrumPlot_SamplingFrequency]
        vec randVec = randu( 20 );
        AngleSpectrumPlot f( randVec );
        f.SetSamplingFrequency( 10 );
        //! [AngleSpectrumPlot_SamplingFrequency]
        return f;
    } );
}

TEST( AngleSpectrumPlot, SetSides )
{
    TestPlot< AngleSpectrumPlot >( "AngleSpectrumPlot_SetSides", []()
    {
        //! [AngleSpectrumPlot_SetSides]
        vec randVec = randu( 20 );
        AngleSpectrumPlot f( randVec );
        f.SetSides( AngleSpectrumPlot::Sides::Default );
        //! [AngleSpectrumPlot_SetSides]
        return f;
    } );
}

TEST( AngleSpectrumPlot, SetSides_OneSided )
{
    TestPlot< AngleSpectrumPlot >( "AngleSpectrumPlot_SetSides_OneSided", []()
    {
        //! [AngleSpectrumPlot_SetSides_OneSided]
        vec randVec = randu( 20 );
        AngleSpectrumPlot f( randVec );
        f.SetSides( AngleSpectrumPlot::Sides::OneSided );
        //! [AngleSpectrumPlot_SetSides_OneSided]
        return f;
    } );
}

TEST( AngleSpectrumPlot, SetSides_TwoSided )
{
    TestPlot< AngleSpectrumPlot >( "AngleSpectrumPlot_SetSides_TwoSided", []()
    {
        //! [AngleSpectrumPlot_SetSides_TwoSided]
        vec randVec = randu( 20 );
        AngleSpectrumPlot f( randVec );
        f.SetSides( AngleSpectrumPlot::Sides::TwoSided );
        //! [AngleSpectrumPlot_SetSides_TwoSided]
        return f;
    } );
}

TEST( AngleSpectrumPlot, SetCentreFrequency )
{
    TestPlot< AngleSpectrumPlot >( "AngleSpectrumPlot_SetCentreFrequency", []()
    {
        //! [AngleSpectrumPlot_SetCentreFrequency]
        vec randVec = randu( 20 );
        AngleSpectrumPlot f( randVec );
        f.SetCentreFrequency( 5 );
        //! [AngleSpectrumPlot_SetCentreFrequency]
        return f;
    } );
}


TEST( AngleSpectrumPlot, SetPadTo )
{
    TestPlot< AngleSpectrumPlot >( "AngleSpectrumPlot_SetPadTo", []()
    {
        //! [AngleSpectrumPlot_SetPadTo]
        vec randVec = randu( 20 );
        AngleSpectrumPlot f( randVec );
        f.SetPadTo( 2 );
        //! [AngleSpectrumPlot_SetPadTo]
        return f;
    } );
}