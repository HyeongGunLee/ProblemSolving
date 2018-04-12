#include <iostream>
#include <stack>
#include <string>
using namespace std;


char TOKENS[3][2] = {{ '{', '}'}, {'(', ')'}, {'[', ']'}};

bool isOpenTerm(char c) {
    for (char* array : TOKENS) {
        cout << "1" << array[0] << " " << c << endl;
        if (array[0] == c) {
            return true;
        }
    }
    return false;
}

bool matches(char openTerm, char closeTerm) {
    for (char* array : TOKENS) {
        cout << "2" << array[0] << " " << openTerm << closeTerm << endl;
        if (array[0] == openTerm) {
            cout << "3" << array[0] << " " << array[1] << endl;
            return array[1] == closeTerm;
        }
    }
    return false;
}

bool isBalanced(string expression) {
    stack<char> stack;
    for (char c : expression) {
        if (isOpenTerm(c)) {
            stack.push(c);
        } else {
            if (matches(stack.top(), c)) {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    return stack.empty();
}


int main(void) {
    string expression = "[]";
    cout << isBalanced(expression);
}