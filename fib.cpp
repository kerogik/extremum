#include <vector>
#include <string>
#include <cmath>
//using namespace std;

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

double f3(double x) {
    double y = sin(x);
    return y;
}

double fib(double a, double b,double l, double eps)
{
    //double a, b, l, eps;
    //std::cout << "Enter a,b,l" <<std::endl;
    //std::cin >> a >> b >> l;
    //std::cout << "Enter eps" << endl;
    //cin >> eps;
    std::vector<int> array = masfib(l, b, a);
    int n = array.size() - 1;
    double arraya =array[n-2];
    double arrayb =array[n-1];
    double arrayc =array[n];
    double arr1, arr2;
    float x = (a + (arraya / arrayc) * (b - a));
    float y = (a + (arrayb / arrayc) * (b - a));
    //cout << array[n-2] << " " << (array[n-1] / array[n]) << " " << array[n] << " " << x << " " << y << endl;
    int k = 1;
    while (k < n) {
        if (f3(x) > f3(y))
        {
            a = x;
            x = y;
            arr1 = array[n - k - 1];
            arr2 = array[n - k];
            y = a + (arr1 / arr2) * (b - a);
            if (k == (n - 2)) {
                y = x + eps;
                if (f3(x) == f3(y)) {
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
                k++;
            }
        }
        else
        {
            b = y;
            y = x;
            arr1 = array[n - k - 2];
            arr2 = array[n - k];
            x = a + (arr1 / arr2) * (b - a);
            if (k == (n - 2))
            {
                y = x + eps;
                if (f3(x) == f3(y)) {
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
                k = k + 1;
            }
        }

    }
    //cout << a << "," << b << endl;
    //cout << n+1;   
    return (a + b)/2;
}
