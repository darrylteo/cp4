#include <bits/stdc++.h>

using namespace std;

// naive solution of updating the array to mark which are dead is TLE
// do doubly linked list instead ._.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int S, B;
    while (cin >> S >> B, S) {
        int prev[100000], next[100000]; // "data" is index
        for (int i = 0; i < S; ++i) {
            prev[i] = (i - 1);
            next[i] = (i + 1);
        }
        prev[0] = -1;
        next[S - 1] = -1;
        while (B--) {
            int L, R;
            cin >> L >> R;
            --L; --R; // 0 indexed
            int left = prev[L]; // the prev alive guy to left (could be far away but dll takes care of it)
            int right = next[R]; // next alive guy to right
            if (left == -1) cout << "* ";
            else {
                next[left] = right;
                cout << left + 1 << " ";
            }
            if (right == -1) cout << "*\n";
            else {
                prev[right] = left;
                cout << right + 1 << "\n";
            }
        }
        cout << "-" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
