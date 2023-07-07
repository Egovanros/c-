#include <iostream>

using namespace std;

void simpleMovingAverage(double* data, int dataSize, double* result, int windowSize) {
    double sum = 0;

    for (int i = 0; i < dataSize; i++) {
        if (i >= windowSize) {  // проверяем, вышли ли за пределы окна(период)
            sum -= *(data + i - windowSize); // если да то вычитаем из суммы значение которое находится за пределами окна
        }
        sum += *(data + i); // добавляем в сумму текущий элемент
        if (i >= windowSize - 1) { // проверяем достигли ли конца окна
            *(result + i - windowSize + 1) = sum / (2 * windowSize + 1); // вычисляем по формуле значение скользящего среднего
        }
    }
}

int main() {
    double data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int dataSize = 10;
    int windowSize;
    
    cout << "Enter size of window: ";
    cin >> windowSize;
    if (windowSize > dataSize || windowSize <= 0) {
        cout << "Error(Size of window uncorrectable)";
        return 0;
    }
   
    double *result = new double[dataSize + 1 - windowSize];

    simpleMovingAverage(data, dataSize, result, windowSize);

    for (int i = 0; i < dataSize - windowSize + 1; i++) {
        cout << "GDP[" << i << "]: " << *(result + i) << endl;
    }

    delete[] result;
    return 0;
}