//AVL stands for Adelson-Velsky and Landi
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    int height;

    // Constructor
    Node(int val) {
        this->data = val;
        this->left = nullptr; // nullptr : has own type
        this->right = nullptr; // NULL : is an integer or a literal '0'
        this->height = 1;
    }
};
class binaryTree{
private:
    Node* root;

    Node* recurInsert(Node* curr, int val) {
        if (curr == nullptr)
            return new Node(val);
        
        if (val <= curr->data)
            curr->left = recurInsert(curr->left, val);
        else
            curr->right = recurInsert(curr->right, val);

        return curr;
    }
    Node* unrecurInsert(int val) {
        if (root == nullptr)
            return new Node(val);
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            if (val <= curr->data) {
                if (curr->left == nullptr) 
                    curr->left = new Node(val);
                else
                    q.push(curr->left);
            }
            else {
                if (curr->right == nullptr) 
                    curr->right = new Node(val);
                else
                    q.push(curr->right);
            }
        }
        return root;
    }
// ----------
    Node* deleteNode(Node* curr, int val) {
        if (curr == nullptr)
            return nullptr;

        if (val < curr->data)
            curr->left = deleteNode(curr->left, val);
        else if (val > curr->data)
            curr->right = deleteNode(curr->right, val);
        else {
            if (curr->left == nullptr && curr->right == nullptr) {
                delete curr;
                return nullptr;
            }
            else if (curr->left == nullptr) {
                Node* temp = curr->right;
                delete curr;
                return temp;
            }
            else if (curr->right == nullptr) {
                Node* temp = curr->left;
                delete curr;
                return temp;
            }
            else {
                Node* successor = findMinNode(curr->right);
                curr->data = successor->data;
                curr->right = deleteNode(curr->right, successor->data);
            }
        }
        return curr;
    }
    // We can use another method is find max valu in left child
    // Here i use method is find min value of right child
    Node* findMinNode(Node* curr) {
        while (curr->left != nullptr) {
            curr = curr->left;
        }
        return curr;
    }    
// ----------
    // Traversal functions
    void printLRN(Node* curr) {
        if (curr == nullptr)
            return;
        
        printLRN(curr->left);
        printLRN(curr->right);
        cout << curr->data << " ";
    }

    void printNRL(Node* curr) {
        if (curr == nullptr)
            return;

        cout << curr->data << " ";
        printNRL(curr->right);
        printNRL(curr->left);
    }
    // Decrease
    void printRNL(Node* curr) {
        if (curr == nullptr)
            return;

        printRNL(curr->right);
        cout << curr->data << " ";
        printRNL(curr->left);
    }
    // Increase
    void printLNR(Node* curr) {
        if (curr == nullptr)
            return;

        printLNR(curr->left);
        cout << curr->data << " ";
        printLNR(curr->right);
    }

    void deleteTree(Node* node) {
        if (node == nullptr)
            return;

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    binaryTree() {
        root = nullptr;
    }

    ~binaryTree() {
        deleteTree(root);
    }
// ----------
    void insert(int val) {
        root = recurInsert(root, val);
    }

    void remove(int val) {
        root = deleteNode(root, val);
    }

    void printLRN() {
        printLRN(root);
        cout << endl;
    }

};

int main() {
    binaryTree tree;

    tree.insert(2);
    tree.insert(1);
    tree.insert(5);
    tree.insert(6);
    tree.insert(3);
    tree.insert(4);



    return 0;
}