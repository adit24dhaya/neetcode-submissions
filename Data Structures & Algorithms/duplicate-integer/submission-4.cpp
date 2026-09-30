class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num : nums)
        {
            seen.insert(num);
        }
        if(seen.size()==nums.size())
        {
            return false;
        }
        return true;
    }
};