#include "sciplot/sciplot.hpp"
#include <iostream>
using namespace sciplot;
// double f(double x) {
//     return sin(x);
// }

int graphics_fuck(double left_border = 0.0, double right_border = 5.0, double result = 0.0, int type = 0) {
    //creating a vector with values from 0 to pi with precision of pi/200 (?)
    Vec x = linspace(left_border, right_border, 200);
    Vec vec_for_dot = linspace(result, result, 1);
    Vec xBox = linspace(result-0.01, result+0.01, 200);
    Vec yBox = linspace(std::sin(result)-0.01, std::sin(result)+0.01, 200);
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
    plot.drawDots(vec_for_dot, std::sin(vec_for_dot)).label("extremum : "+ std::to_string(result)); 
    plot.drawBoxes(xBox, yBox)
        .fillSolid()
        .fillColor("red")
        .fillIntensity(0.5)
        .label("pointer to the extremum");
    plot.boxWidthRelative(0.3);
    
    //show & save
    //plot.show();
    if (type == 1){
        plot.save("plot_dichotomy.pdf");
    }
    else if (type == 2){
        plot.save("plot_section.pdf");
    }
    else if (type == 3){
        plot.save("plot_fib.pdf");
    }
    return 0;
}

int graphics_precision(std::map<int, std::tuple<double,double>> const &diction, int type){
    Plot plot;
    plot.xlabel("iteration");
    plot.ylabel("center");
    Vec vec_for_x, vec_for_y;
    plot.xrange(0.0, diction.size());
    plot.yrange(-12.0, 12.0); //тут надо подумать на что менять 12.0
    plot.legend()
        .atOutsideBottom()
        .displayHorizontal()
        .displayExpandWidthBy(2);
        
    
    for (auto const &pair: diction) {
        vec_for_x = linspace(pair.first, pair.first, 200);
        vec_for_y = linspace(std::get<0>(pair.second), std::get<1>(pair.second), 200);
        std::cout << std::get<0>(pair.second) << std::get<1>(pair.second) << std::endl;
        plot.drawCurve(vec_for_x, vec_for_y).label("iteration :" + std::to_string(pair.first));
            //.fillColor("red");
    }
    if (type == 1){
        plot.save("precision_dichotomy.pdf");
    }
    else if (type == 2) {
        plot.save("precision_section.pdf");
    }
    else if (type == 3){
        plot.save("precision_fib.pdf");
    }
    return 0;
}