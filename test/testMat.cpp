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

#include "helper.h"

TEST(PMat, ConstructVec)
{
    ::PMat m(std::vector< std::vector< double >> { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } });
    EXPECT_EQ(3, m.GetData().size());

    EXPECT_EQ(3, m.GetData()[0].size());
    EXPECT_DOUBLE_EQ(1, m.GetData()[0][0]);
    EXPECT_DOUBLE_EQ(2, m.GetData()[0][1]);
    EXPECT_DOUBLE_EQ(3, m.GetData()[0][2]);

    EXPECT_EQ(3, m.GetData()[1].size());
    EXPECT_DOUBLE_EQ(4, m.GetData()[1][0]);
    EXPECT_DOUBLE_EQ(5, m.GetData()[1][1]);
    EXPECT_DOUBLE_EQ(6, m.GetData()[1][2]);

    EXPECT_EQ(3, m.GetData()[2].size());
    EXPECT_DOUBLE_EQ(7, m.GetData()[2][0]);
    EXPECT_DOUBLE_EQ(8, m.GetData()[2][1]);
    EXPECT_DOUBLE_EQ(9, m.GetData()[2][2]);


    EXPECT_EQ(0, m.GetStrings().size());

    EXPECT_EQ(m.GetData().size(), m.GetSize());

    std::pair< size_t, size_t > dim = { 3, 3 };
    EXPECT_EQ(dim, m.GetDimension());
}

TEST(PMat, ConstructPVec)
{
    ::PMat m(std::vector< PVec > { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } });
    EXPECT_EQ(3, m.GetData().size());

    EXPECT_EQ(3, m.GetData()[0].size());
    EXPECT_DOUBLE_EQ(1, m.GetData()[0][0]);
    EXPECT_DOUBLE_EQ(2, m.GetData()[0][1]);
    EXPECT_DOUBLE_EQ(3, m.GetData()[0][2]);

    EXPECT_EQ(3, m.GetData()[1].size());
    EXPECT_DOUBLE_EQ(4, m.GetData()[1][0]);
    EXPECT_DOUBLE_EQ(5, m.GetData()[1][1]);
    EXPECT_DOUBLE_EQ(6, m.GetData()[1][2]);

    EXPECT_EQ(3, m.GetData()[2].size());
    EXPECT_DOUBLE_EQ(7, m.GetData()[2][0]);
    EXPECT_DOUBLE_EQ(8, m.GetData()[2][1]);
    EXPECT_DOUBLE_EQ(9, m.GetData()[2][2]);


    EXPECT_EQ(0, m.GetStrings().size());

    EXPECT_EQ(m.GetData().size(), m.GetSize());

    std::pair< size_t, size_t > dim = { 3, 3 };
    EXPECT_EQ(dim, m.GetDimension());
}

TEST(PMat, ConstructInit)
{
    ::PMat m({ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } });
    EXPECT_EQ(3, m.GetData().size());

    EXPECT_EQ(3, m.GetData()[0].size());
    EXPECT_DOUBLE_EQ(1, m.GetData()[0][0]);
    EXPECT_DOUBLE_EQ(2, m.GetData()[0][1]);
    EXPECT_DOUBLE_EQ(3, m.GetData()[0][2]);

    EXPECT_EQ(3, m.GetData()[1].size());
    EXPECT_DOUBLE_EQ(4, m.GetData()[1][0]);
    EXPECT_DOUBLE_EQ(5, m.GetData()[1][1]);
    EXPECT_DOUBLE_EQ(6, m.GetData()[1][2]);

    EXPECT_EQ(3, m.GetData()[2].size());
    EXPECT_DOUBLE_EQ(7, m.GetData()[2][0]);
    EXPECT_DOUBLE_EQ(8, m.GetData()[2][1]);
    EXPECT_DOUBLE_EQ(9, m.GetData()[2][2]);


    EXPECT_EQ(0, m.GetStrings().size());

    EXPECT_EQ(m.GetData().size(), m.GetSize());

    std::pair< size_t, size_t > dim = { 3, 3 };
    EXPECT_EQ(dim, m.GetDimension());
}

TEST(PMat, ConstructArma)
{
    ::PMat m(mat{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } });
    EXPECT_EQ(3, m.GetData().size());

    EXPECT_EQ(3, m.GetData()[0].size());
    EXPECT_DOUBLE_EQ(1, m.GetData()[0][0]);
    EXPECT_DOUBLE_EQ(2, m.GetData()[0][1]);
    EXPECT_DOUBLE_EQ(3, m.GetData()[0][2]);

    EXPECT_EQ(3, m.GetData()[1].size());
    EXPECT_DOUBLE_EQ(4, m.GetData()[1][0]);
    EXPECT_DOUBLE_EQ(5, m.GetData()[1][1]);
    EXPECT_DOUBLE_EQ(6, m.GetData()[1][2]);

    EXPECT_EQ(3, m.GetData()[2].size());
    EXPECT_DOUBLE_EQ(7, m.GetData()[2][0]);
    EXPECT_DOUBLE_EQ(8, m.GetData()[2][1]);
    EXPECT_DOUBLE_EQ(9, m.GetData()[2][2]);


    EXPECT_EQ(0, m.GetStrings().size());

    EXPECT_EQ(m.GetData().size(), m.GetSize());

    std::pair< size_t, size_t > dim = { 3, 3 };
    EXPECT_EQ(dim, m.GetDimension());
}

