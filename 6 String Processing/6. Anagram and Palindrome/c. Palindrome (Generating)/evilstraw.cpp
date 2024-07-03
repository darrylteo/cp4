#include <bits/stdc++.h>

using namespace std;

int check(string s) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - i - 1]) continue;
        int j = n - i - 1; // start from right match left
        while (s[i] != s[j]) j--;
        int j1 = i; // start from left match right
        while (s[n - i - 1] != s[j1]) j1++;
        // use the one which is closer
        if (j1 - i < n - i - 1 - j) {
            ans += j1 - i;
            for (int k = j1; k > i; k--) swap(s[k], s[k - 1]);
        } else {
            ans += n - i - 1 - j;
            for (int k = j; k < n - i - 1; k++) swap(s[k], s[k + 1]);
        }
    }
    return ans;
}

// also available at uva 10716... not that easy for 2.9 kattis rating. used udebug to catch corner cases

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size(), odd = 0;
        int dat[26]{};
        for (int i = 0; i < n; i++) dat[s[i] - 'a']++;
        for (int i: dat) if (i & 1) odd++;
        if (odd > 1) {
            cout << "Impossible\n";
            continue;
        }

        cout << check(s) << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}