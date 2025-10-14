/* ------------- Problem 3-2 -------------
Give an algorithm that takes a string S consisting of opening and closing
parentheses, say )()(())()()))())))(, and finds the length of the longest balanced
parentheses in S, which is 12 in the example above. (Hint: The solution is not
necessarily a contiguous run of parenthesis from S.)
*/
#include <iostream>
#include <stack>

int countValid(std::string_view input) {
    std::stack<int> openIndices;
    int matched = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
            openIndices.push(i);
        }

        else if (input[i] == ')') {
            if (openIndices.size() != 0) {
                openIndices.pop();
                matched++;
            }
        }
    }

    return 2 * matched;
}

int main() {
    std::string_view testStr = ")()(())()()))())))(";
    std::cout << "Longest balanced subsequence of " << testStr
              << " has length: " << countValid(testStr) << "\n";
}
