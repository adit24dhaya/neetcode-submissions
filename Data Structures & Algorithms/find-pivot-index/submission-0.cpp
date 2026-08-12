class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>sum(n,0);
        vector<int>postfix(n,0);

        //prefix
        for(int i =1; i<n;i++)
        {
            sum[i] = sum[i-1] +nums[i-1];
        }
        for(int i = n-2; i>= 0; i-- )
        {           
            postfix[i] = postfix[i+1] + nums[i+1];
        }
        for(int i =0; i<n; i++)
        {
            if (postfix[i] - sum[i] == 0) return i;
        }
        return -1;
    }
};