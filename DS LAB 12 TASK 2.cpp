#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inorder (LNR)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder (NLR)
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder (LRN)
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // Manually creating the given tree
    Node* root = createNode(6);
    root->left = createNode(3);
    root->right = createNode(10);
    root->left->left = createNode(2);
    root->left->right = createNode(5);

    cout << "Inorder (LNR): ";
    inorder(root);

    cout << "\nPreorder (NLR): ";
    preorder(root);

    cout << "\nPostorder (LRN): ";
    postorder(root);

    return 0;
}