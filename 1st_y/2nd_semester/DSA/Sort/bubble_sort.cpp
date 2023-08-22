#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// push the element has max value to the top element.
// note that the order of elements that have same value is not changed. (interchange vs bubble)
// stable sorting.
void bubble_sort(int *arr, int n){
    while (n > 1){
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
        n--;
    }
}

void output(int *arr, int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}

int main(){
    int arr[] = {5, 7, 1, 6, 3, 8, 0, 6, 2};
    int n = sizeof(arr) / sizeof(int);
    bubble_sort(arr, n);
    output(arr, n);
    return 0;
}