#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        // Read the first sorted array A
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // Read the second sorted array B
        vector<int> B(M);
        for (int i = 0; i < M; ++i) {
            cin >> B[i];
        }

        // Merge the two sorted arrays into one sorted array in non-increasing order
        vector<int> mergedArray;
        int i = 0, j = 0;

        while (i < N && j < M) {
            if (A[i] >= B[j]) {
                mergedArray.push_back(A[i]);
                ++i;
            } else {
                mergedArray.push_back(B[j]);
                ++j;
            }
        }

        // Add remaining elements from A
        while (i < N) {
            mergedArray.push_back(A[i]);
            ++i;
        }

        // Add remaining elements from B
        while (j < M) {
            mergedArray.push_back(B[j]);
            ++j;
        }

        // Print the merged array in non-increasing order
        for (int k = 0; k < mergedArray.size(); ++k) {
            cout << mergedArray[k] << " ";
        }

        cout << endl;
    }

    return 0;
}
