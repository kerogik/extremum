#include "sciplot/sciplot.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace sciplot;

double calculate(std::string &str, double chislo);
double expression(std::string &, unsigned &, double chislo);
double multiply_divide(std::string &, unsigned &, double chislo);
double sign(std::string &, unsigned &, double chislo);
double brackets(std::string &, unsigned &, double chislo);
double number(std::string &, unsigned &, double chislo);
double identificator(std::string &, unsigned &, double chislo);
double function(std::string &, std::string &, unsigned &, double chislo);

double f(std::string function, double chislo) {
    double y;
    y = calculate(function, chislo);
    return y;
}

typedef std::tuple<std::tuple<double, double>, std::map<int, std::tuple<double, double>>> FuncOutput;

int graphics_func(double left_border, double right_border, double result, int type, std::string function, std::map<int, std::tuple<double,double>> const &diction) {
    
    Vec x = linspace(left_border, right_border, 200);
    Vec xBox = linspace(result, result, 1);
    Vec yBox = linspace(f(function, result), f(function, result), 1);
    Vec ZeroBox = linspace(0.0,0.0,1);
    Plot plot1, plot2;
    
    std::vector colors = {"yellow", "orange", "coral", "red", "brown", "navy", "black"};
    int num_color = 0;
    std::vector<double> y;
    for (int i=0;i<200;i++){
        y.push_back(f(function,x[i]));
    }
    double fmax = *std::max_element(y.begin(), y.end());
    double fmin = *std::min_element(y.begin(), y.end());
    double absmax = std::max(fabs(fmax),fabs(fmin));

    //set plot1 size
    plot1.size(600, 600);
    //set x and y labels
    plot1.xlabel("x");
    plot1.ylabel("y");

    //set ranges
    plot1.xrange(left_border, right_border);
    plot1.yrange(-absmax, absmax);
    
    //legend
    plot1.legend()
            .atOutsideBottom()
            .displayHorizontal();

    plot1.drawCurve(x, y).label(function).lineColor("green");

    ////////////////////////////////////////////////////////////////////////////////////////
    
    //set plot2 size
    plot2.size(600, 600);
    //set x and y labels
    plot2.xlabel("x");
    plot2.ylabel("y");

    //set ranges
    plot2.xrange(left_border, right_border);
    plot2.yrange(-absmax, absmax);
    
    //legend
    plot2.legend()
            .atOutsideBottom()
            .displayHorizontal();

    plot2.drawCurve(x, y).label(function).lineColor("green");

    //diagonals
    // Vec x_lined, y_lined;
    // for (auto const &pair: diction) {
    //     x_lined = linspace(std::get<0>(pair.second), std::get<1>(pair.second), 200);
    //     y_lined = linspace(f(function, std::get<0>(pair.second)), f(function, std::get<1>(pair.second)), 200);
    //     plot1.drawCurve(x_lined, y_lined).label("iteration :" + std::to_string(pair.first)).lineColor(colors[num_color % size(colors)]);
    //     num_color +=1;
    // }
    
    Vec vec_for_x1, vec_for_x2, vec_for_y1, vec_for_y2;
    for (auto const &pair: diction) {
        vec_for_x1 = linspace(std::get<0>(pair.second), std::get<0>(pair.second), 200);
        //vec_for_y1 = linspace(f(function, std::get<0>(pair.second)) - 0.1, f(function, std::get<0>(pair.second)) + 0.1, 200);
        vec_for_y1 = linspace(-absmax, absmax, 200);
        plot2.drawCurve(vec_for_x1, vec_for_y1).label("iteration :" + std::to_string(pair.first)).lineColor(colors[num_color % size(colors)]);
        vec_for_x2 = linspace(std::get<1>(pair.second), std::get<1>(pair.second), 200);
        //vec_for_y2 = linspace(f(function, std::get<1>(pair.second)) - 0.1, f(function, std::get<1>(pair.second)) + 0.1, 200);
        vec_for_y2 = linspace(-absmax, absmax, 200);
        plot2.drawCurve(vec_for_x2, vec_for_y2).label("iteration :" + std::to_string(pair.first)).lineColor(colors[num_color % size(colors)]);
        num_color += 1;
    }

    plot1.drawCurveWithPoints(xBox, ZeroBox).label("extremum : "+ std::to_string(result));
    plot1.drawCurveWithPoints(xBox, yBox).label("pointer to the extremum");

    plot2.drawCurveWithPoints(xBox, ZeroBox).label("extremum : "+ std::to_string(result));
    plot2.drawCurveWithPoints(xBox, yBox).label("pointer to the extremum");

    Figure plots = {{ plot1, plot2 }};
    plots.size(1200,600);
    plots.title("Plots");
    plots.palette("dark2");
    
    if (type == 1){
        // plot1.save("plot_dichotomy.pdf");
        // plots.save("plots_dichotomy-test.pdf");
        plots.save("plot_dichotomy.pdf");
    }
    else if (type == 2){
        // plot1.save("plot_section.pdf");
        // plots.save("plots_section-test.pdf");
        plots.save("plot_section.pdf");
    }
    else if (type == 3){
        // plot1.save("plot_fib.pdf");
        // plots.save("plots_fib-test.pdf");
        plots.save("plot_fib.pdf");
    }
    return 0;
}

int graphics_precision(std::map<int, std::tuple<double,double>> const &diction, int type, double left_border, double right_border){
    
    Plot plot1;
    plot1.xlabel("iteration");
    plot1.ylabel("center");
    Vec vec_for_x, vec_for_y;
    plot1.xrange(0.0, diction.size());
    plot1.yrange(left_border, right_border); 
    plot1.legend()
            .atOutsideBottom()
            .displayHorizontal()
            .displayExpandWidthBy(2);

    for (auto const &pair: diction) {
        vec_for_x = linspace(pair.first, pair.first, 200);
        vec_for_y = linspace(std::get<0>(pair.second), std::get<1>(pair.second), 200);
        plot1.drawCurve(vec_for_x, vec_for_y).label("iteration :" + std::to_string(pair.first));
    }

    if (type == 1){
        plot1.save("precision_dichotomy.pdf");
    }
    else if (type == 2) {
        plot1.save("precision_section.pdf");
    }
    else if (type == 3){
        plot1.save("precision_fib.pdf");
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