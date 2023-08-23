#include <iostream>
using namespace std;

int linearSearch(int A[], int n, int x) {
    int i = 0;
    while (i < n) {
        if (A[i] == x) return i;
        i++;
    }
    return -1;
}

// complexity O(n)