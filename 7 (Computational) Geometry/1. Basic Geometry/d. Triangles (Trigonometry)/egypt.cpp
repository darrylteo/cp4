#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> v(3);
    while (cin >> v[0] >> v[1] >> v[2], v[0]) {
        sort(v.begin(), v.end());
        cout << (v[0] * v[0] + v[1] * v[1] == v[2] * v[2] ? "right\n" : "wrong\n");
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}