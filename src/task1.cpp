#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // Initialize a variable to store the sum of remaining numbers
        long long remainingSum = 0;

        // Perform N-2 operations
        for (int i = 0; i < N - 2; ++i) {
            vector<int> medians;

            // Calculate medians for odd-sized subarrays greater than 2
            for (int j = 1; j < N - 1; j += 2) {
                int median = A[j];
                medians.push_back(median);
            }

            // Find the minimum median
            int minMedian = *min_element(medians.begin(), medians.end());

            // Remove the first occurrence of the minimum median from the array
            auto it = find(A.begin(), A.end(), minMedian);
            A.erase(it);

            // Add the remaining numbers to the sum
            for (int num : A) {
                remainingSum += num;
            }
        }

        // Print the sum of remaining numbers for each test case
        cout << remainingSum << " ";
    }

    return 0;
}
