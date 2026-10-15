#include <print>
#include <charconv>

class Solution {
public:

    string encode(vector<string>& strs) {
        // multiple separate strings
        // frame start and end
        // im trn

        string res;

        if (strs.empty()) {
            return "";
        }

        char frameSeparator{'#'};

        for(const auto& x: strs) {
            res += to_string(x.length());
            res.push_back(frameSeparator);
            res += x;
        }
        // 1 string frame construction -> 
        // frame start + size + # + string + frame end

        return res;
    }

    vector<string> decode(string s) {
        // frame start + size + # + string + frame end
        vector<string> res;
        size_t i{};
        while (i < s.size()) {

            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }
        return res;
    }
};
