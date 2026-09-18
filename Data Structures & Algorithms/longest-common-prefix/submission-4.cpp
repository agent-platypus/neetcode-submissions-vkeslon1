class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string lcp{strs.front()};

        for(int i = 1; i < strs.size(); ++i) {
            int matchingIdx{stringwiseAND(lcp, strs[i])};
            if (!matchingIdx) {
                return "";
            }
            lcp.resize(matchingIdx);
        }

        return lcp;
    }

    int stringwiseAND(const string& a, const string& b) {
        int idx;
        for(idx = 0; idx < a.size() && idx < b.size(); ++idx) {
            if (a[idx] != b[idx] ) {
                return idx;
            }
        }

        return idx;
    } 
};