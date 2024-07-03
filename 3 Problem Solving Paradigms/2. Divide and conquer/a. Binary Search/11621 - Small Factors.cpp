#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<long long> s;
    // generate all numbers
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            long long num = (1LL << i) * pow(3, j);
            if (num > (1LL << 32)) break;
            s.insert(num);
        }
    }

    int n;
    while (cin >> n, n) {
        auto ans = lower_bound(s.begin(), s.end(), n);
        cout << *ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

