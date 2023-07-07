#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double f(double x, double alpha) {
    double pi = 3.14;
    return sqrt(pi/2)*exp(alpha * x) + x / (alpha * alpha + x * x);
}

double fprime(double x, double alpha) {
    double pi = 3.14;
    return sqrt(pi / 2) * alpha * exp(alpha * x) - (2 * alpha * x) / pow(alpha * alpha + x * x, 2);
}

double newton_method(double x0, double alpha, double tol, int& iterations) {
    double x = x0;
    iterations = 0;

    while (true) {
        double fx = f(x, alpha);
        double fpx = fprime(x, alpha);

        double x_next = x - fx / fpx; // вычисляем следующее приближение
        double err = fabs(x_next - x); // оцениваем погрешность

        iterations++;

        if (err < tol) {
            return x_next; // если достигнута точность, возвращаем найденное значение x
        }

        x = x_next; // обновляем текущее приближение
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    double alpha;
    cout << "Введите параметр альфа: ";
    cin >> alpha;

    
    double x0, x, tol;

    x0 = 0.5;
    tol = 1e-6;

    ofstream fout("iterations.txt"); 

    
    for (x = 0.5; x <= 1.0; x += 0.1) {
        int iterations;
        double result = newton_method(x0, alpha, tol, iterations); 
        cout << "x = " << x << ", результат = " << result << endl; 
        fout << "x = " << x << ", кол-во итераций = " << iterations << endl; 
    }

    fout.close();

    return 0;
}