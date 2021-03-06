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
#ifndef __ENGINE_FONTPROPERTIES_H__
#define __ENGINE_FONTPROPERTIES_H__

#include "plot/abstractPlot.h"

static const char *const __PlotLibFontPropertiesStyle[] =
{
    "normal",
    "italic",
    "oblique"
};

static const char *const __PlotLibFontPropertiesVariant[] =
{
    "normal",
    "smallcaps"
};

static const char *const __PlotLibFontPropertiesStrech[] =
{
    "ultra-condensed",
    "extra-condensed",
    "condensed",
    "semi-condensed",
    "normal",
    "semi-expanded",
    "expanded",
    "extra-expanded",
    "ultra-expanded"
};

static const char *const __PlotLibFontPropertiesWeight[] =
{
    "ultralight",
    "light",
    "normal",
    "regular",
    "book",
    "medium",
    "roman",
    "semibold",
    "demibold",
    "demi",
    "bold",
    "heavy",
    "extraBold",
    "black"
};
static const char *const __PlotLibFontPropertiesSize[] =
{
    "xx-small",
    "x-small",
    "small",
    "medium",
    "large",
    "x-large",
    "xx-large"
};

template<class tBase, bool IsDict, bool IsBase >
class FontProperties;

template< typename tBase = void *,
          bool IsDict = std::is_same< tBase, void * >::value,
          bool IsBase = false >
class FontProperties
    : public AbstractPlot
{
public:
    typedef typename std::conditional < IsDict &&!IsBase, FontProperties< tBase, IsDict >, tBase & >::type tReturn;

    enum class Style
    {
        Normal,
        Italic,
        Oblique
    };

    enum class Variant
    {
        Normal,
        SmallCaps
    };

    enum class Stretch
    {
        UltraCondensed,
        ExtraCondensed,
        Condensed,
        SemiCondensed,
        Normal,
        SemiExpanded,
        Expanded,
        ExtraExpanded,
        UltraExpanded
    };

    enum class Weight
    {
        UltraLight,
        Light,
        Normal,
        Regular,
        Book,
        Medium,
        Roman,
        SemiBold,
        DemiBold,
        Demi,
        Bold,
        Heavy,
        ExtraBold,
        Black
    };

    enum class Size
    {
        XXSmall,
        XSmall,
        Small,
        Medium,
        Large,
        XLarge,
        XXLarge
    };

    tReturn &SetFamily(const std::vector< std::string > &families)
    {
        this->AddArgument("family", this->ToArray(families));
        return static_cast<tBase &>(*this);
    }

    tReturn &SetStyle(Style style)
    {
        this->AddArgument("style", this->GetString(__PlotLibFontPropertiesStyle[static_cast<size_t>(style)]));
        return static_cast<tBase &>(*this);
    }

    tReturn &SetVariant(Variant variant)
    {
        this->AddArgument("variantvariant", this->GetString(__PlotLibFontPropertiesVariant[static_cast<size_t>(variant)]));
        return static_cast<tBase &>(*this);
    }

    tReturn &SetStretch(Stretch stretch)
    {
        this->AddArgument("stretch", this->GetString(__PlotLibFontPropertiesStrech[static_cast<size_t>(stretch)]));
        return static_cast<tBase &>(*this);
    }

    tReturn &SetStretch(uint32_t stretch)
    {
        this->AddArgument("stretch", stretch);
        return static_cast<tBase &>(*this);
    }

    tReturn &SetWeight(Weight weight)
    {
        this->AddArgument("weight", this->GetString(__PlotLibFontPropertiesWeight[static_cast<size_t>(weight)]));
        return static_cast<tBase &>(*this);
    }

    tReturn &SetWeight(uint32_t weight)
    {
        this->AddArgument("weight", weight);
        return static_cast<tBase &>(*this);
    }

    tReturn &SetSize(Size size)
    {
        this->AddArgument("size", this->GetString(__PlotLibFontPropertiesSize[static_cast<size_t>(size)]));
        return static_cast<tBase &>(*this);
    }

    tReturn &SetSize(double size)
    {
        this->AddArgument("size", size);
        return static_cast<tBase &>(*this);
    }
};

typedef FontProperties<> Font;

#endif