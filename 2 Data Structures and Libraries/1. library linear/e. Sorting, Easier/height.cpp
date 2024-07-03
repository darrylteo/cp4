#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    for (int caseCnt = 1; caseCnt <= T; ++caseCnt) {
        cout << caseCnt << " ";
        int n;
        vector<int> v(20);
        cin >> n;
        for (int i = 0; i < 20; ++i) {
            cin >> v[i];
        }
        int steps = 0;
        for (int j = 0; j < 19; ++j) {
            for (int i = 0; i < 19; ++i) {
                if (v[i] > v[i+1]) {
                    swap(v[i], v[i+1]);
                    ++steps;
                }
            }
        }
        cout << steps << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
