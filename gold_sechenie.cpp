//
// Created by smyat on 19.05.2022.
//

#include <iostream>
#include <cmath>
#include <map>
#include <tuple>
#include <string>

double calculate(std::string &str, double chislo);
double expression(std::string &, unsigned &, double chislo);
double multiply_divide(std::string &, unsigned &, double chislo);
double sign(std::string &, unsigned &, double chislo);
double brackets(std::string &, unsigned &, double chislo);
double number(std::string &, unsigned &, double chislo);
double identificator(std::string &, unsigned &, double chislo);
double function(std::string &, std::string &, unsigned &, double chislo);

typedef std::tuple<std::tuple<double, double>, std::map<int, std::tuple<double, double>>> FuncOutput;



// Переменные a и b будут зависеть от выбранного интервала, так как они будут границами
FuncOutput golden_section(int word, double right_border, double left_border, double e, std::string function)
{   
    typedef std::map<int, std::tuple<double, double>> ForGraph;
    ForGraph dict;
    double t = (sqrt(5) + 1) / 2;
    double x_1 = right_border - (right_border - left_border) / t;
    double x_2 = left_border +  (right_border - left_border) / t;
    int counter = 0;
    double center;
    std::tuple<double, double> pre_interval;

    if (word == 1) {
        while (e < fabs(right_border - left_border))
        {
            counter += 1;
            x_1 = right_border - (right_border - left_border) / t;
            x_2 = left_border +  (right_border - left_border) / t;
            if (calculate(function,x_1) <= calculate(function,x_2))
            {
                left_border = x_1;
            }
            else
            {
                right_border = x_2;
            }
            pre_interval = std::make_tuple(left_border, right_border);
            dict.insert(std::make_pair(counter, pre_interval));
        }
        //std::cout <<"Количество итераций(сечение):" << counter << std::endl << "Максимум(сечение):" << (x_2 + x_1)*0.5 << std::endl;
    }
    else {
        while (e < fabs(right_border - left_border))
        {
            counter += 1;
            x_1 = right_border - (right_border - left_border) / t;
            x_2 = left_border +  (right_border - left_border) / t;
            if (calculate(function,x_1) >= calculate(function,x_2))
            {
                left_border = x_1;
            }
            else
            {
                right_border = x_2;
            }
            pre_interval = std::make_tuple(left_border, right_border);
            dict.insert(std::make_pair(counter, pre_interval));
        }
        
        //std::cout <<"Количество итераций(сечение):" << counter << std::endl << "Минимум(сечение):" << (x_2 + x_1)*0.5 << std::endl;
    }
    center = (left_border + right_border) / 2;
    std::tuple<double, double> interval = std::make_tuple(left_border, right_border);
    return std::make_tuple(interval, dict);
}