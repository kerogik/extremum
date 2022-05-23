#include <math.h>
#include <map>
#include <tuple>
double f1(double x){
    return sin(x);
}
typedef std::map<int, double> ForGraph;

std::tuple<double, ForGraph> dixot(double left_border,double right_border,double eps,int l) {
    double center;
    ForGraph dict;
    int counter = 0;
    if (l == 1){
        while (fabs(right_border - left_border) > eps) {
            center = (left_border + right_border) / 2;
            if (f1(center + eps) < f1(center - eps)) {
                right_border = center;
            } else {
                left_border = center;
            }
            counter +=1;
            dict.insert(std::make_pair(counter, center));
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
            dict.insert(std::make_pair(counter, center));
        }
    }
    center = (left_border + right_border) / 2;
    return std::make_tuple(center, dict);
}

