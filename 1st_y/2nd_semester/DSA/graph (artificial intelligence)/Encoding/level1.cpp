#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<string> strings = {"apple", "banana", "orange"};

    unordered_map<string, int> encodedMap;

    // Encoding the vector
    for (int i = 0; i < strings.size(); ++i) {
        encodedMap[strings[i]] = i;
    }

    // Accessing the encoded map
    cout << encodedMap["orange"];

    return 0;
}
