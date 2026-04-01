class Solution {
public:
    int hammingWeight(uint32_t n) {
        int numBit = 0;
        for(int i = 0; i < 32; i++) {
            uint32_t filtered = n & (1 << i);
            if (filtered != 0) {
                numBit++;
            }
        }

        return numBit;
    }
};
