#include <charconv>
#include <print>

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        int res{};

        // for score elements, push to stack

        // for + 
        // store the top as a temp
        // stack.pop
        // need to check if the stack is empty 
        // if not then we can peek at the stack.top 
        // sum = stack.top() + temp
        // push temp back onto the stack
        // push the sum onto the stack

        // for D, stack.push(stack.top() * 2);

        // for C, just pop 


        for(const auto& s: operations) {
            if (s == "+" && !scores.empty()) {
                int temp = scores.top();
                scores.pop();
                int sumTwoPrev = temp + scores.top();
                scores.push(temp);
                scores.push(sumTwoPrev);
                res += sumTwoPrev;
            }
            else if (s == "C" && !scores.empty()) {

                res -= scores.top();
                scores.pop();
            }

            else if (s == "D" && !scores.empty()) {
                int doubleScore = scores.top() * 2;
                scores.push(doubleScore);
                res += doubleScore;

            }
            else {
                int currScore;
                auto x = from_chars(s.data(), s.data() + s.size(), currScore);
                scores.push(currScore);
                res += currScore;
            }
        }

        return res;
    }
};