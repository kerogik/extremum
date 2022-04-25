#include "graphics.cpp"
#include "dixotomia.cpp"
#include <iostream>
#include <windows.h>

int main(int argc, char **argv) {
    SetConsoleOutputCP(CP_UTF8);

    double left_border,right_border,eps,choice;
    std::cout << "Введите значение левой границы" << std::endl;
    std::cin >> left_border;
    std::cout << "Введите значение правой границы" << std::endl;
    std::cin >> right_border;
    std::cout << "Введите значение погрешности" << std::endl;
    std::cin >>eps;
    std::cout << "Что нужно найти? \n 1-максимум \n 2-минимум" << std::endl;
    std::cin >>choice;
    double result_dichotomy = dixot(left_border,right_border,eps,choice);
    std::cout << result_dichotomy << std::endl;
    graphics(left_border, right_border, result_dichotomy);
}
