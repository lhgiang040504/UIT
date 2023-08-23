#include <iostream>
using namespace std;
#include <vector>
#define hashTableSize 27
vector<string> hashTable[hashTableSize];

int hashFunc(string s) {
    return s[0] - 'a';
}

void insert(string s) {
    int index = hashFunc(s);
    hashTable[index].push_back(s);
}

bool search(string s) {
    int index = hashFunc(s);
    for(auto i : hashTable[index])
        if(i == s) 
            return true;
    return false;
}

int main() {

    insert("strawberry");
    insert("banana");
    insert("mango");
    insert("watermelon");
    insert("apple");
    insert("grapes");
    insert("kiwi");
    insert("coconut");
    insert("cantaloupe");
    insert("melon");
    insert("cherry");

    cout << search("kiwi") << endl;
    cout << search("mango") << endl;
    cout << search("melon") << endl;
    cout << search("chery") << endl;
    cout << search("cherry") << endl;
    cout << search("coconut") << endl;
    cout << search("cantaloupe") << endl;
    
    return 0;
}