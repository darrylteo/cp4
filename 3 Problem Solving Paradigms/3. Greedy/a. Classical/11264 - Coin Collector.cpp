#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        // pick first coin always
        int x, currTotal = 0, ans = 1, tmp;
        vector<int> v;
        cin >> x;
        while (x--) {
            cin >> tmp;
            v.push_back(tmp);
        }
        // accept coin if it is a possible "coin change" from next coin
        for (int i = 0; i < v.size() - 1; ++i) {
            if (currTotal + v[i] < v[i + 1]) {
                ans++;
                currTotal += v[i];
            }
        }
        cout << ans << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
