#include <math.h>
#include <map>
#include <tuple>
#include <string>



typedef std::tuple<std::tuple<double, double>, std::map<int, std::tuple<double, double>>> FuncOutput;
double calculate(std::string &str, double chislo);
double expression(std::string &, unsigned &, double chislo);
double multiply_divide(std::string &, unsigned &, double chislo);
double sign(std::string &, unsigned &, double chislo);
double brackets(std::string &, unsigned &, double chislo);
double number(std::string &, unsigned &, double chislo);
double identificator(std::string &, unsigned &, double chislo);
double function(std::string &, std::string &, unsigned &, double chislo);

FuncOutput dixot(double left_border,double right_border,double eps,int l, std::string function) {
    double center, check1, check2;
    typedef std::map<int, std::tuple<double, double>> ForGraph;
    ForGraph dict;
    int counter = 0;
    std::tuple<double, double> pre_interval;
    if (l == 1){
        while (fabs(right_border - left_border) > eps) {
            center = (left_border + right_border) / 2;
            check1= calculate(function, center + eps);
            check2= calculate(function, center - eps);
            if (check1 < check2) {
                right_border = center;
            } else {
                left_border = center;
            }
            counter +=1;
            pre_interval = std::make_tuple(left_border, right_border);
            dict.insert(std::make_pair(counter, pre_interval));
        }
    }else{
        while (fabs(right_border - left_border) > eps) {
            center = (left_border + right_border) / 2;
            check1= calculate(function, center + eps);
            check2= calculate(function, center - eps);
            if (check1 > check2) {
                right_border = center;
            } else {
                left_border = center;
            }
            counter +=1;
            pre_interval = std::make_tuple(left_border, right_border);
            dict.insert(std::make_pair(counter, pre_interval));
        }
    }
    center = (left_border + right_border) / 2;
    std::tuple<double, double> interval = std::make_tuple(left_border, right_border);
    return std::make_tuple(interval, dict);
}