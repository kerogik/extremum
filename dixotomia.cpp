#include <iostream>
#include <math.h>

double f(double x){
    return sin(x);
}
double dixot(double a,double b,double eps,int l) {
    double c;
    if (l == 1){
        while (fabs(b - a) > eps) {
            c = (a + b) / 2;
            if (f(c + eps) < f(c - eps)) {
                b = c;
            } else {
                a = c;
            }
        }
    }else{
        while (fabs(b - a) > eps) {
            c = (a + b) / 2;
            if (f(c + eps) > f(c - eps)) {
                b = c;
            } else {
                a = c;
            }
        }
    }
    return c;
}
// int main() {
//     double a,b,eps,l;
//     std::cout << "Введите значение левой границы" << std::endl;
//     std::cin >> a;
//     std::cout << "Введите значение правой границы" << std::endl;
//     std::cin >> b;
//     std::cout << "Введите значение погрешности" << std::endl;
//     std::cin >>eps;
//     std::cout << "Что нужно найти? \n 1-максимум \n 2-минимум" << std::endl;
//     std::cin >>l;
//     std::cout << dixot(a,b,eps,l) << std::endl;
// }

