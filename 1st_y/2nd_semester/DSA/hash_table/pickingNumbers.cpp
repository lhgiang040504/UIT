#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
    int n = a.size();
    vector<int> count(101, 0); // Initialize count array with size 101

    // Count the frequency of each number
    for (int i = 0; i < n; i++)
        count[a[i]]++;

    int maxLength = 0;

    // Iterate through the count array and find the maximum length subarray
    for (int i = 1; i <= 100; i++)
        maxLength = max(maxLength, count[i] + count[i - 1]);
        
    return maxLength;
/*
    int n = a.size();
    unordered_map<int, int> count;

    // Count the frequency of each number
    for (int i = 0; i < n; i++)
        count[a[i]]++;

    int maxLength = 0;

    // Iterate through the count map and find the maximum length subarray
    for (auto it = count.begin(); it != count.end(); ++it) {
        int curr = it->first;
        int currCount = it->second;

        maxLength = max(maxLength, currCount);

        if (count.find(curr + 1) != count.end())
            maxLength = max(maxLength, currCount + count[curr + 1]);
    }

    return maxLength;
*/
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

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
