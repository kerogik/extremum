#include "graphics.cpp"
#include "dixotomia.cpp"
#include "gold_sechenie.cpp"
#include "fib.cpp"
#include <iostream>

#if defined __has_include
#   if __has_include (<windows.h>)
#       include <windows.h>
#   endif
#endif


int main(int argc, char **argv) {
    
    #if defined __has_include
    #   if __has_include (<windows.h>)
    #       define INCLUDED true 
    #   else
    #       define INCLUDED false
    #   endif
    #endif 

    #if INCLUDED 
        SetConsoleOutputCP(CP_UTF8);
    #endif

    double left_border,right_border,eps,choice,l;
    typedef std::tuple<std::tuple<double, double>, std::map<int, std::tuple<double, double>>> FuncOutput;
    
    std::cout << "Введите значение левой границы" << std::endl;
    std::cin >> left_border;
    std::cout << "Введите значение правой границы" << std::endl;
    std::cin >> right_border;
    std::cout << "Введите значение погрешности" << std::endl;
    std::cin >> eps;
    std::cout << "Что нужно найти? \n 1-максимум \n 2-минимум" << std::endl;
    std::cin >> choice;
    FuncOutput result_dichotomy = dixot(left_border, right_border, eps, choice);
    FuncOutput result_section = golden_section(choice, right_border, left_border, eps);
    std::cout << "Дихотомия:" << (std::get<0>(std::get<0>(result_dichotomy))+std::get<1>(std::get<0>(result_dichotomy))) / 2 << std::endl;
    std::cout << "Золотое Сечение:" << (std::get<0>(std::get<0>(result_section))+std::get<1>(std::get<0>(result_section))) / 2 << std::endl;
    std::cout << "Введите интервал для фибоначчи (обычно 0.01)" << std::endl;
    std::cin >> l;
    FuncOutput result_fib = fib(left_border, right_border, l, eps);
    std::cout << "Фибоначчи:" << (std::get<0>(std::get<0>(result_fib))+std::get<1>(std::get<0>(result_fib))) / 2 << std::endl;
    graphics_fuck(left_border, right_border, std::get<0>(std::get<0>(result_dichotomy)), 1);
    graphics_fuck(left_border, right_border, std::get<0>(std::get<0>(result_section)), 2);
    graphics_fuck(left_border, right_border, std::get<0>(std::get<0>(result_fib)), 3);
    graphics_precision(std::get<1>(result_dichotomy), 1);
    graphics_precision(std::get<1>(result_section), 2);
    graphics_precision(std::get<1>(result_fib), 3);
    graphics_iter_precision(left_border, right_border, 1); //dichotomy
    graphics_iter_precision(left_border, right_border, 2); //section
    graphics_iter_precision(left_border, right_border, 3); //fib
    return 0;
}

