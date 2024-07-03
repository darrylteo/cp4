#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    int n;
    while (cin >> n, n) {
        vector<int> v;
        v.assign(100, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v[x]++;
        }
        n--; // to avoid extra space
        for (int i = 0; i < 100; i++) {
            while (v[i]--) {
                cout << i;
                if (n) cout << " ";
                n--;
            }
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
