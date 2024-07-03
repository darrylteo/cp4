#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n), vIdx(n);
    for (int &i: v) cin >> i;
    iota(vIdx.begin(), vIdx.end(), 0);
    int idx = 0, flag;
    while (v.size() > 1) {
        idx = (idx + v[idx] - 1) % v.size();
        if (idx == v.size() - 1) flag = 1;
        else flag = 0;
        v.erase(v.begin() + idx);
        vIdx.erase(vIdx.begin() + idx);
        if (flag) idx = 0;
    }
    cout << vIdx[0] + 1 << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

