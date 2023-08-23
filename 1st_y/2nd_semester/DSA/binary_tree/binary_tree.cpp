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
// ----------
    int balanceFactor(Node* curr) {
        if (curr == NULL)
            return 0;
        return curr->left->height - curr->right->height;
    }
    Node* rightRotate(Node* root) {
        Node* temp = root->left->right;
        Node* newRoot = root->left;
        
        newRoot->right = root;
        root->left = temp;

        return newRoot;
    }
    Node* leftRotate(Node* root) {
        Node* temp = root->right->left;
        Node* newRoot = root->right;
        
        newRoot->left = root;
        root->right = temp;

        return newRoot;
    }
    Node* left_rightRotate (Node* root) {
        Node* middleNode = root->left->right;
        Node* temp = middleNode->left;

        middleNode->left = root->left;
        root->left = middleNode;
        middleNode->left->right = temp;

        return root;
    }
    Node* right_leftRotate (Node* root) {
        Node* middleNode = root->right->left;
        Node* temp = middleNode->right;
        
        middleNode->right = root->right;
        root->right = middleNode;
        middleNode->right->left = temp;

        return root;
    }
    Node* avlInsert(Node* curr, int val) {
        if (curr == NULL)
            return new Node(val);
        else if (val <= curr->data)
            curr->left = avlInsert(curr->left, val);
        else
            curr->right = avlInsert(curr->right, val);

        curr->height = 1 + max(curr->left->height, curr->right->height);

        int bf = balanceFactor(curr);

        if (bf > 1) {
            if (val > curr->left->data) 
                curr = left_rightRotate(curr);
            return rightRotate(curr);
        }
        else if (bf < -1) {
            if (val < curr->right->data)
                curr = right_leftRotate(curr);
            return leftRotate(curr);
        }        
        return curr;
    }
// ----------
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
        root = avlInsert(root, val);
    }
// ----------
    void topView() {
        if (root == nullptr) 
            return;
        
        int horizCorr;
        Node *curr;
        queue<pair<Node*, int>> q;
        map<int, int> listResult;
        q.push({root, 0});

        while (!q.empty()) {
            horizCorr = q.front().second;
            curr = q.front().first;
            q.pop();
            
            if (listResult.find(horizCorr) == listResult.end())
                listResult[horizCorr] = curr->data;
            
            if (curr->left != nullptr)
                q.push({curr->left, horizCorr - 1});
            if (curr->right != nullptr)
                q.push({curr->right, horizCorr + 1});
        }

        for (const auto& iter : listResult)
            cout << iter.second << " ";
    }
// ----------
    int recurHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return max(recurHeight(node->left), recurHeight(node->right)) + 1;
    }
    int unrecurHeight(Node* root) {
        if (root == nullptr)
            return 0;

        queue<Node*> q;
        q.push(root);
        int height = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size > 0) {
                Node* curr = q.front();
                q.pop();

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);

                size--;
            }

            height++;
        }

        return height;
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

    tree.topView();

    return 0;
}