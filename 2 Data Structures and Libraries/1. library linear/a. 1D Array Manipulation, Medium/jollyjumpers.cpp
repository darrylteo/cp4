#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    while (cin >> n) {
        vector<int> v, vdiff;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        for (int i = 0; i < n - 1; i++) {
            vdiff.push_back(abs(v[i + 1] - v[i]));
        }
        bool jolly = true;
        sort(vdiff.begin(), vdiff.end());
        for (int i = 0; i < n - 1; i++) {
            if (vdiff[i] != i + 1) {
                jolly = false;
                break;
            }
        }
        if (jolly) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }

    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
