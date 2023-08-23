#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void sort(int *a, int l, int r){
    int x, i, j;
    x = (l+r)/2;
    i = l;
    j = r;
    while (i < j){
        while (a[i] < a[x]) i++;
        while (a[j] > a[x]) j--;
        if(i < j)
            swap(a[i], a[j]);
        i++;
        j--;
    }
    if (l < j) sort(a, l, j);
    if (i < r) sort(a, i, r);
}

void output(int *arr, int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}
int main(){
    int arr[] = {5, 7, 1, 6, 3, 8, 0, 6, 2};
    int n = sizeof(arr)/ sizeof(int);
    sort(arr, 0, n - 1);
    output(arr, n);
    return 0;
}