#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<char> a(n);
    for (char &i : a) cin >> i;
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) {
            cnt++;
        }
    }
    cout << cnt << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
