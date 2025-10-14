/* ------------- Problem 3-1 -------------
A common problem for compilers and text editors is determining whether the parentheses in a string
are balanced and properly nested. For example, the string ((())())() contains properly nested pairs
of parentheses, while the strings )()( and ()) do not. Give an algorithm that returns true if a
string contains properly nested and balanced parentheses, and false if otherwise. For full credit,
identify the position of the first offending parenthesis if the string is not properly nested and
balanced.
*/
#include <iostream>
#include <stack>
#include <string>
#include <vector>

struct ParenthesisValidation {
    bool isValid;
    int firstOffending;
};

ParenthesisValidation hasValidParentheses(std::string_view input) {
    std::stack<int> openIndices;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
            openIndices.push(i);
        }

        else if (input[i] == ')') {
            if (openIndices.size() == 0) {
                return ParenthesisValidation{false, i};
            }
            openIndices.pop();
        }
    }
    if (openIndices.size() > 0) {
        return ParenthesisValidation{false, openIndices.top()};
    }

    return ParenthesisValidation{true, -1};
}

int main() {
    std::vector<std::string_view> testStrings = {"((())())()", ")()(", "())", "((()"};
    for (auto x : testStrings) {
        ParenthesisValidation validation = hasValidParentheses(x);
        if (validation.isValid) {
            std::cout << x << " is valid" << "\n";
        } else {
            std::cout << x
                      << " is not valid, bad parenthesis at index: " << validation.firstOffending
                      << "\n";
        }
    }
}