#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    vector<int> v;
    int n;
    for (int i = 0; i < 5; ++i) {
        cin >> n;
        v.push_back(n);
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                for (int k: v) {
                    cout << k << " ";
                }
                cout << endl;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
