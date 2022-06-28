#include <vector>
#include <cmath>
#include <map>
#include <tuple>
#include <string>

typedef std::tuple<std::tuple<double, double>, std::map<int, std::tuple<double, double>>> FuncOutput;
double calculate(std::string &str, double chislo);
double expression(std::string &, unsigned &, double chislo);
double multiply_divide(std::string &, unsigned &, double chislo);
double sign(std::string &, unsigned &, double chislo);
double brackets(std::string &, unsigned &, double chislo);
double number(std::string &, unsigned &, double chislo);
double identificator(std::string &, unsigned &, double chislo);
double function(std::string &, std::string &, unsigned &, double chislo);

std::vector<int> masfib(double l, double b, double a)
{
    std::vector<int> array;
    array.push_back(1);
    array.push_back(1);
    int fib;
    while (array[i] <= ((b - a) / l))
    {
        i++;
        fib = array[i - 1] + array[i - 2];
        array.push_back(fib);
    }
    return array;
}


FuncOutput fib(double a, double b,double l, double eps, std::string function)
{
    
    typedef std::map<int, std::tuple<double, double>> ForGraph;
    ForGraph dict;
    std::vector<int> array = masfib(l, b, a);
    int n = array.size() - 1;
    double penpenultimateelement =array[n-2];
    double penultimateelement =array[n-1];
    double lastelement =array[n];
    float x = (a + (penpenultimateelement / lastelement) * (b - a));
    float y = (a + (penultimateelement / lastelement) * (b - a));
    int k = 1;
    std::tuple<double, double> pre_interval;

    while (k < n) {
        if (calculate(function, x) > calculate(function,y))
        {
            a = x;
            x = y;
            penpenultimateelement = array[n - k - 1];
            penultimateelement = array[n - k];
            y = a + (penpenultimateelement / penultimateelement) * (b - a);
            if (k == (n - 2)) {
                y = x + eps;
                if (calculate(function,x) == calculate(function,y)) {
                    a = x;
                    k = n;
                }
                else {
                    b = y;
                    k = n;
                }
            }
            else
            {
                pre_interval = std::make_tuple(a, b);
                dict.insert(std::make_pair(k, pre_interval));
                k++;
            }
        }
        else
        {
            b = y;
            y = x;
            penpenultimateelement = array[n - k - 2];
            penultimateelement = array[n - k];
            x = a + (penpenultimateelement / penultimateelement) * (b - a);
            if (k == (n - 2))
            {
                y = x + eps;
                if (calculate(function,x) == calculate(function,y)) {
                    a = x;
                    k = n;
                }
                else {
                    b = y;
                    k = n;
                }

            }
            else
            {   
                pre_interval = std::make_tuple(a, b);
                dict.insert(std::make_pair(k, pre_interval));
                k = k + 1;
            }
        }

    }

    std::tuple<double, double> interval = std::make_tuple(a, b);
    return std::make_tuple(interval, dict);
}
