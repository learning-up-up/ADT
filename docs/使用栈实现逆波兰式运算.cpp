#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

class Stack {
private:
    double data[100]; // 假设栈的最大容量为100
    int top;

public:
    Stack() : top(-1) {}

    bool push(double value) {
        if (top >= 99) return false; // 栈满
        data[++top] = value;
        return true;
    }

    bool pop(double &value) {
        if (top < 0) return false; // 栈空
        value = data[top--];
        return true;
    }

    bool isEmpty() {
        return top == -1;
    }
};

// 计算逆波兰表达式的函数
double evaluateRPN(string tokens[], int size) {
    Stack s;
    for (int i = 0; i < size; ++i) {
        string token = tokens[i];
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            s.push(stod(token));
        } else {
            double b, a;
            s.pop(b);
            s.pop(a);
            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") s.push(a / b);
        }
    }
    double result;
    s.pop(result);
    return result;
}

int main() {
    string input;
    cout << "请输入逆波兰表达式（用空格分隔）：" << endl;
    getline(cin, input);

    string tokens[100]; // 假设最多100个元素
    int size = 0;

    stringstream ss(input);
    string token;
    while (ss >> token) {
        tokens[size++] = token;
    }

    double result = evaluateRPN(tokens, size);
    cout << "计算结果: " << result << endl;

    return 0;
}