#include <iostream>
#include <algorithm>
using namespace std;

void print_weight_diff(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int half_sum = sum / 2;

    bool* dp = new bool[half_sum + 1];
    for (int i = 0; i <= half_sum; i++){
        dp[i] = false;
    }
    dp[0] = true;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = half_sum; j >= arr[i]; j--) {
            dp[j] |= dp[j - arr[i]];
        }
    }

    bool found_diff = false;
    for (int j = half_sum; j >= 0; j--) {
        if (dp[j]){
            int diff = sum - 2 * j;
            if (diff < sum - diff) {
                cout << "Разница между массами кучек: " << diff << endl;
                found_diff = true;
            }
        }
    }

    if (!found_diff) {
        cout << "Разница превышает допустимое значение (в 2 раза)" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    int n;
    cout << "Введите количество камешков: ";
    cin >> n;
    if (n <= 1) {
        cout << "Кол-во камешков должно быть 2 или более";
        return 0;
    }
    int* arr = new int[n];
    cout << "Введите массы камешков: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
        if (arr[i] < 0) {
        cout << "Масса камешков должна быть положительной";
        return 0;
        }
    }
   
    print_weight_diff(arr, n);
    return 0;
}