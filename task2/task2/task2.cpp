#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int recursiveCounter = 0;
int iterativeCounter = 0;

int findNthTermRecursive(int n) {
    recursiveCounter++;
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (n == 3) {
        return 3;
    }
    return 3 * findNthTermRecursive(n - 1) + 2 * findNthTermRecursive(n - 2) + findNthTermRecursive(n - 3);
}

int findNthTermIterative(int n) {
    iterativeCounter++;
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (n == 3) {
        return 3;
    }
    int a1 = 1, a2 = 2, a3 = 3, an;
    for (int i = 4; i <= n; i++) {
        iterativeCounter++;
        an = 3 * a3 + 2 * a2 + a1;
        a1 = a2;
        a2 = a3;
        a3 = an;
    }
    return an;
}

int main() {
    int n = 30;

    // Recursive
    auto start = high_resolution_clock::now();
    int result1 = findNthTermRecursive(n);
    auto end = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end - start);
    cout << "Recursive result: " << result1 << " Time taken: " << duration1.count() << " nanoseconds" << endl;
    cout << "Recursive operations: " << recursiveCounter << endl;

    // Iterative
    auto start2 = high_resolution_clock::now();
    int result2 = findNthTermIterative(n);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2 - start2);
    cout << "Iterative result: " << result2 << " Time taken: " << duration2.count() << " nanoseconds" << endl;
    cout << "Iterative operations: " << iterativeCounter << endl;

    return 0;
}