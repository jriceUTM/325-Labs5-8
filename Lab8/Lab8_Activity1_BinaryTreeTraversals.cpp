#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

static int indx = -1;

Node* buildTree(vector<int> preorder) {
    indx++;

    if (preorder[indx] == -1) {
        return nullptr;
    }

    Node* root = new Node(preorder[indx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void preorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(preorder);

    cout << "Preorder Traversal: " << endl;
    
    preorderTraversal(root);
    cout << endl;

    cout << "In-order Traversal: " << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "Post-Order Traversal: " << endl;
    postorderTraversal(root);
    cout << endl;

    return 0;
}
