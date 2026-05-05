#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Inorder to verify BST
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int values[] = {4, 45, 25, 65, 10, 30};
    int n = 6;

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
        cout << "After inserting " << values[i] << ": ";
        inorder(root);   // shows tree in sorted form
        cout << endl;
    }

    return 0;
}