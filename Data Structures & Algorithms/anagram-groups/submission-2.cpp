class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> sorted_strs;
        vector<vector<string>> ans;
        if(strs.empty())
        {
            return {};
        }
        for (const auto& s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            sorted_strs[key].push_back(s);
        }
        for (const auto& s : sorted_strs)
        {
            ans.push_back(s.second);
        }
        return ans;
    }
};
