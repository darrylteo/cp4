#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    while (T--){
        int M, D, tmp;
        vector<int> d;
        cin >> D >> M;
        for (int i = 0; i < M; ++i) {
            cin >> tmp;
            d.push_back(tmp);
        }
        int ans = 0, day = 0;
        for (int i = 0; i < M; ++i) {
            // if first day of month is sunday. 13th day is friday
            if (day%7 == 0) {
                if (d[i] >= 13) {
                    ans++;
                }
            }
            // advance clock
            day += d[i];
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}