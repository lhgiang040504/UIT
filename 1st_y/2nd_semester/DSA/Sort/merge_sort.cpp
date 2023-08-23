#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sort(vector<int> subVector_l, vector<int> subVector_r){
    vector<int> result;
    int i = 0, j = 0;
    while (i < subVector_l.size() && j < subVector_r.size() ){
        if (subVector_l[i] < subVector_r[j]){
            result.push_back(subVector_l[i]);
            i++;
        }
            
        if (subVector_l[i] >= subVector_r[j]){
            result.push_back(subVector_r[j]);
            j ++;
        }
    }
    result.insert(result.end(), subVector_l.begin() + i, subVector_l.end());
    result.insert(result.end(), subVector_r.begin() + j, subVector_r.end());
    return result;
}


vector<int> divide(vector<int> rootVector){
    vector<int> result;
    if (rootVector.size() == 1) return rootVector;
    
    vector<int> subVector_l(rootVector.begin() , rootVector.begin() + rootVector.size()/2);
    vector<int> subVector_r(rootVector.begin() + rootVector.size()/2, rootVector.end());
    subVector_l = divide(subVector_l);
    subVector_r = divide(subVector_r);
    
    result = merge_sort(subVector_l, subVector_r);
    return result;
}

void output(vector<int> v){
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
}

int main(){
    vector<int> arr = {5, 7, 1, 6, 3, 8, 0, 4, 2, 8};
    vector<int> result;
    result = divide(arr);
    output(result);
    return 0;
}
/*
    Time Complexity: O(n log(n))
    
    Space Complexity: O(n)
        Space Complexity:
            Merge Sort has a space complexity of O(n) because it creates temporary vectors during the merging process to store the sorted elements.
            The additional space required is proportional to the size of the input vector.

*/