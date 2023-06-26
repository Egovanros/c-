
// задачи на перебор и циклы(задача 8)

#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ofstream file;
    file.open("fractions.txt");
    for (int denominator = 2; denominator <= 255; denominator++) {
        for (int numerator = 1; numerator < denominator; numerator++) {
            if (gcd(numerator, denominator) == 1) {
                file << (double)numerator / denominator << endl;
            }
        }
    }
    file.close();
    return 0;
}