#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, P;
    cin >> W >> P;
    vector<int> cuts(P + 2);
    cuts[0] = 0;
    cuts[P + 1] = W;
    for (int i = 1; i <= P; ++i) {
        cin >> cuts[i];
    }
    set<int> ans;
    for (int i = 0; i < cuts.size(); ++i) {
        for (int j = i + 1; j < cuts.size(); ++j) {
            ans.insert(cuts[j] - cuts[i]);
        }
    }
    for (auto &x: ans) {
        cout << x << " ";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}