#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int mp[400005]{};
    for (int i = 0; i < 75; ++i) {
        for (int j = i; j < 75; ++j) {
            int sum = i * i * i + j * j * j;
            if (sum <= 400000) mp[sum]++;
        }
    }
    int n;
    cin >> n;
    for (int i = n; i >= 0; --i) {
        if (mp[i] > 1) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "none\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
