#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element {
    int value;
    int row;
    int col;

    Element(int v, int r, int c) : value(v), row(r), col(c) {}

    // Overloading the comparison operator for min-heap
    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    
    // Using a min-heap to keep track of the smallest elements
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    // Adding the first element of each row to the min-heap
    for (int i = 0; i < n; ++i) {
        minHeap.push(Element(matrix[i][0], i, 0));
    }

    // Extracting the kth smallest element
    for (int i = 0; i < k - 1; ++i) {
        Element current = minHeap.top();
        minHeap.pop();

        // If the current element has a next element in its row, add it to the min-heap
        if (current.col < n - 1) {
            minHeap.push(Element(matrix[current.row][current.col + 1], current.row, current.col + 1));
        }
    }

    // Return the kth smallest element
    return minHeap.top().value;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> matrix(n, vector<int>(n));

    // Input matrix elements
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Find and print the kth smallest element
    int result = kthSmallest(matrix, k);
    cout << result << endl;

    return 0;
}
