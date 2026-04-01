class Solution {
public:
    int hammingWeight(uint32_t n) {

        int number_1s = 0;
        for(int i = 0; i < 32; i++ ) {
            number_1s += (n >> i) & 0x0001;
        }
        return number_1s;
    }
};
