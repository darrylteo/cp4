#include <bits/stdc++.h>

using namespace std;

// always combine 2 smallest items

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n, n) {

        long long ans = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            pq.push(x);
        }
        while (pq.size() > 1) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        cout << ans << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
