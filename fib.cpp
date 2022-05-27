#include <vector>
#include <cmath>
#include <map>
#include <tuple>

typedef std::tuple<std::tuple<double, double>, std::map<int, std::tuple<double, double>>> FuncOutput;

std::vector<int> masfib(double l, double b, double a)
{
    std::vector<int> array;
    array.push_back(1);
    array.push_back(1);
    int i = 1;
    int fib;
    while (array[i] <= ((b - a) / l))
    {
        i++;
        fib = array[i - 1] + array[i - 2];
        array.push_back(fib);
    }
    int n = i;
    return array;
}


FuncOutput fib(double a, double b,double l, double eps, std::string function)
{
    
    typedef std::map<int, std::tuple<double, double>> ForGraph;
    ForGraph dict;
    std::vector<int> array = masfib(l, b, a);
    int n = array.size() - 1;
    double arraya =array[n-2];
    double arrayb =array[n-1];
    double arrayc =array[n];
    /*double arr1, arr2;*/
    float x = (a + (arraya / arrayc) * (b - a));
    float y = (a + (arrayb / arrayc) * (b - a));
    int k = 1;
    std::tuple<double, double> pre_interval;
    double center;

    while (k < n) {
        if (calculate(function, x) > calculate(function,y))
        {
            a = x;
            x = y;
            /*arr1 = array[n - k - 1];
            arr2 = array[n - k];*/
            arraya = array[n - k - 1];
            arrayb = array[n - k];
            y = a + (arraya / arrayb) * (b - a);
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
            /*arr1 = array[n - k - 2];
            arr2 = array[n - k];*/
            arraya = array[n - k - 2];
            arrayb = array[n - k];
            x = a + (arraya / arrayb) * (b - a);
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
 
    center = (a + b) / 2;
    std::tuple<double, double> interval = std::make_tuple(a, b);
    return std::make_tuple(interval, dict);
}
