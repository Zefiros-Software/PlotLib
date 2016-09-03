#include "plot/pvec.h"

#include "helper.h"

TEST( PVec, Construct )
{
    EXPECT_FALSE( std::is_constructible<PVec>::value );
}

TEST( PVec, FloatConstr )
{
    PVec v( { 0.1f, 2.0f, 8.0f } );

    EXPECT_DOUBLE_EQ( 0.1f, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 2.0f, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 8.0f, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( PVec, DoubleConstr )
{
    PVec v( { 0.1, 2.0, 8.0 } );

    EXPECT_DOUBLE_EQ( 0.1, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 2.0, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 8.0, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( PVec, IntConstr )
{
    PVec v( { 1, 2, 8 } );

    EXPECT_DOUBLE_EQ( 1, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 2, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 8, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( PVec, IntStrConstr )
{
    PVec v( {"1", "2", "8" } );

    EXPECT_EQ( "1", v.GetStrings()[0] );
    EXPECT_EQ( "2", v.GetStrings()[1] );
    EXPECT_EQ( "8", v.GetStrings()[2] );
    EXPECT_EQ( 3, v.GetStrings().size() );

    EXPECT_EQ( 0, v.GetData().size() );
}

TEST( PVec, Valarr )
{
    PVec v( std::valarray< int16_t > { 1, 2, 8 } );

    EXPECT_DOUBLE_EQ( 1, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 2, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 8, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( PVec, Str )
{
    PVec v( { "1", "2", "8" } );

    EXPECT_EQ( "1", v.GetStrings()[0] );
    EXPECT_EQ( "2", v.GetStrings()[1] );
    EXPECT_EQ( "8", v.GetStrings()[2] );
    EXPECT_EQ( 3, v.GetStrings().size() );

    EXPECT_EQ( 0, v.GetData().size() );
}

TEST( PVec, Map )
{
    PVec v( { 1, 2, 8 }, { { 1, "1" }, { 2, "2" }, { 8, "8" } } );

    EXPECT_EQ( "1", v.GetStrings()[0] );
    EXPECT_EQ( "2", v.GetStrings()[1] );
    EXPECT_EQ( "8", v.GetStrings()[2] );
    EXPECT_EQ( 3, v.GetStrings().size() );

    EXPECT_EQ( 0, v.GetData().size() );
}

TEST( PVec, Linspace )
{
    PVec v( 0, 2, 3 );

    EXPECT_DOUBLE_EQ( 0.0, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 1.0, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 2.0, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( PVec, LinspaceFunc )
{
    PVec v( 0, 2, 3, []( double x )
    {
        return x - 1;
    } );

    EXPECT_DOUBLE_EQ( -1.0, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 0.0, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 1.0, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( PVec, Func )
{
    PVec v( { 0, 2, 3 }, []( double x )
    {
        return x - 1;
    } );

    EXPECT_DOUBLE_EQ( -1.0, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 1.0, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 2.0, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( PVec, Arma )
{
    PVec v( arma::vec{ 0, 2, 3 } );

    EXPECT_DOUBLE_EQ( 0.0, v.GetData()[0] );
    EXPECT_DOUBLE_EQ( 2.0, v.GetData()[1] );
    EXPECT_DOUBLE_EQ( 3.0, v.GetData()[2] );
    EXPECT_EQ( 3, v.GetData().size() );

    EXPECT_EQ( 0, v.GetStrings().size() );
}

TEST( PVec, GetSizeDouble )
{
    PVec v( { 0, 2, 3, 4 } );
    EXPECT_EQ( 4, v.GetSize() );
}

TEST( PVec, GetSizeStr )
{
    PVec v( { "0", "2", "3", "4" } );
    EXPECT_EQ( 4, v.GetSize() );
}

TEST( PVec, Min )
{
    PVec v( { 0, 2, 3, 4, -2 } );
    EXPECT_DOUBLE_EQ( -2.0, v.Min() );
}

TEST( PVec, Max )
{
    PVec v( { 0, 2, 3, 4, -2 } );
    EXPECT_DOUBLE_EQ( 4.0, v.Max() );
}