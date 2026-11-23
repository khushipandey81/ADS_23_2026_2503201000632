#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Find minimum value
Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Find maximum value
Node* findMax(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// Find inorder successor
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

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    // Creating the given BST
    Node* root = new Node(50);

    root->left = new Node(25);
    root->right = new Node(75);

    root->left->left = new Node(15);
    root->left->right = new Node(30);

    root->left->left->left = new Node(10);
    root->left->right->right = new Node(35);

    root->right->left = new Node(60);
    root->right->right = new Node(90);
    root->right->right->right = new Node(99);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nMinimum Value: "
         << findMin(root)->data;

    cout << "\nMaximum Value: "
         << findMax(root)->data;

    int key = 50;
    Node* s = successor(root, key);

    if (s != NULL)
        cout << "\nSuccessor of " << key
             << " is: " << s->data;
    else
        cout << "\nNo Successor exists";

    return 0;
}