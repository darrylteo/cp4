#include <iostream>

using namespace std;

int search(const int arr[], int x, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

void printPostOrder(int in[], int pre[], int n) {
    int root = search(in, pre[0], n);
    if (root != 0) printPostOrder(in, pre + 1, root);
    if (root != n - 1) printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
    cout << (char) (pre[0] + 'A');
}

// template from https://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int in[30], pre[30];
    int n;
    string s;
    while (cin >> s) {
        n = s.length();
        for (int i = 0; i < n; i++) pre[i] = s[i] - 'A';
        cin >> s;
        for (int i = 0; i < n; i++) in[i] = s[i] - 'A';
        printPostOrder(in, pre, n);
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
