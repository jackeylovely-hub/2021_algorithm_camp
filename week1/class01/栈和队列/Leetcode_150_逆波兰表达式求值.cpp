class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long b = stk.top();
                stk.pop();
                long long a = stk.top();
                stk.pop();
                stk.push(calculate(a, b, token));//忘了将计算后的结果压入栈
            }
            else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
    long long calculate(long long a, long long b, string token) {
        if (token == "+") return a + b;
        if (token == "-") return a - b;
        if (token == "*") return a * b;
        if (token == "/") return a / b;
        return 0;
    }
};