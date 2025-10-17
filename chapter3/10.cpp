/* ------------- Problem 3-10 -------------
Two strings X and Y are anagrams if the letters of X can be rearranged to form Y . For example,
silent/listen, and incest/insect are anagrams. Give an efficient algorithm to determine whether
strings X and Y are anagrams.
*/
#include <iostream>
#include <string_view>
#include <unordered_map>

bool isAnagram(std::string_view x, std::string_view y) {
    std::unordered_map<char, int> letterCount;

    // Words with different lengths can't be anagrams of each other.
    if (x.length() != y.length()) {
        return false;
    }

    // Hash map with how many times a letter appeared on x.
    for (const auto letter : x) {
        letterCount[letter] += 1;
    }

    for (const auto letter : y) {
        // If some letter in y doesn't exists on x, then it's not an anagram.
        if (!letterCount.contains(letter)) {
            return false;
        }
        // When we're decrementing, if the letter counts ever gets bellow zero, it means that the
        // letter in question appeared more on y than in x, so it can be an anagram.
        if (letterCount[letter]-- < 0) {
            return false;
        }
    }

    // Check if all letter counts are zero.
    for (const auto &[letter, count] : letterCount) {
        if (count != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string_view x = "insect";
    std::string_view y = "incest";

    std::cout << x << " and " << y;
    if (isAnagram(x, y)) {
        std::cout << " are ";
    } else {
        std::cout << " are not ";
    }
    std::cout << "anagrams of each other";
}