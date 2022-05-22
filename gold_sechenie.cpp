//
// Created by smyat on 19.05.2022.
//

#include <iostream>
#include <cmath>
//#include "windows.h"

//using namespace std;

// sin(x) на отрезке [0,4]
double f2(double x)
{
// Здесь будет вычисление значения функции
    double answer = sin(x);
    return answer;
}
// Переменные a и b будут зависеть от выбранного интервала, так как они будут границами
double golden_section(int word, double right_border, double left_border, double e)
{
    //SetConsoleOutputCP(CP_UTF8);
    //int word;
    //double right_border = 4;
    //double left_border = 0;
    //double e;
    // std::cout << "Ищем локальный минимум или максимум? Если вам нужен максимум введите цифру 1, иначе введите цифру 0";
    // std::cin >> word;
    // std::cout << "Введите левую границу";
    // std::cin >> left_border;
    // std::cout << "Введите правую границу";
    // std::cin >> right_border;
    // std::cout << "Введите погрешность";
    // std::cin >> e;
    double t = (sqrt(5) - 1) / 2;
    double x_1 = right_border - t * (right_border - left_border);
    double x_2 = left_border + t * (right_border - left_border);
    int counter = 0;
    if (word == 1) {
        while (e < fabs(right_border - left_border))
        {
            counter += 1;
            x_1 = right_border - (right_border - left_border) / t;
            x_2 = left_border +  (right_border - left_border) / t;
            if (f2(x_1) <= f2(x_2))
            {
                left_border = x_1;
            }
            else
            {
                right_border = x_2;
            }
        }
        std::cout <<"Количество итераций(сечение):" << counter << std::endl << "Максимум(сечение):" << (x_2 + x_1)*0.5 << std::endl;
    }
    else if (word == 2) {
        while (e < fabs(right_border - left_border))
        {
            counter += 1;
            x_1 = right_border - (right_border - left_border) / t;
            x_2 = left_border +  (right_border - left_border) / t;
            if (f2(x_1) >= f2(x_2))
            {
                left_border = x_1;
            }
            else
            {
                right_border = x_2;
            }
        }
        std::cout <<"Количество итераций(сечение):" << counter << std::endl << "Минимум(сечение):" << (x_2 + x_1)*0.5 << std::endl;
    }
    return (x_2 + x_1)*0.5;
}