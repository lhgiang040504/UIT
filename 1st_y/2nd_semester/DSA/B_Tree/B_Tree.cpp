#include <iostream>
using namespace std;

// Class representing a node of the B-tree
class BTreeNode {
    int *keys;  // Array of keys
    int t;      // Minimum degree (defines the range for number of keys)
    BTreeNode **children; // Array of child pointers
    int n;     // Current number of keys
    bool leaf; // Is true when node is a leaf, false otherwise

public:
    BTreeNode(int t, bool leaf);

    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
    void traverse();

    friend class BTree;
};

// Class representing the B-tree
class BTree {
    BTreeNode *root; // Pointer to the root node
    int t;           // Minimum degree (defines the range for number of keys)

public:
    BTree(int t) {
        root = nullptr;
        this->t = t;
    }

    void traverse() {
        if (root != nullptr)
            root->traverse();
    }

    void insert(int k);
};

BTreeNode::BTreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;

    keys = new int[2 * t - 1];
    children = new BTreeNode *[2 * t];

    n = 0;
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            children[i]->traverse();
        cout << " " << keys[i];
    }

    if (leaf == false)
        children[i]->traverse();
}

void BTree::insert(int k) {
    if (root == nullptr) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            BTreeNode *s = new BTreeNode(t, false);
            s->children[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->children[i]->insertNonFull(k);

            root = s;
        } else
            root->insertNonFull(k);
    }
}

void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf == true) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        n = n + 1;
    } else {
        while (i >= 0 && keys[i] > k)
            i--;

        if (children[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, children[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        children[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (y->leaf == false) {
        for (int j = 0; j < t; j++)
            z->children[j] = y->children[j + t];
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
        children[j + 1] = children[j];

    children[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];

    n = n + 1;
}

int main() {
    BTree tree(3);

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    cout << "Traversal of the constructed B-tree:\n";
    tree.traverse();
    cout << endl;

    return 0;
}
