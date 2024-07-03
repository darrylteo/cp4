#include <bits/stdc++.h>

using namespace std;

// if want compare each tree against each other: https://stackoverflow.com/questions/24368565/find-two-binary-tree-are-structurally-identical?rq=3
// writing bst: https://stackoverflow.com/questions/5085091/binary-search-tree-implementation-in-c-stl
// i compare how many left and right nodes at each level

set<set<string>> s; // string will be l1, r1 means left level 1, right level 1.
set<string> tmpSet;
string tmpString;

struct node {
    int val;
    node* left;
    node* right;
};

node* createNewNode(int x)
{
    node* nn = new node;
    nn->val = x;
    nn->left  = nullptr;
    nn->right = nullptr;

    return nn;
}

void bstInsert(node* &root, int x)
{
    if(root == nullptr) {
        root = createNewNode(x);
        return;
    }

    if(x < root->val)
    {
        tmpString += "l";
        if(root->left == nullptr) {
            root->left = createNewNode(x);
            return;
        } else {
            bstInsert(root->left, x);
        }
    }

    if( x > root->val )
    {
        tmpString += "r";
        if(root->right == nullptr) {
            root->right = createNewNode(x);
            return;
        } else {
            bstInsert(root->right, x);
        }
    }
}

// nothing special since the bst was given in ref.
// just added a string to say where we go e.g. lllrr or llr etc

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        node* root = nullptr;
        tmpSet.clear();
        for (int j = 0; j < k; ++j) {
            tmpString = "";
            int x;
            cin >> x;
            bstInsert(root, x);
            tmpSet.insert(tmpString);
        }
        s.insert(tmpSet);
    }
    cout << s.size() << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
