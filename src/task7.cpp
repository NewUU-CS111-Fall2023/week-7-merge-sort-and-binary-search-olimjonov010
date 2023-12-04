#include <iostream>

using namespace std;

// Recursive function to calculate x raised to the power n
int recursivePow(int x, int n) {
    // Base case: x^0 is always 1
    if (n == 0) {
        return 1;
    }

    // Recursive case: x^n = x * x^(n-1)
    return x * recursivePow(x, n - 1);
}

int main() {
    int x, n;

    // Input x and n
    cin >> x >> n;

    // Calculate x raised to the power n using recursivePow function
    int result = recursivePow(x, n);

    // Print the result
    cout << result << endl;

    return 0;
}
