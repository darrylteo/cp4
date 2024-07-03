#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n;
vi A, p;

void print_LIS(int i) {                          // backtracking routine
    if (p[i] == -1) { cout << A[i]; return; }// base case
    print_LIS(p[i]);                               // backtrack
    cout << " " << A[i];
}

// used code from book, and just added sort

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);

    while (cin >> n, n) {
        n++;
        int k = 0, lis_end = 0;
        vi L(n, 0), L_id(n, 0);
        p.assign(n, -1);
        A.resize(n);
        for (int i = 0; i < n-1; ++i) cin >> A[i];
        A[n-1] = INT_MAX;

        for (int i = 0; i < n; ++i) { // O(n log k)
            int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
            L[pos] = A[i]; // greedily overwrite this
            L_id[pos] = i; // remember the index too
            p[i] = pos ? L_id[pos-1] : -1; // predecessor info
            if (pos == k) { // can extend LIS?
                k = pos+1; // k = longer LIS by +1
                lis_end = i; // keep best ending i
            }
        }


        int bestK = k;
         k = 0, lis_end = 0;
        L.assign(n, 0), L_id.assign(n, 0);
        p.assign(n, -1);
        vector<vector<int>> possibleAns;
        for (int i = 0; i < n; ++i) { // O(n log k)
            int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
            L[pos] = A[i]; // greedily overwrite this
            L_id[pos] = i; // remember the index too
            p[i] = pos ? L_id[pos-1] : -1; // predecessor info
            if (pos == k) { // can extend LIS?
                k = pos+1; // k = longer LIS by +1
                lis_end = i; // keep best ending i
            }
            if (k == bestK) {
                vector<int> ans;
                int j = lis_end;
                while (p[j] != -1) {
                    ans.push_back(A[j]);
                    j = p[j];
                }
                ans.push_back(A[j]);
                possibleAns.push_back(ans);
            }
        }
        cout << bestK - 1 << " ";
        sort(possibleAns.begin(), possibleAns.end());
        for (int i = bestK - 1; i > 0; --i) {
            cout << possibleAns[0][i] << " ";
        }
        cout << "\n";

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
