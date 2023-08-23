#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
// find the element has min value end swap with the bot element
void selection_sort(int *arr, int n){
    int initial = 0, min;
    while (initial < n - 1){
        min = initial;
        for (int i = initial + 1; i < n; i++)
            if (arr[min] > arr[i])
                min = i;
        swap(arr[min], arr[initial]);
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