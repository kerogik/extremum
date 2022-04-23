#include "graphics.cpp"
#include "dixotomia.cpp"

int main(int argc, char **argv) {
    double a,b,eps,l;
    std::cout << "Введите значение левой границы" << std::endl;
    std::cin >> a;
    std::cout << "Введите значение правой границы" << std::endl;
    std::cin >> b;
    std::cout << "Введите значение погрешности" << std::endl;
    std::cin >>eps;
    std::cout << "Что нужно найти? \n 1-максимум \n 2-минимум" << std::endl;
    std::cin >>l;
    std::cout << dixot(a,b,eps,l) << std::endl;
    graphics();
}
