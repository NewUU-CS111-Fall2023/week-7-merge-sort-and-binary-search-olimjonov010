#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> Y(n);
    for (int i = 0; i < n; ++i) {
        cin >> Y[i];
    }

    // Calculate the initial beautifulness
    long long initialBeautifulness = 0;
    for (int i = 0; i < n; ++i) {
        initialBeautifulness += abs(Y[i] - (i + 1));
    }

    // Try swapping adjacent elements to maximize beautifulness
    long long maxBeautifulness = initialBeautifulness;
    for (int i = 0; i < n - 1; ++i) {
        swap(Y[i], Y[i + 1]);

        // Calculate beautifulness after the swap
        long long currentBeautifulness = 0;
        for (int j = 0; j < n; ++j) {
            currentBeautifulness += abs(Y[j] - (j + 1));
        }

        // Update maxBeautifulness if the current beautifulness is greater
        maxBeautifulness = max(maxBeautifulness, currentBeautifulness);

        // Undo the swap for the next iteration
        swap(Y[i], Y[i + 1]);
    }

    cout << maxBeautifulness << endl;

    return 0;
}
