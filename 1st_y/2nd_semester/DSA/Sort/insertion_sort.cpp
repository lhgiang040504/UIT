#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void insertion_sort_p1(int *arr, int n){
    int initial = 1;
    while(initial < n){
        int max = initial;
        for(int i = initial - 1; i > -1; i--)
            if(arr[max] < arr[i]){
               swap(arr[max], arr[i]);
               max = i;
            }
            else break;
        initial ++;  
    }
}

void insertion_sort_p2(int *a, int n){
    int i = 0;
    while(i < n - 1){
        if(a[i] > a[i+1]) {
            swap(a[i], a[i+1]);
            i --;
        }
        else
            i ++;
        if (i < 0) i = 0;
    }
}

void output(int *arr, int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}

int main(){
    int arr[] = {5, 7, 1, 6, 3, 8, 0, 4, 2};
    int n = sizeof(arr) / sizeof(int);
    insertion_sort_p2(arr, n);
    output(arr, n);
    return 0;
}

/*
n is the number of element, complexity

p1:
    best-case scenario: O(n) no swaps are necessary
    worst case scenerio: O(n^2), all elements need to be sorted
    
*/