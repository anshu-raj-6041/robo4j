class Solution {
public:
    vector<string> res;
    unordered_map<string, int> mp;

    int countIP(string s) {
        // stack<char> st;
        int open = 0, invalid = 0;

        // to cal no of invalid parenthesis
        for (char ch : s) {
            // char ch = s[i];

            if (ch == '(') {
                // st.push(ch);
                open++;
            } else if (ch == ')') {
                if (open > 0) {
                    open--;
                } else {
                    invalid++;
                }
            }
        }
        return open + invalid;
    }

    void solve(string s, int minInv) {
        if (mp[s] != 0) {
            return;
        } else {
            mp[s]++;
        }

        if (minInv < 0) {
            return;
        }

        if (minInv == 0) {
            // to check valid
            if (!countIP(s)) {
                res.push_back(s);
            }
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '(' && s[i] != ')')
                continue;
            string left = s.substr(0, i);
            string right = s.substr(i + 1);
            solve(left + right, minInv - 1);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        solve(s, countIP(s));
        return res;
    }
};
