#include <iostream>
using namespace std;
struct SinglyLinkedListNode{
    int data;
    SinglyLinkedListNode *next;
};
SinglyLinkedListNode* create_node(int node_data){
    SinglyLinkedListNode* p = new SinglyLinkedListNode();
    p -> data = node_data;
    p -> next = nullptr;
    return p;
}
class stack{
private:
    SinglyLinkedListNode* head ;
    SinglyLinkedListNode* tail ;
public:
    stack(){
        SinglyLinkedListNode* head = nullptr;
        SinglyLinkedListNode* tail = nullptr;
    }
    bool empty();
    void push(int data);
    void pop();
    int top();
};
bool stack::empty(){
    if(head == NULL) return true;
    return false;
}
void stack::push(int data){
    SinglyLinkedListNode* new_node = create_node(data);
    if (this->head == nullptr) {
        this->head = new_node;
    }
    else {
        SinglyLinkedListNode* current = this->head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
}
void stack::pop() {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    SinglyLinkedListNode* second_last = head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    delete second_last->next;
    second_last->next = NULL;
}
int stack::top(){
    if (this->head == nullptr) {
        return -1; // Or some other value indicating an error
    }
    SinglyLinkedListNode* current = this -> head;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current->data;
}
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top(); s.pop(); cout << " " << s.empty() << endl;
    cout << s.top(); s.pop(); cout << " " << s.empty() << endl;
    s.push(4);
    s.push(5);
    cout << s.top(); s.pop(); cout << " " << s.empty() << endl;
    cout << s.top(); s.pop(); cout << " " << s.empty() << endl;
    cout << s.top(); s.pop(); cout << " " << s.empty() << endl;
    return 0;
}