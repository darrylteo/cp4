#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // get fibonacci numbers
    vector<ull> fib(48);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 47; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    // to zero based index
    fib.erase(fib.begin());
    fib.erase(fib.begin());

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n), pos(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        for (int i = 0; i < n; i++) pos[i] = lower_bound(fib.begin(), fib.end(), nums[i]) - fib.begin();
        string q;
        getline(cin >> ws, q);
        string query;
        for (char c: q) if (isupper(c)) query += c;
        string ans(200, ' ');
        for (int i = 0; i < n; i++) ans[pos[i]] = query[i];
        while (ans.back() == ' ') ans.pop_back();
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

