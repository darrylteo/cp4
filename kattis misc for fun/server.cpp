#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, total;
    cin >> n >> total;
    int ans = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        curr += x;
        if (curr <= total) {
            ans++;
        } else {
            break;
        }
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
