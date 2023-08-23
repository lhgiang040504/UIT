#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int basic(string s){
    float num;
    vector<int> nums;
    vector<char> opers;
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s[i])){
            num = s[i]-'0';
            while(isdigit(s[i+1])){
                num = num*10 + (s[i+1]-'0');
                i++;
            }
            nums.push_back(num);
        }
        else if(s[i] == '*' || s[i] == ':' || s[i] == '+' || s[i] == '-')
            opers.push_back(s[i]);
    }
    for(int i = 0; i < opers.size(); i++){
        if(opers[i] == '*') {    nums[i] = nums[i] * nums[i+1];    }
        else if(opers[i] == ':') {    nums[i] = float(nums[i]) / nums[i+1];    }
        
        nums.erase(nums.begin() + i + 1);
        opers.erase(opers.begin() + i);
        i--;
    }
    int result = nums[0];
    for (int i = 0; i < opers.size(); i++) {
        if (opers[i] == '+')
            result += nums[i + 1];
        else if (opers[i] == '-')
            result -= nums[i + 1];
    }
    return result;
}


string extractParenthesis(string expr) {
    stack<int> s;
    string result = "";
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(') {
            s.push(i);
        }
        else if (expr[i] == ')') {
            // get the deepest parenthesis
            int start = s.top();
            s.pop();
            string contents = expr.substr(start + 1, i - start - 1);
            // get the ressult and cast to string type
            int value = basic(contents);
            string strValue = to_string(value);
            
            // replace contents inside parenthesis (both parenthesis)
            expr.replace(start, i - start + 1, strValue);
            i = start + strValue.length() - 1;
        }
    }
    return expr;
}
int main()
{
    string result = extractParenthesis(s);
    while (result != s) {
        s = result;
        result = extractParenthesis(s);
    }

    // Evaluate the final expression
    cout << basic(s);

    return 0;
}
