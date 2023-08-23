#include <iostream>
using namespace std;
#define MAX 500
class stack{
private:
    int Data[MAX];
    int nTop;
public:
    stack(){
        Data[0] = 0;
        nTop = 0;   }
    bool empty();
    void pop();
    void push(int i);
    int top();
};
bool stack::empty(){
    return Data[nTop] == 0;   }
void stack::pop(){
    Data[nTop] = 0;
    nTop --;    }
void stack::push(int i){
    nTop ++; 
    Data[nTop] = i; }
int stack::top(){
    return Data[nTop];  }

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top(); s.pop(); cout << ' ' << s.empty() << endl;
    cout << s.top(); s.pop(); cout << ' ' << s.empty() << endl;
    s.push(4);
    s.push(5);
    cout << s.top(); s.pop(); cout << ' ' << s.empty() << endl;
    cout << s.top(); s.pop(); cout << ' ' << s.empty() << endl;
    cout << s.top(); s.pop(); cout << ' ' << s.empty() << endl;
    return 0;
}
