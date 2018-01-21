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

#include "plot/heatMapPlot.h"
#include "plot/subPlots.h"

PLOTLIB_INLINE SubPlots::SubPlots(uint32_t rows, uint32_t columns) : mPlotCount(0)
{
    mStream << "fig, axn = plt.subplots(" << rows << "," << columns <<
            ", sharex=True, sharey=True, squeeze=True, subplot_kw={'axisbg': 'w'})\n"
            << "fig.subplots_adjust(hspace=0.5,wspace=0.5)\n";
}

PLOTLIB_INLINE std::string SubPlots::ToString()
{
    return mStream.str() + "\n" + mPlots.str() + "\nfig.tight_layout(rect=[0, 0, .85, .9],pad=0.1)\n";
}

PLOTLIB_INLINE void SubPlots::AddHeatMapPlot(HeatMapPlot &plot)
{
    if (mPlotCount == 0)
    {
        mStream << "cbar_ax = fig.add_axes([.86, .05, .03, .9])\n"
                << "ax_cycler = itertools.cycle(axn.flat)\n";
        plot.mStream << ", cbar_ax= cbar_ax";
    }
    else
    {
        plot.ColourBar(false);
    }

    plot.mStream << ", ax=next(ax_cycler)";
    mPlots << "\n" << plot.ToString() << "\n";
    ++mPlotCount;
}
