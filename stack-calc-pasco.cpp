#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

vector<string> infixToPostfix(const string& expression) {
    stack<char> ops;
    vector<string> output;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            output.push_back(token);
        } else if (token == "(") {
            ops.push('(');
        } else if (token == ")") {
            while (!ops.empty() && ops.top() != '(') {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.pop();
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(token[0])) {
                output.push_back(string(1, ops.top()));
                ops.pop();
            }
            ops.push(token[0]);
        }
    }

    while (!ops.empty()) {
        output.push_back(string(1, ops.top()));
        ops.pop();
    }

    return output;
}

int evaluatePostfix(const vector<string>& postfix) {
    stack<int> values;

    for (const auto& token : postfix) {
        if (isdigit(token[0])) {
            values.push(stoi(token));
        } else {
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            values.push(applyOp(a, b, token[0]));
        }
    }

    return values.top();
}

int main() {
    string expression;
    cout << "Enter an expression in infix notation: ";
    getline(cin, expression);

    vector<string> postfix = infixToPostfix(expression);
    int result = evaluatePostfix(postfix);

    cout << "Result: " << result << endl;

    return 0;
}