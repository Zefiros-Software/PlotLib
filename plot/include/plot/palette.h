#pragma once
#ifndef __PALETTE_H__
#define __PALETTE_H__

#include <sstream>

class Palette
{
public:

    enum class Type
    {
        Deep,
        Muted,
        Bright,
        Pastel,
        Dark,
        ColourBlind,
        Reset,
        Other
    };

    Palette( Type type )
        : mType( type )
    {
    }

    std::string ToString() const
    {
        return GetPalette( mType );
    }

    std::string GetArguments() const
    {
        return mArguments.str();
    }

    Palette &SetColours( size_t nColours )
    {
        mArguments << ", n_colors=" << nColours;
        return *this;
    }

    Palette &SetDesaturation( double desat )
    {
        mArguments << ", desat=" << desat;
        return *this;
    }

    Palette &UseColourCodes( bool colourCodes )
    {
        mArguments << ", color_codes=" << ( colourCodes ? "True" : "False" );
        return *this;
    }

    Palette &SetColourMap( bool map )
    {
        mArguments << ", as_cmap=" << ( map ? "True" : "False" );
        return *this;
    }

protected:

    std::stringstream mStream;
    std::stringstream mArguments;
    Type mType;

    std::string GetPalette( Type palette ) const
    {
        switch ( palette )
        {
        case Type::Deep:
            return "'deep'";

        case Type::Muted:
            return "'muted'";

        case Type::Bright:
            return "'bright'";

        case Type::Pastel:
            return "'pastel'";

        case Type::Dark:
            return "'dark'";

        case Type::ColourBlind:
            return "'colorblind'";

        case Type::Reset:
            return "'None'";

        case Type::Other:
            {
                std::string arguments = mArguments.str();

                if ( arguments.size() > 0 && *arguments.begin() == ',' )
                {
                    arguments = std::string( arguments.begin() + 1, arguments.end() );
                }

                return mStream.str() + arguments + ")";
            }
        }

        return "";
    }
};

class HUSLPalette
    : public Palette
{
public:

    HUSLPalette()
        : Palette( Type::Other )
    {
        mStream << "sns.husl_palette(";
    }

    HUSLPalette &SetColours( size_t nColours )
    {
        mArguments << ", n_colours=" << nColours;
        return *this;
    }

    HUSLPalette &SetH( double h )
    {
        mArguments << ", h=" << h;
        return *this;
    }

    HUSLPalette &SetS( double s )
    {
        mArguments << ", s=" << s;
        return *this;
    }

    HUSLPalette &SetL( double l )
    {
        mArguments << ", l=" << l;
        return *this;
    }
};

class HLSPalette
    : public Palette
{
public:

    HLSPalette()
        : Palette( Type::Other )
    {
        mArguments << "sns.hls_palette(";
    }

    HLSPalette &SetColours( size_t nColours )
    {
        mArguments << ", n_colours=" << nColours;
        return *this;
    }

    HLSPalette &SetH( double h )
    {
        mArguments << ", h=" << h;
        return *this;
    }

    HLSPalette &SetS( double s )
    {
        mArguments << ", s=" << s;
        return *this;
    }

    HLSPalette &SetL( double l )
    {
        mArguments << ", l=" << l;
        return *this;
    }
};

class CubeHelixPalette
    : public Palette
{
public:

    CubeHelixPalette()
        : Palette( Type::Other )
    {
        mStream << "sns.cubehelix_palette(";
    }

    CubeHelixPalette &SetColours( size_t nColours )
    {
        mArguments << ", n_colours=" << nColours;
        return *this;
    }

    CubeHelixPalette &SetStart( double start )
    {
        mArguments << ", start=" << start;
        return *this;
    }

    CubeHelixPalette &SetRot( double rot )
    {
        mArguments << ", rot=" << rot;
        return *this;
    }

    CubeHelixPalette &SetGamma( double gamma )
    {
        mArguments << ", gamma=" << gamma;
        return *this;
    }

    CubeHelixPalette &SetHue( double hue )
    {
        mArguments << ", hue=" << hue;
        return *this;
    }

    CubeHelixPalette &SetDark( double dark )
    {
        mArguments << ", dark=" << dark;
        return *this;
    }

    CubeHelixPalette &SetLight( double light )
    {
        mArguments << ", light=" << light;
        return *this;
    }

    CubeHelixPalette &SetReverse( bool reverse )
    {
        mArguments << ", reverse=" << ( reverse ? "True" : "False" );
        return *this;
    }
};


#endif