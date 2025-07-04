class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // To store frequency of each number

    // Step 1: Count frequency of each number using a for loop
    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
    }

    // Step 2: Use a min-heap to keep top k frequent elements
    // The heap stores pairs {frequency, number}
    priority_queue<pair<int, int>> minHeap;

    // Use for loop to push into heap
    for (auto i: freq) {
        int number = i.first;
        int frequency = i.second;

        minHeap.push({frequency, number});  // Push the pair
    }

    // Step 3: Extract the top k frequent elements from the heap
    vector<int> result;
    while (!minHeap.empty() && k) {
        result.push_back(minHeap.top().second); // We need the number, not frequency
        minHeap.pop();
        k--;
    }

    return result;
    }
};