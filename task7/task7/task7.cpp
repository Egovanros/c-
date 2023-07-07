#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    srand(time(NULL));
    int lower, upper, n;
    cout << "Введите нижнюю границу диапазона: ";
    cin >> lower;
    while (lower <= 0)
    {
        cout << "Неверный ввод! Повторите: ";
        cin >> lower;
    }
    cout << "Введите верхнюю границу диапазона: ";
    cin >> upper;
    while (upper < lower)
    {
        cout << "Неверный ввод! Повторите: ";
        cin >> upper;
    }
    n = rand() % (upper - lower + 1) + lower;
    
    cout << "Случайное число: " << n << endl;

   
    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % (upper - lower + 1) + lower;
        }
    }

    

    ofstream fout("matrix.txt");
    if (fout.is_open()) {
        fout << n << endl; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fout << A[i][j] << " ";
            }
            fout << endl;
        }
        fout.close();
    }
    else {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

   
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}