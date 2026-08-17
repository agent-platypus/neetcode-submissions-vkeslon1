class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> res;
        for(int i = 0; i < queries.size(); i++) {
            int valid_words = 0;

            int start_idx = queries[i][0];
            int end_idx = queries[i][1];

            for(int j = start_idx; j < end_idx + 1; j++) {
                if (validWord(words[j])) {
                    valid_words++;
                }
            }
            res.push_back(valid_words);
        }
        return res;
    }

    bool validWord(string word) {

        int n = word.length();
        if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') {
            if (word[n-1] == 'a' || word[n-1] == 'e' || word[n-1] == 'i' || word[n-1] == 'o' || word[n-1] == 'u') {
                return true;
            }
        }

        return false;
            
    }
};