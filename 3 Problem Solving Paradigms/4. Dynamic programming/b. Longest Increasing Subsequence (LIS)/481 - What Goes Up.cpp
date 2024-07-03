#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n;
vi A, p, ans;

void print_LIS(int i) {                          // backtracking routine
    if (p[i] == -1) {
        ans.push_back(A[i]);
        return;
    }
    print_LIS(p[i]);                               // backtrack
    ans.push_back(A[i]);
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int x;
    while (cin >> x) {
        A.push_back(x);
    }

    n = A.size() + 1;
    int k = 0, lis_end = 0;
    vi L(n, 0), L_id(n, 0);
    p.assign(n, -1);
    A.push_back(INT_MAX);

    for (int i = 0; i < n; ++i) { // O(n log k)
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        L[pos] = A[i]; // greedily overwrite this
        L_id[pos] = i; // remember the index too
        p[i] = pos ? L_id[pos - 1] : -1; // predecessor info
        if (pos == k) { // can extend LIS?
            k = pos + 1; // k = longer LIS by +1
            lis_end = i; // keep best ending i
        }
    }

    cout << k - 1 << "\n-\n";
    print_LIS(lis_end);
    for (int i = 0; i < ans.size() - 1; ++i) {
        cout << ans[i] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
