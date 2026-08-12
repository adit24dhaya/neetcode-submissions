class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0;//left pointer to the start
        int res = 0;//counter

        //we use right pointer in loop to make it move
        for (int r = 0; r < s.size(); r++) {
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            //update the window length
            res = max(res, r - l + 1);
        }
        return res;
    }
};