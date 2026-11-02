class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 1 indexing

        // using the right adjacent element of a given element as the "next" node
        // with slow and fast pointers

        // 1 2 3 2 2 actual values of elements
        // 1 2 3 4 5 1-indexed

        // 1 2 3 2 2
        // S 
        // F 

        // 1 2 3 2 2
        //   S
        //     F
        // 
        // 1 2 3 2 2

        //     S
        //     F  
        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        int slow2 = 0;
        do {
            slow2 = nums[slow2];
            slow = nums[slow];
        } while(slow2 != slow);

        return slow;
        // although slow and  fast are equal at this point, they
        // are not guaranteed to converge on the element that is duplicate
        // the index that the slow and fast pointer converge on is the duplicate within //         input array
        // how to extract the index?


        // 1 2 3 4 4
        // S
        // F

        // 1 2 3 4 4 

        //   S F
        // 
        // 1 2 3 4 4

        //     S   F
        // 

        // 1 2 3 4 4

        //       S F

        // 1 2 3 4 4 
        //         S
                // F 
    }
};
