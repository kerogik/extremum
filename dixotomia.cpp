#include <math.h>
#include <map>
#include <tuple>

double f1(double x){
    return sin(x);
}


typedef std::tuple<std::tuple<double, double>, std::map<int, std::tuple<double, double>>> FuncOutput;

FuncOutput dixot(double left_border,double right_border,double eps,int l) {
    double center;
    typedef std::map<int, std::tuple<double, double>> ForGraph;
    ForGraph dict;
    int counter = 0;
    std::tuple<double, double> pre_interval;
    if (l == 1){
        while (fabs(right_border - left_border) > eps) {
            center = (left_border + right_border) / 2;
            if (f1(center + eps) < f1(center - eps)) {
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
            if (f1(center + eps) > f1(center - eps)) {
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

