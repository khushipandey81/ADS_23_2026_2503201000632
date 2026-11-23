#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert a node
Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find Minimum
Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Find Maximum
Node* findMax(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// Find Successor
Node* successor(Node* root, int key) {
    Node* succ = NULL;

    while (root != NULL) {
        if (key < root->data) {
            succ = root;
            root = root->left;
        }
        else if (key > root->data) {
            root = root->right;
        }
        else {
            if (root->right != NULL)
                succ = findMin(root->right);
            break;
        }
    }

    return succ;
}

// Find Predecessor
Node* predecessor(Node* root, int key) {
    Node* pred = NULL;

    while (root != NULL) {
        if (key > root->data) {
            pred = root;
            root = root->right;
        }
        else if (key < root->data) {
            root = root->left;
        }
        else {
            if (root->left != NULL)
                pred = findMax(root->left);
            break;
        }
    }

    return pred;
}

// Main Function
int main() {
    Node* root = NULL;
    int n, value, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    if (root == NULL) {
        cout << "BST is empty.";
        return 0;
    }

    cout << "\nMinimum value: " << findMin(root)->data;
    cout << "\nMaximum value: " << findMax(root)->data;

    cout << "\n\nEnter value to find successor and predecessor: ";
    cin >> key;

    Node* succ = successor(root, key);
    Node* pred = predecessor(root, key);

    if (succ != NULL)
        cout << "Successor of " << key << ": " << succ->data << endl;
    else
        cout << "Successor does not exist." << endl;

    if (pred != NULL)
        cout << "Predecessor of " << key << ": " << pred->data << endl;
    else
        cout << "Predecessor does not exist." << endl;

    return 0;
}