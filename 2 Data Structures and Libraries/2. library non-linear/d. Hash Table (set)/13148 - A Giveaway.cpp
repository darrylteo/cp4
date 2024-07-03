#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<int> s = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,
    1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,
    47045881, 64000000, 85766121};
    int n;
    while (cin >> n, n) {
        if (s.find(n) != s.end()) cout << "Special\n";
        else cout << "Ordinary\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
