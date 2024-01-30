class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++i) {
            int x = 0;
            if ((tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                 tokens[i] == "/")) {
                switch (tokens[i][0]) {
                case '+':
                    x = s.top();
                    s.pop();
                    x += s.top();
                    s.pop();
                    s.push(x);
                    break;
                case '-':
                    x = s.top();
                    s.pop();
                    x = s.top() - x;
                    s.pop();
                    s.push(x);
                    break;
                case '*':
                    x = s.top();
                    s.pop();
                    x *= s.top();
                    s.pop();
                    s.push(x);
                    break;
                case '/':
                    x = s.top();
                    s.pop();
                    x = s.top() / x;
                    s.pop();
                    s.push(x);
                    break;
                }
            } else {
                istringstream in(tokens[i]);
                in >> x;
                s.push(x);
            }
        }
        return s.top();
    }
};