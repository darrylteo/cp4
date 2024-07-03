#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // all 5 subject same then count as same

    int n;
    cin >> n;
    unordered_map<string, int> frosh;
    vector<int> tmp(5);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> tmp[0] >> tmp[1] >> tmp[2] >> tmp[3] >> tmp[4];
        sort(tmp.begin(), tmp.end());
        s = to_string(tmp[0]) + to_string(tmp[1]) + to_string(tmp[2]) + to_string(tmp[3]) + to_string(tmp[4]);
        ++frosh[s];
    }
    int mx = 0, cnt = 0;
    // new way to single pass count max and get count
    for (auto &i: frosh) {
        if (i.second > mx) {
            mx = i.second;
            cnt = 0;
        }
        if (i.second == mx) {
            cnt += i.second;
        }
    }
    cout << cnt << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
