#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> kMostFrequent(vector<int>& nums, int k) {
    // Count the frequency of each element using an unordered map
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    // Use a max heap to keep track of the k most frequent elements
    priority_queue<pair<int, int>> maxHeap;

    // Iterate through the frequency map
    for (auto it = freqMap.begin(); it != freqMap.end(); ++it) {
        maxHeap.push({it->second, it->first});

        // If the size of the heap exceeds k, pop the least frequent element
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    // Extract the result from the max heap
    vector<int> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    // Reverse the result since it's in decreasing order
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cin >> k;

    vector<int> result = kMostFrequent(nums, k);

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
