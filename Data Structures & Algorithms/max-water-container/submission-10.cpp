class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left{};
        int right = heights.size() - 1;

        int maxArea = 0;
        while(left < right) {
            int currArea = min(heights[left], heights[right]) * (right - left);
            maxArea = max(currArea, maxArea);

            if (heights[left] > heights[right]) {
                --right;
            }
            else {
                ++left;
            }
        }

        return maxArea;
    }
};
