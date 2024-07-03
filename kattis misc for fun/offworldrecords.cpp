#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, curr, prev;
    cin >> n >> curr >> prev;
    int cnt = 0;
    while (n--) {
        int x;
        cin >> x;
        if (x > curr + prev) {
            cnt++;
            prev = curr;
            curr = x;
        }
    }
    cout << cnt << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
