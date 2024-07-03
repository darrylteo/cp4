#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;

// requirements not related to problem description

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<ull> v(50001);
    v[0] = 0;
    for (ull i = 1; i < 50001; i++) {
        v[i] = v[i - 1] + i * i * i;
    }
    int n;
    while (cin >> n) {
        cout << v[n] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

