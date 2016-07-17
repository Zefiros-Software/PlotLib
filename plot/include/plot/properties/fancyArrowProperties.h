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
#ifndef __FANCYARROWPROPERTIES_H__
#define __FANCYARROWPROPERTIES_H__

#include "plot/properties/patchProperties.h"

static const char *const __PlotLibFancyArrowPropertiesConnectionStyle[] =
{
    "angle",
    "angle3",
    "arc",
    "arc3",
    "bar"
};

template<class tBase, bool IsDictn >
class FancyArrowProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value >
class FancyArrowProperties
    : public PatchProperties< FancyArrowProperties< tBase, IsDict >, IsDict, true >
{
public:

    enum class ConnectionStyle
    {
        Angle,
        Angle3,
        Arc,
        Arc3,
        Bar
    };

    tReturn &SetPos( std::pair< double, double > a, std::pair< double, double> b )
    {
        AddArgument( "posA", ToTuple( a.first, a.second ) );
        AddArgument( "posB", ToTuple( b.first, b.second ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetShrink( double a, double b )
    {
        AddArgument( "shrinkA", a );
        AddArgument( "shrinkB", b );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetMutationScale( double scale )
    {
        AddArgument( "mutation_scale", scale );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetMutationAspect( double aspect )
    {
        AddArgument( "mutation_aspect", aspect );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetConnectionStyle( ConnectionStyle style )
    {
        AddArgument( "connectionstyle"
                     , GetString( __PlotLibFancyArrowPropertiesConnectionStyle[static_cast<size_t>( style )] ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetArrowStyle( const std::string &style )
    {
        AddArgument( "arrowstyle", GetString( style ) );

        return static_cast<tReturn &>( *this );
    }

    tReturn &SetDpiCorrection( double dpi )
    {
        AddArgument( "dpi_cor", dpi );

        return static_cast<tReturn &>( *this );
    }
};

typedef FancyArrowProperties<> FancyArrow;


#endif