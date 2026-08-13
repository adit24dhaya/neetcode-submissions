class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> nums1Idx;
    for(int i = 0; i < nums1.size();i++)
    {
        nums1Idx[nums1[i]]= i; // key - value of nums1 and value - index
    }
    vector<int> res(nums1.size(),-1);
    stack<int> st;

    for(int num : nums2)
    {
        while (!st.empty() and num > st.top())
        {
            int val = st.top();
            st.pop();
            int idx = nums1Idx[val];
            res[idx] = num;
        }
        if(nums1Idx.find(num)!= nums1Idx.end())
        {
            st.push(num);
        }
    }
    return res;
    }
};