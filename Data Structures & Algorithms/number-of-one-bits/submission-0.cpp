class Solution {
public:
    int hammingWeight(uint32_t n) {
    int res = 0;

    for(int i = 0; i<32; i++)
    {
        uint32_t bit = n & 1;
        res +=bit;
        n = n >> 1;
    }
    return res;
    }
};
