#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>
using namespace std;

int main() {
    vector<string> strings = {"apple", "banana", "orange"};

    unordered_map<string, size_t> encodedMap;

    // Encoding the vector
    for (size_t i = 0; i < strings.size(); ++i) {
        encodedMap[strings[i]] = i;
    }

    // Accessing the encoded map
    try {
        cout << "Index of 'apple': " << encodedMap.at("apple") << std::endl;
        cout << "Index of 'banana': " << encodedMap.at("banana") << std::endl;
        cout << "Index of 'orange': " << encodedMap.at("orange") << std::endl;
        cout << "Index of 'grape': " << encodedMap.at("grape") << std::endl; // Throws an exception
    } catch (const std::out_of_range& e) {
        cout << "Error: " << e.what() << std::endl;
    }
    
    cout << encodedMap["orange"];
    return 0;
}
