#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'beautifulPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY A
 *  2. INTEGER_ARRAY B
 */

int beautifulPairs(vector<int> A, vector<int> B) {
    unordered_map<int, int> freq_A, freq_B;
    
    // Count the frequency of each element in A and B
    for (int num : A)
        freq_A[num]++;
    for (int num : B)
        freq_B[num]++;
    
    int pairs = 0;
    
    // Calculate the count of common elements between A and B
    for (const auto& pair : freq_A) {
        int num = pair.first;
        pairs += min(pair.second, freq_B[num]);
    }
    
    // If we can change an element in A that is not part of any beautiful pair,
    // the count of beautiful pairs increases by 1
    if (pairs < A.size())
        pairs++;
    else
        pairs--; // Reduce the count by 1 to keep the pairs disjoint
    
    return pairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    string B_temp_temp;
    getline(cin, B_temp_temp);

    vector<string> B_temp = split(rtrim(B_temp_temp));

    vector<int> B(n);

    for (int i = 0; i < n; i++) {
        int B_item = stoi(B_temp[i]);

        B[i] = B_item;
    }

    int result = beautifulPairs(A, B);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
