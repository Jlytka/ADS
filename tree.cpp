#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;
};

Node* createNode(const string& data) {
    Node* newNode = new Node();

    if (!newNode) {
        cout << "error" << endl;
        return nullptr;
    }

    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = createNode("+");
    root->left = createNode("*");
    root->left->left = createNode("+");
    root->left->left->left = createNode("c");
    root->left->left->right = createNode("b");
    root->left->right = createNode("+");
    root->left->right->left = createNode("a");
    root->left->right->right = createNode("c");

    root->right = createNode("+");
    root->right->left = createNode("b");
    root->right->right = createNode("^");
    root->right->right->left = createNode("c");
    root->right->right->right = createNode("2");

    cout << "Tree traversal in preorder: ";
    preorder(root);
    cout << endl;

    cout << "Tree traversal in postorder: ";
    postorder(root);
    cout << endl;

    cout << "Tree traversal in inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}
