#include <print> 

class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int n1 = word1.length();
        int n2 = word2.length();
        string res;
        res.reserve(n1 + n2);

        int ptr1 = 0;
        int ptr2 = 0;

        int resIdx{};
        while(ptr1 < n1 && ptr2 < n2) {
            print("ptr 1 = {}, ptr 2 = {}\n", ptr1, ptr2);
            res.push_back(word1[ptr1++]);
            res.push_back(word2[ptr2++]);
        }

        while(ptr1 < n1) {
            res.push_back(word1[ptr1++]);
        }

        while(ptr2 < n2) {
            res.push_back(word2[ptr2++]);
        }

        return res;
        
    }
};