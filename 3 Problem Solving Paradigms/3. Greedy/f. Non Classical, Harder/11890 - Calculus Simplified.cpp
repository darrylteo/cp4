#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i: v) cin >> i;
        sort(v.begin(), v.end());
        // record how many minus in this nested expression.
        // count how many x are minus and plus
        int negative = 0, minusCnt = 0, plusCnt = 0;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (i != 0 && s[i-1] == '-') {
                    st.push(1);
                    negative++;
                } else {
                    st.push(0);
                }
            } else if (s[i] == ')') {
                if (st.top() == 1) {
                    negative--;
                }
                st.pop();
            } else if (s[i] == 'x') {
                if (i != 0 && s[i-1] == '-') {
                    if (negative % 2 == 0) {
                        minusCnt++;
                    } else {
                        plusCnt++;
                    }
                } else {
                    if (negative % 2 == 0) {
                        plusCnt++;
                    } else {
                        minusCnt++;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < minusCnt; i++) {
            ans -= v[i];
        }
        for (int i = minusCnt; i < v.size(); i++) {
            ans += v[i];
        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
