class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t ret = n;
        ret = (ret >> 16 | ret << 16);
        ret = ((0xff00ff00 & ret) >> 8) | ((0x00ff00ff & ret) << 8);
        ret = ((0xf0f0f0f0 & ret) >> 4) | ((0x0f0f0f0f & ret) << 4);
        ret = ((0xcccccccc & ret) >> 2) | ((0x33333333 & ret) << 2);
        ret = ((0xaaaaaaaa & ret) >> 1) | ((0x55555555 & ret) << 1);
        return ret;
    }
};
