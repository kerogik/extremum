#include <sciplot/sciplot.hpp>
using namespace sciplot;

int graphics() {
    //creating a vector with values from 0 to pi with precision of pi/200 (?)
    Vec x = linspace(0.0, PI, 200);
    
    //plot obj
    Plot plot;

    //set x and y labels
    plot.xlabel("x");
    plot.ylabel("y");

    //set ranges
    plot.xrange(0.0, PI);
    plot.yrange(0.0, 1);
    
    //legend
    plot.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);

    //plot sinx
    plot.drawCurve(x, std::sin(x)).label("sinx");
    
    //show
    plot.show();
}