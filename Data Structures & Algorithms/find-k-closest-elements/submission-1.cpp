#include <print>

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 1. find x in arr, or find the closest value less than x in the array

        vector<int> res;

        int left{};
        int right = arr.size() - 1;

        int count{k};
        int closestMid = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] <= x) {
                closestMid = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        // if a matching element to x was found we handle the left and right assignments differently

        // if (!res.empty()) {
        //     left = closestMid;
        //     right = closestMid + 1;
        // }
        if (closestMid < 0) { // the greatest element less than x is at the beginning
            left = closestMid + 1;
            right = closestMid + 2;
        }
        else {
            left = closestMid;
            right = closestMid + 1;
        }

        print("left = {}, mid = {}, right = {}\n", left, closestMid, right);
        // at this point, either an element in arr that is == to x is found or the closest value
        // to x that is less than x is found

        // either way I want to explore the left and right adjacent elements, 
        // 1. keep track of count = k
        // 2. conditionals to check the validity of the adjacent elements
        //      i. out of bounds check first since left is decrementing and right is incrementing
        //      ii. first check is if the difference between |a - x| < |b - x|
        //          a. if true, store a's index in the result and decrement left
                    // else if b's difference is less than, store b's index and increment right
                    // else, b and a difference are equal, and a is on the left pointer and the array is sorted
                    // then a is always going to be less than b so store a's index and decrement the left
        
        while(count > 0) {
            //out of bounds check 
            int leftElem;
            int rightElem;

            if (left < 0) { // if left is out of bounds, exclude the left in the comparisons
                leftElem = 1000000;
            }
            else {
                leftElem = arr[left];
            }

            if (right >= arr.size()) { // same for right 
                rightElem = 1000000;
            }
            else {
                rightElem = arr[right];
            }

            //      ii. first check is if the difference between |a - x| < |b - x|
        //          a. if true, store a's index in the result and decrement left
                    // else if b's difference is less than, store b's index and increment right
                    // else, b and a difference are equal, and a is on the left pointer and the array is sorted
                    // then a is always going to be less than b so store a's index and decrement the left

            int leftDiff = abs(leftElem - x);
            int rightDiff = abs(rightElem - x);

            if (leftDiff <= rightDiff) {
                res.push_back(leftElem);
                left--;
            }
            else {
                res.push_back(rightElem);
                right++;
            }
            --count;
        }

        sort(res.begin(), res.end());
        return res;
    }
};