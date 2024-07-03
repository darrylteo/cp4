#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    while (cin >> N >> D, N) {
        int cnt = D;
        string s, ans;
        cin >> s;
        // while the next number is greater, remove this number and decrement the count
        for (char c : s) {
            while (cnt && !ans.empty() && ans.back() < c) {
                ans.pop_back();
                cnt--;
            }
            ans.push_back(c);
        }
        // if the count is still greater than 0, remove the last few numbers
        while (cnt--) ans.pop_back();
        cout << ans << '\n';

    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
