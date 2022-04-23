#include <sciplot/sciplot.hpp>
using namespace sciplot;

double f(double x) {
    return sin(x);
}

int graphics(double left_border = 0.0, double right_border = 5.0, double result_dichotomy = 0.0) {
    //creating a vector with values from 0 to pi with precision of pi/200 (?)
    Vec x = linspace(left_border, right_border, 200);
    Vec vec_for_dot = linspace(result_dichotomy, result_dichotomy, 1);
    Vec xBox = linspace(result_dichotomy-0.01, result_dichotomy+0.01, 200);
    Vec yBox = linspace(std::sin(result_dichotomy)-0.01, std::sin(result_dichotomy)+0.01, 200);
    //plot obj
    Plot plot;

    //set x and y labels
    plot.xlabel("x");
    plot.ylabel("y");

    //set ranges
    plot.xrange(left_border, right_border);
    plot.yrange(-1.5, 1.5);
    
    //legend
    plot.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);

    //plot sinx
    plot.drawCurve(x, std::sin(x)).label("sin(x)");
    plot.drawDots(vec_for_dot, std::sin(vec_for_dot)).label("extremum : "+ std::to_string(result_dichotomy)); 
    plot.drawBoxes(xBox, yBox)
        .fillSolid()
        .fillColor("red")
        .fillIntensity(0.5)
        .label("pointer to  the dichotomy extremum");
    plot.boxWidthRelative(0.3);
    //show
    plot.show();
    return 0;
}