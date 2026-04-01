class Solution {
public:
    int maxArea(vector<int>& heights) {
        int vec_size = heights.size();
        int left = 0;
        int right = vec_size-1;
        int mostWater = 0;

        // how to determine which pointer to move 
        // 
        while(left < right) {
            int newWaterAmount = waterAmount(left, right, heights[left], heights[right]);
            if( newWaterAmount >= mostWater) {
                mostWater = newWaterAmount;
            }
            if (heights[left] > heights[right]) {
                right--;
            }
            else {
                left++;
            }
        }
        return mostWater;
    }

    int waterAmount(int leftidx, int rightidx, int leftHeight, int rightHeight) {
        return (min(leftHeight, rightHeight) * (rightidx - leftidx));
    }
};