TEST(PMat, ConstructArma2)
{
    ::PMat m(mat{ { 1, 2, 3 }, { 4, 5, 6 } });
    EXPECT_EQ(2, m.GetData().size());

    EXPECT_EQ(3, m.GetData()[0].size());
    EXPECT_DOUBLE_EQ(1, m.GetData()[0][0]);
    EXPECT_DOUBLE_EQ(2, m.GetData()[0][1]);
    EXPECT_DOUBLE_EQ(3, m.GetData()[0][2]);

    EXPECT_EQ(3, m.GetData()[1].size());
    EXPECT_DOUBLE_EQ(4, m.GetData()[1][0]);
    EXPECT_DOUBLE_EQ(5, m.GetData()[1][1]);
}

TEST(PMat, ConstructStr)
{
    ::PMat m({ { "1", "2", "3" }, { "4", "5", "6" }, { "7", "8", "9" } });
    EXPECT_EQ(3, m.GetStrings().size());

    EXPECT_EQ(3, m.GetStrings()[0].size());
    EXPECT_EQ("1", m.GetStrings()[0][0]);
    EXPECT_EQ("2", m.GetStrings()[0][1]);
    EXPECT_EQ("3", m.GetStrings()[0][2]);

    EXPECT_EQ(3, m.GetStrings()[1].size());
    EXPECT_EQ("4", m.GetStrings()[1][0]);
    EXPECT_EQ("5", m.GetStrings()[1][1]);
    EXPECT_EQ("6", m.GetStrings()[1][2]);

    EXPECT_EQ(3, m.GetStrings()[2].size());
    EXPECT_EQ("7", m.GetStrings()[2][0]);
    EXPECT_EQ("8", m.GetStrings()[2][1]);
    EXPECT_EQ("9", m.GetStrings()[2][2]);


    EXPECT_EQ(0, m.GetData().size());

    EXPECT_EQ(m.GetStrings().size(), m.GetSize());

    std::pair< size_t, size_t > dim = { 3, 3 };
    EXPECT_EQ(dim, m.GetDimension());
}

TEST(PMat, ConstructMap)
{
    ::PMat m({ { 1, 2, 3 }, { 1, 2, 3 }, { 1, 2, 3 } },
    { { 1, "1" }, { 2, "2" }, { 3, "3" } });
    EXPECT_EQ(3, m.GetStrings().size());

    EXPECT_EQ(3, m.GetStrings()[0].size());
    EXPECT_EQ("1", m.GetStrings()[0][0]);
    EXPECT_EQ("2", m.GetStrings()[0][1]);
    EXPECT_EQ("3", m.GetStrings()[0][2]);

    EXPECT_EQ(3, m.GetStrings()[1].size());
    EXPECT_EQ("1", m.GetStrings()[1][0]);
    EXPECT_EQ("2", m.GetStrings()[1][1]);
    EXPECT_EQ("3", m.GetStrings()[1][2]);

    EXPECT_EQ(3, m.GetStrings()[2].size());
    EXPECT_EQ("1", m.GetStrings()[2][0]);
    EXPECT_EQ("2", m.GetStrings()[2][1]);
    EXPECT_EQ("3", m.GetStrings()[2][2]);

    EXPECT_EQ(0, m.GetData().size());

    EXPECT_EQ(m.GetStrings().size(), m.GetSize());

    std::pair< size_t, size_t > dim = { 3, 3 };
    EXPECT_EQ(dim, m.GetDimension());
}

template< typename tT >
void PreventOptimisation(tT func)
{
    func();
}

// won't work due to optimisation
#ifdef DEBUG

TEST(PMat, ConstructVecCheckDim)
{
    EXPECT_DEATH(PreventOptimisation([]()
    {
        volatile ::PMat m(std::vector< std::vector< double >> { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8 } });
    }), "== size");
}

TEST(PMat, ConstructInitCheckDim)
{
    EXPECT_DEATH(PreventOptimisation([]()
    {
        volatile ::PMat m({ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8 } });
    }), "== size");
}

TEST(PMat, ConstructStrCheckDim)
{
    EXPECT_DEATH(PreventOptimisation([]()
    {
        volatile ::PMat m({ { "1", "2", "3" }, { "4", "5", "6" }, { "7", "8" } });
    }), "== size");
}

TEST(PMat, ConstructMapCheckDim)
{
    EXPECT_DEATH(PreventOptimisation([]()
    {
        volatile ::PMat m({ {1, 2, 3}, {1, 2, 3}, {1, 2} },
        { {1, "1"}, {2, "2"}, {3, "3"} });
    }), "== size");
}

#endif