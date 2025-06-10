#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>  // For std::tolower

// Generic search function using parametric polymorphism (optimized)
template <typename T, typename Predicate>
std::vector<T> searchItems(
    const std::vector<T>& items,
    Predicate searchStrategy)
{
    std::vector<T> result;
    for (const auto& item : items) {
        if (searchStrategy(item)) {
            result.push_back(item);
        }
    }
    return result;
}

// Print the result
template <typename T>
void printItems(const std::vector<T>& items) {
    for (const auto& item : items) {
        std::cout << item << "\n";
    }
}

// Function returning a lambda to check if a string starts with a given character
std::function<bool(const std::string&)> checkStringStartsWithGivenChar(char startChar) {
    return [startChar](const std::string& name) {
        return !name.empty() && std::tolower(name[0]) == std::tolower(startChar);
    };
}

int main() {
    // List of names (std::string)
    std::vector<std::string> names = {"Sam", "John", "Sara", "Michael", "Steve", "Alice", "susan", "Tom", "Travis"};
    
    // Search names starting with a given character
    char startChar = 's';
    auto filteredNames = searchItems(names, checkStringStartsWithGivenChar(startChar));
    std::cout << "Names starting with '" << startChar << "':\n";
    printItems(filteredNames);

    // List of integers (int)
    std::vector<int> numbers = {5, 10, 15, 20, 25, 30, 35, 40};
    auto isEven = [](int n) { return n % 2 == 0; }; // Lambda to check even numbers
    auto filteredNumbers = searchItems(numbers, isEven);
    std::cout << "Even numbers:\n";
    printItems(filteredNumbers);

    // List of floating-point numbers (double)
    std::vector<double> floatNumbers = {3.14, 1.618, 2.718, 4.669, 6.283, 9.81};
    auto greaterThanFive = [](double n) { return n > 5.0; }; // Lambda for values > 5
    auto filteredFloatNumbers = searchItems(floatNumbers, greaterThanFive);
    std::cout << "Numbers greater than 5:\n";
    printItems(filteredFloatNumbers);

    // List of characters (char)
    std::vector<char> letters = {'a', 'b', 'c', 'd', 'A', 'B', 'C', 'D'};
    auto isUppercase = [](char ch) { return std::isupper(ch); }; // Lambda for uppercase letters
    auto filteredLetters = searchItems(letters, isUppercase);
    std::cout << "Uppercase letters:\n";
    printItems(filteredLetters);

    return 0;
}
