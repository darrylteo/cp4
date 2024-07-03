#include <bits/stdc++.h>

using namespace std;

bool bs(const vector<long long>& x, long long val) {
    // note from qns mid is "location"
    int l = 0, r = x.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (x[mid] == val) return true;
        else if (x[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, a, c, x0;
    cin >> n >> m >> a >> c >> x0;
    vector<long long> x(n);
    x[0] = (a * x0 + c) % m;
    for (int i = 1; i < n; ++i) {
        x[i] = (a * x[i - 1] + c) % m;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (bs(x,x[i])) ans++;
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

