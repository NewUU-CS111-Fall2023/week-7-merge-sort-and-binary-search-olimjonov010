#include <iostream>

using namespace std;

int kthFactor(int n, int k) {
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            k--;
            if (k == 0) {
                return i;
            }
        }
    }
    return -1; // If n has fewer than k factors
}

int main() {
    int n, k;
    cin >> n >> k;

    int result = kthFactor(n, k);

    // Print the result
    cout << result << endl;

    return 0;
}
