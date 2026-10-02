class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int num1 = numeric_limits<int>::min();
        int num2 = numeric_limits<int>::min();

        int freq1{};
        int freq2{};
        vector<int> res;
        for(const auto& x: nums) {
            if (x == num1) {
                ++freq1;
            }
            else if (x == num2) {
                ++freq2;
            }
            else if (freq1 == 0) {
                num1 = x;
                freq1 = 1;
            }
            else if (freq2 == 0) {
                num2 = x;
                freq2 = 1;
            }
            else {
                --freq1;
                --freq2;
            }
        }

        freq1 = 0;
        freq2 = 0;
        for(const auto& x: nums) {
            if (x == num1) {
                ++freq1;
            }
            else if (x == num2) {
                ++freq2;
            }
        }

        if (freq1 > nums.size() / 3) 
            res.push_back(num1);
        if (freq2 > nums.size() / 3) 
            res.push_back(num2);

        return res;
    }
};