#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
// find the element has less value end constant swap.
// note that the order of elements that have same value is changed. (interchange vs bubble)
// unstable sorting.
void interchange_sort(int *arr, int n){
    int initial = 0, min;
    while (initial < n - 1){
        for (int i = initial + 1; i < n; i++)
            if (arr[initial] > arr[i])
                swap(arr[initial], arr[i]);
        initial ++;
    }
}
void output(int *arr, int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}


int main(){
    int arr[] = {5, 7, 1, 6, 3, 8, 0, 6, 2};
    int n = sizeof(arr) /  sizeof(int);
    selection_sort(arr, n);
    output(arr, n);
    return 0;
}