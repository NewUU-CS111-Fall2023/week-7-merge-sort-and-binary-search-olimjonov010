#include <iostream>
#include <vector>

using namespace std;

pair<int, int> searchInsertPosition(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            index = mid;
            return {1, index};
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
            index = mid;
        }
    }

    return {-1, index + 1};
}

int main() {
    int n, target;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cin >> target;

    pair<int, int> result = searchInsertPosition(nums, target);

    // Print the result
    cout << result.first << " " << result.second << endl;

    return 0;
}
