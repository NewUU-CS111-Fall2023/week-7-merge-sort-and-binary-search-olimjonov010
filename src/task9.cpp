#include <iostream>
#include <vector>

using namespace std;

int findKthMissingPositive(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    int num = 1;

    while (count < k) {
        if (num != arr[arr.size() - 1]) {
            if (num == arr[num - 1]) {
                num++;
            } else {
                count++;
                num++;
            }
        } else {
            num++;
        }
    }

    return num - 1;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    // Input the sorted array
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Find and print the kth missing positive integer
    int result = findKthMissingPositive(arr, k);
    cout << result << endl;

    return 0;
}
