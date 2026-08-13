class Solution {
public:
    bool isPowerOfTwo(int n) {
        if ( n <=0) return false;
        int counter = 0;
        for(int i = 0; i < 32; i++)
        {
            int bit = n & 1;
            n = n >> 1;
            counter += bit;

            if(counter > 1)
            {
                return false;
            }
        }
        return true;
    }
};