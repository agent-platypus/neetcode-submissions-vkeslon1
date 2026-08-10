class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int w1ptr = 0;
        int w2ptr = 0;

        int w1sz = word1.length();
        int w2sz = word2.length(); 

        string res;
        while(w1ptr < w1sz || w2ptr < w2sz) {

            if (w1ptr < w1sz) {
                res.push_back(word1[w1ptr]);
                w1ptr++;
            }
            
            if (w2ptr < w2sz) {
            res.push_back(word2[w2ptr]);
            w2ptr++;
            }
        }

        return res;
    }
};