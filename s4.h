

#include <string>
#include <utility>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int ans_start = 0, ans_end = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            auto [s1, e1] = expandCenter(s, i, i);
            auto [s2, e2] = expandCenter(s, i, i + 1);

            if (e1 - s1 > ans_end - ans_start) {
                ans_end = e1;
                ans_start = s1;
            }
            if (e2 - s2 > ans_end - ans_start) {
                ans_end = e2;
                ans_start = s2;
            }
        }
        return s.substr(ans_start, ans_end - ans_start + 1);
    }

private:
    pair<int, int> expandCenter(const string& s, int start, int end) {
        while (start >= 0 && end < (int)s.size() && s[start] == s[end]) {
            start--;
            end++;
        }
        return { start + 1, end - 1 };
    }
};


