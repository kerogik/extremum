#include "sciplot/sciplot.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace sciplot;

double calculate(std::string &str, double chislo);
double expr(std::string &, unsigned &, double chislo);
double term(std::string &, unsigned &, double chislo);
double factor(std::string &, unsigned &, double chislo);
double base(std::string &, unsigned &, double chislo);
double number(std::string &, unsigned &, double chislo);
double identifier(std::string &, unsigned &, double chislo);
double function(std::string &, std::string &, unsigned &, double chislo);

double f(std::string function, double chislo) {
    double y;
    y = calculate(function, chislo);
    return y;
}

typedef std::tuple<std::tuple<double, double>, std::map<int, std::tuple<double, double>>> FuncOutput;

int graphics_func(double left_border, double right_border, double result, int type, std::string function ) {
    //creating a vector with values from 0 to pi with precision of pi/200 (?)
    Vec x = linspace(left_border, right_border, 200);
    Vec vec_for_dot = linspace(result, result, 1);
    Vec xBox = linspace(result, result, 1);
    Vec yBox = linspace(f(function, result), f(function, result), 1);
    Vec ZeroBox = linspace(0.0,0.0,1);
    Plot plot;
    std::vector<double> y;
    for (int i=0;i<200;i++){
        y.push_back(f(function,x[i]));
    }
    //set x and y labels
    plot.xlabel("x");
    plot.ylabel("y");

    //set ranges
    plot.xrange(left_border, right_border);
    plot.yrange(f(function,left_border), f(function,right_border));

    //legend
    plot.legend()
            .atOutsideBottom()
            .displayHorizontal()
            .displayExpandWidthBy(2);

    //plot funcs
    plot.drawCurve(x, y).label(function);
    plot.drawCurveWithPoints(xBox, ZeroBox).label("extremum : "+ std::to_string(result));
    plot.drawCurveWithPoints(xBox, yBox).label("pointer to the extremum");
    plot.boxWidthRelative(0.3);

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
    plot.yrange(left_border, right_border); 
    plot.legend()
            .atOutsideBottom()
            .displayHorizontal()
            .displayExpandWidthBy(2);

    for (auto const &pair: diction) {
        vec_for_x = linspace(pair.first, pair.first, 200);
        vec_for_y = linspace(std::get<0>(pair.second), std::get<1>(pair.second), 200);
        plot.drawCurve(vec_for_x, vec_for_y).label("iteration :" + std::to_string(pair.first));
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
FuncOutput fib(double a, double b,double l, double eps, std::string function);

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
        FuncOutput cycle_of_func = fib(left_border, right_border, 0.001, 1 / pow(10,it),function); //what is l and what is eps
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