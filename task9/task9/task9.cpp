#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Monitor {
    string manufacturer;
    double size; 
    double price; 
};

int main() {
    setlocale(LC_ALL, "Ru");

    
    Monitor monitors[] = {
        {"Acer", 17.5, 8000.0},
        {"Asus", 24.0, 12000.0},
        {"Dell", 19.5, 9500.0},
        {"LG", 18.0, 8500.0},
        {"Samsung", 27.0, 15000.0}
    };

    
    ofstream fout("monitors.bin", ios::binary);
    if (!fout.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    
    for (int i = 0; i < 5; i++) {
        fout.write((char*)&monitors[i], sizeof(Monitor));
    }

    fout.close(); 

   
    ifstream fin("monitors.bin", ios::binary);
    if (!fin.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    
    double sum = 0.0;
    int count = 0;
    Monitor m;
    while (fin.read((char*)&m, sizeof(Monitor))) {
        if (m.size >= 19.0) {
            sum += m.price;
            count++;
            cout << "Фирма-производитель: " << m.manufacturer << endl;
            cout << "Размер по диагонали: " << m.size << " дюймов" << endl;
            cout << "Стоимость: " << m.price << " рублей" << endl << endl;
        }
    }

    fin.close(); 

    if (count > 0) {
        double averagePrice = sum / count;
        cout << "Средняя цена мониторов размером не менее 19 дюймов: " << averagePrice << " рублей" << endl;
    }
    else {
        cout << "Мониторов размером не менее 19 дюймов не найдено" << endl;
    }

    return 0;
}