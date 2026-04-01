class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size()) {
            return false;
        }
        
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for(int i = 0; i < s1.size(); i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        int matches = 0;
        for(int i = 0; i < 26; i++) {
            if(count1[i] == count2[i]) {
                matches++;
            }
        }

        int left = 0;

        for(int right = s1.length(); right < s2.length(); right++) {
            if(matches == 26) {
                return true;
            }

            int index = s2[right] - 'a';
            count2[index]++;
            
            if(count1[index] == count2[index]) {
                matches++;
            }
            else if (count1[index] + 1 == count2[index]) {
                matches--;
            }

            index = s2[left] - 'a';
            count2[index]--;
            if(count1[index] == count2[index]) {
                matches++;
            }
            else if (count1[index] - 1 == count2[index]) {
                matches--;
            }
            left++;
        }
        return (matches == 26);
    }
};
