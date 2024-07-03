#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> A(101), B(101);
    int n;
    cin >> n;
    while (n--) {

        int a, b, max = 0;
        cin >> a >> b;
        A[a]++;
        B[b]++;
        vector<int> ACopy = A, BCopy = B;

        int l = 0, r = 100;
        while (l <= 100 && r >= 0) {
            if (ACopy[l] == 0) {
                l++;
                continue;
            }
            if (BCopy[r] == 0) {
                r--;
                continue;
            }
            if (l + r > max) {
                max = l + r;
            }
            int maxHere = min(ACopy[l], BCopy[r]);
            ACopy[l] -= maxHere;
            BCopy[r] -= maxHere;
        }

        cout << max << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
