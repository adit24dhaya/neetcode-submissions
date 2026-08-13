class Solution {
public:
    int numberofOnes(int n)
    {
        int counter = 0;
        int bit = 0;
        for(int i= 0; i<32;i++)
        {
            bit = n & 1;
            counter +=bit;
            n = n >> 1;
        }
        return counter;
    }
    vector<int> res;
    vector<int> countBits(int n) {
        for (int i = 0; i <= n; i ++)
        {
            int n = numberofOnes(i);
            res.push_back(n);
        }
        return res;
    }
};
