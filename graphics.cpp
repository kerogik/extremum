#include "sciplot/sciplot.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace sciplot;
// double f(double x) {
//     return sin(x);
// }
typedef std::tuple<std::tuple<double, double>, std::map<int, std::tuple<double, double>>> FuncOutput;

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

int graphics_precision(std::map<int, std::tuple<double,double>> const &diction, int type, double left_border, double right_border){
    Plot plot;
    plot.xlabel("iteration");
    plot.ylabel("center");
    Vec vec_for_x, vec_for_y;
    plot.xrange(0.0, diction.size());
    plot.yrange(left_border, right_border); //тут надо подумать на что менять 12.0
    plot.legend()
            .atOutsideBottom()
            .displayHorizontal()
            .displayExpandWidthBy(2);


    for (auto const &pair: diction) {
        vec_for_x = linspace(pair.first, pair.first, 200);
        vec_for_y = linspace(std::get<0>(pair.second), std::get<1>(pair.second), 200);
        //std::cout << std::get<0>(pair.second) << std::get<1>(pair.second) << std::endl;
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

FuncOutput dixot(double left_border,double right_border,double eps,int l, std::string function);
FuncOutput golden_section(int word, double right_border, double left_border, double e, std::string function);
FuncOutput fib(double a, double b,double l, double eps);

int draw_cycle_through_precision(double left_border, double right_border, int choice, Plot plot_for_iter_precision, double it, std::string function) {
    int current_it_size;
    if (choice == 1) {
        FuncOutput cycle_of_func = dixot(left_border,right_border, 1 / pow(10,it), choice, function);
        current_it_size = size(std::get<1>(cycle_of_func));
    }
    else if (choice == 2){
        FuncOutput cycle_of_func = golden_section(choice, right_border, left_border, 1 / pow(10,it), function);
        current_it_size = size(std::get<1>(cycle_of_func));
    }
    else if (choice == 3){
        FuncOutput cycle_of_func = fib(left_border, right_border, 0.001, 1 / pow(10,it)); //what is l and what is eps
        current_it_size = size(std::get<1>(cycle_of_func));
    }
    return current_it_size;
}

int graphics_iter_precision(double left_border,double right_border,int choice, std::string function) {
    Plot plot_for_iter_precision;
    int curr_iter_size;
    std::vector<double> x;
    std::vector<int> y;
    for (double i=0.0; i<10;i+=0.1){
        curr_iter_size = draw_cycle_through_precision(left_border, right_border, choice, plot_for_iter_precision, i, function);
        y.push_back(curr_iter_size);
        x.push_back(1/pow(10,i+1));
        std::cout << i << " " << 1 / pow(10,i+1) << " " << curr_iter_size << std::endl;
    }
    plot_for_iter_precision.size(400,400);
    plot_for_iter_precision.xrange(0.0, 0.1);
    plot_for_iter_precision.yrange(0.0, *max_element(y.begin(), y.end()));
    plot_for_iter_precision.ylabel("iterations");
    plot_for_iter_precision.xlabel("precision");
    plot_for_iter_precision.drawCurve(x, y).label("iterations-precision dependency");
    if (choice == 1){
        plot_for_iter_precision.save("iteration-precision-dichotomy.pdf");
    }
    else if (choice == 2){
        plot_for_iter_precision.save("iteration-precision-section.pdf");
    }
    else if (choice == 3){
        plot_for_iter_precision.save("iteration-precision-fib.pdf");
    }
    return 0;
}