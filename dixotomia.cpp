#include <iostream>
#include <math.h>

double f(double x){
    return sin(x);
}
double dixot(double left_border,double right_border,double eps,int l) {
    double center;
    if (l == 1){
        while (fabs(right_border - left_border) > eps) {
            center = (left_border + right_border) / 2;
            if (f(center + eps) < f(center - eps)) {
                right_border = center;
            } else {
                left_border = center;
            }
        }
    }else{
        while (fabs(right_border - left_border) > eps) {
            center = (left_border + right_border) / 2;
            if (f(center + eps) > f(center - eps)) {
                right_border = center;
            } else {
                left_border = center;
            }
        }
    }
    center = (left_border + right_border) / 2;
    return center;
}

