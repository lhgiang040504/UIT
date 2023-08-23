#include <iostream>
using namespace std;

#define MAX 500

class queue {
private:
    int Data[MAX];
    int head, tail;
public:
    queue(){
        head = 0;
        tail = 0;
    }
    bool empty();
    void pop();
    void push(int i);
    int top();
};

bool queue::empty() {   return head = tail;     }
void queue::pop() {  head ++;    }
void queue::push( int i){
    Data[tail] = i;
    tail ++;
}
int queue::top() {  return Data[tail - 1];   }
int main(){
    queue s;
    s.push(3);
    s.push(2);
    s.push(1);
    cout << s.top(); s.pop(); cout << ' ' << s.empty() << endl;
    cout << s.top(); s.pop(); cout << ' ' << s.empty() << endl;
    s.push(4);
    s.push(5);
    cout << s.top(); s.pop(); cout << ' ' << s.empty() << endl;
    cout << s.top(); s.pop(); cout << ' ' << s.empty() << endl;
    cout << s.top(); s.pop(); cout << ' ' << s.empty() << endl;
    return 0;
}
