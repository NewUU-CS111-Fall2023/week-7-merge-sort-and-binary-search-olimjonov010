#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(vector<int>& nums, int n) {
    int sum = 0;
    
    // Calculate the sum of the numbers from 1 to n
    int expectedSum = n * (n + 1) / 2;

    // Calculate the sum of the given array
    for (int num : nums) {
        sum += num;
    }

    // The missing number is the difference between the expected sum and the actual sum
    return expectedSum - sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n - 1);

    // Input the array of n-1 distinct numbers
    for (int i = 0; i < n - 1; ++i) {
        cin >> nums[i];
    }

    // Find and print the missing number
    int missingNumber = findMissingNumber(nums, n);
    cout << missingNumber << endl;

    return 0;
}
