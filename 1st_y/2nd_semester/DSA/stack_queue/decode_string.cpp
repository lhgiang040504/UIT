#include<iostream>
#include<string>
#include<stack>

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<int> countStack;
        stack<string> resStack;
        int i = 0;
        while (i < s.length()) {
            if (isdigit(s[i])) {
                int count = 0;
                while (isdigit(s[i])) {
                    count = count * 10 + (s[i] - '0');
                    i++;
                }
                countStack.push(count);
            } else if (s[i] == '[') {
                resStack.push(res);
                res = "";
                i++;
            } else if (s[i] == ']') {
                string tmp = resStack.top();
                resStack.pop();
                int repeat = countStack.top();
                countStack.pop();
                for (int j = 0; j < repeat; j++) {
                    tmp += res;
                }
                res = tmp;
                i++;
            } else {
                res += s[i];
                i++;
            }
        }
        return res;
    }

};