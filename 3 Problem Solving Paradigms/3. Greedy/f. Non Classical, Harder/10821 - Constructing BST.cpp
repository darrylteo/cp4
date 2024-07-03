#include <bits/stdc++.h>

using namespace std;

// ref https://algorithmist.com/wiki/UVa_10821_-_Constructing_BST

// height is height of the right subtree i want to make in next call
// if 0 height means a leaf node. -1 means don't make
void BST(int left, int right, int height) {
    if (left > right || height == -1) return;
    int root = right - (pow(2, height) - 1);
    if (root <= left) root = left;
    cout << ' ' << root;
    BST(left, root - 1, height - 1);
    BST(root + 1, right, height - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, H, cases = 1;
    while (cin >> N >> H, N) {
        cout << "Case " << cases++ << ':';
        int nodesRequired = pow(2, H) - 1;
        if (N > nodesRequired) {
            cout << " Impossible." << '\n';
            continue;
        }
        BST(1, N, H-1);
        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
