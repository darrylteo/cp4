#include <bits/stdc++.h>

using namespace std;

// ref: https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/

class node {
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int data) {
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

node *constructTreeUtil(int pre[], int *preIndex, int key, int min, int max, int size) {
    if (*preIndex >= size) return nullptr;
    node *root = nullptr;
    if (key > min && key < max) {
        root = newNode(key);
        *preIndex = *preIndex + 1;
        if (*preIndex < size) {
            root->left = constructTreeUtil(pre, preIndex, pre[*preIndex], min, key, size);
        }
        if (*preIndex < size) {
            root->right = constructTreeUtil(pre, preIndex, pre[*preIndex], key, max, size);
        }
    }
    return root;
}

node *constructTree(int pre[], int size) {
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, pre[0],INT_MIN, INT_MAX, size);
}

void printInorder(node *node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPostorder(node *node) {
    if (node == nullptr) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << "\n";
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int pre[10005];
    int n, idx = 0;
    while (cin >> n) {
        pre[idx++] = n;
    }
    node *root = constructTree(pre, idx);
    printPostorder(root);

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
