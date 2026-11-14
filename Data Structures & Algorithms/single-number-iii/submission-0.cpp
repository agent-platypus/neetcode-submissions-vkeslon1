class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        uint32_t xorAll = 0;

        for(int x: nums) {
            xorAll ^= x;
        }

        // a ^ b

        // find least significant set bit that differs between the 2 numbers
        // a ^ b will contain the bits that differ between the 2

        uint32_t differLSB = xorAll & -xorAll;

        int a = 0;
        int b = 0;

        for(int x: nums) {
            if (x & differLSB) {
                a ^= x;
            }
            else {
                b ^= x;
            }
        }

        return {a, b};
    }
};