class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> arr(nums.begin(), nums.end());
    if(arr.size() < nums.size()) return true;
    else return false;
    }
};