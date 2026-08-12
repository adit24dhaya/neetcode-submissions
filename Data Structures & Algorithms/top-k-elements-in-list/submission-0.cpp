class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // store the number-frequency in the unordered_map
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        //create a min-heap
        priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> heap;

        //insert the count-map as frequency-number into the min-heap
        //min-heap stores the values in increasing order
        //we pop the top of the heap to keep the most frequent values using the   frequency
        for (auto& entry : count) {
            heap.push({entry.second, entry.first});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        //then we store the heap values as second and pop the heap
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};