class Solution {
public:
    int calculate(string s) {
        stack<char> ops;
        vector<string> tokens;
        long long val = 0;
        bool num_start = false;
        bool need_zero = true;
        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                val = val * 10 + ch - '0';
                num_start = true;
                continue;
            }
            else if (num_start) {
                tokens.push_back(to_string(val));
                num_start = false;
                need_zero = false;
                val = 0;
            }
            //处理空格
            if (ch == ' ') continue;
            //处理括号
            if (ch == '(') {
                ops.push(ch);
                need_zero = true;
                continue;
            }
            if (ch == ')') {
                while (ops.top() != '(') {
                    tokens.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.pop();
                need_zero = false;
                continue;
            }
            //处理+-*/
            if (need_zero) tokens.push_back("0");
            while (!ops.empty() && getRank(ops.top()) >= getRank(ch)) {
                //错误代码getRank(ops.top() >= getRank(ch)))我是真的吐了
                tokens.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(ch);
            need_zero = true;
        }

        if (num_start) tokens.push_back(to_string(val));
        while (!ops.empty()) {
            tokens.push_back(string(1, ops.top()));
            ops.pop();
        }
        return evalRPN(tokens);
    }

    int getRank(char ch) {
        if (ch == '+' || ch == '-') return 1;
        if (ch == '*' || ch == '/') return 2;
        return 0;
    }
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