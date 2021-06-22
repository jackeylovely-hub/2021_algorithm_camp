//解法一：常规做法
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            }
            else {
                if (stk.empty())  return false;
                if (c == ')') {
                    if (stk.top() != '(') {
                        return false;
                    }
                }
                else if (c == ']') {
                    if (stk.top() != '[') {
                        return false;
                    }
                }
                else if (c == '}') {
                    if (stk.top() != '{') {
                        return false;
                    }
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
//解法二：ascii码做法
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            }
            else {
                if (stk.size() && abs(stk.top() - c) <= 2) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};