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
    
    std::cout << "Введите значение левой границы" << std::endl;
    std::cin >> left_border;
    std::cout << "Введите значение правой границы" << std::endl;
    std::cin >> right_border;
    std::cout << "Введите значение погрешности" << std::endl;
    std::cin >> eps;
    std::cout << "Что нужно найти? \n 1-максимум \n 2-минимум" << std::endl;
    std::cin >> choice;
    double result_dichotomy = dixot(left_border, right_border, eps, choice);
    double result_section = golden_section(choice, right_border, left_border, eps);
    std::cout << "Дихотомия:" << result_dichotomy << std::endl;
    std::cout << "Золотое Сечение:" << result_section << std::endl;
    std::cout << "Введите интервал для фибоначчи (обычно 0.01)" << std::endl;
    std::cin >> l;
    double result_fib = fib(left_border, right_border, l, eps);
    std::cout << "Фибоначчи:" << result_fib << std::endl;
    graphics(left_border, right_border, result_dichotomy, 1);
    graphics(left_border, right_border, result_section, 2);
    graphics(left_border, right_border, result_fib, 3);
}
