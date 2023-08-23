#include <iostream>
#include <algorithm>
using namespace std;

struct frac{
    int nume;
    int deno;
};

istream& operator >> (istream& in, frac& p){
        in >> p.nume;
        in >> p.deno;
        while (p.deno == 0)
            in >> p.deno;// only denomination
        return in;
}
ostream& operator << (ostream& out, frac& p) {
        return out << p.nume << '/' << p.deno << endl;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void sort(frac *arr, int n){
    int min, index = 0;
    while(index < n){
        min = index;
        for(int i = index + 1; i < n; i++){
            if (arr[i].nume/float(arr[i].deno) < arr[min].nume/float(arr[min].deno)) 
                min = i;
        }
        swap(arr[index], arr[min]);
        index ++;
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    if(n == 0) return 0;
    frac *arr = new frac[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, n);
    if (n-k >= 0)
        cout << arr[n - k];
    if (k-1 < n)
        cout << arr[k - 1];
    return 0;
}