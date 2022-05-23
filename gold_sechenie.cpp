//
// Created by smyat on 19.05.2022.
//

#include <iostream>
#include <cmath>
#include <map>
#include <tuple>

typedef std::map<int, double> ForGraph;

double f2(double x)
{
// Здесь будет вычисление значения функции
    double answer = sin(x);
    return answer;
}

// Переменные a и b будут зависеть от выбранного интервала, так как они будут границами
std::tuple<double, ForGraph> golden_section(int word, double right_border, double left_border, double e)
{
    ForGraph dict;
    double t = (sqrt(5) + 1) / 2;
    double x_1 = right_border - (right_border - left_border) / t;;
    double x_2 = left_border +  (right_border - left_border) / t;
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
            dict.insert(std::make_pair(counter, (x_1 + x_2)*0.5));
        }
        std::cout <<"Количество итераций(сечение):" << counter << std::endl << "Максимум(сечение):" << (x_2 + x_1)*0.5 << std::endl;
    }
    else {
        while (e < fabs(right_border - left_border))
        {
            counter += 1;
            //std::cout << " " << f2(x_1) << " "<< f2(x_2)<<std::endl; //Чисто для проверка, строка необязательна
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
            dict.insert(std::make_pair(counter, (x_1 + x_2)*0.5));
        }
        //std::cout << x_2<< x_1;
        std::cout <<"Количество итераций(сечение):" << counter << std::endl << "Минимум(сечение):" << (x_2 + x_1)*0.5 << std::endl;
    }
    //std::cout <<"Количество итераций(сечение):" << counter << std::endl << "Минимум(сечение):" << (x_2 + x_1)*0.5 << std::endl;
    return std::make_tuple((x_1 + x_2)*0.5, dict);
}