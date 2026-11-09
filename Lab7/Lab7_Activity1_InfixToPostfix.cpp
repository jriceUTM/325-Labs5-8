#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char value) {
    top = new Node{value, top};
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* oldTop = top;
    char value = oldTop->data;
    top = oldTop->next;
    delete oldTop;
    return value;
}

char peek(Node* top) {
    return (top == nullptr) ? '\0' : top->data;
}

bool isEmpty(Node* top) {
    return top == nullptr;
}

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(string infix) {
    Node* top = nullptr;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            push(top, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(top) && peek(top) != '(') {
                postfix += pop(top);
            }
            if (!isEmpty(top))
                pop(top);
        }
        else {
            while (!isEmpty(top) && peek(top) != '(' &&
                   precedence(peek(top)) >= precedence(ch)) {
                postfix += pop(top);
            }
            push(top, ch);
        }
    }

    while (!isEmpty(top)) {
        postfix += pop(top);
    }

    return postfix;
}

int main() {
    string expression;
    cout << "Enter infix expression: ";
    cin >> expression;
    cout << "Postfix: " << infixToPostfix(expression) << endl;
    return 0;
}
