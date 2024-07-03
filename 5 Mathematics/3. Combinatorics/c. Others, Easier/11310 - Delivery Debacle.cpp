#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// ref: https://oeis.org/A127864
// can see how it works... 
// v[i-1] since can only put 2 ball if 1 extra col
// 4[i-2] since 1 L 1 ball 4 orientation if 2 extra col
// 2[i-3] since the new 2 ball col can swap with the 1L 1ball part

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<ull> v(41);
    v[1] = 1;
    v[2] = 5;
    v[3] = 11;
    for (int i = 4; i <= 40; ++i) {
        v[i] = v[i - 1] + 4 * v[i - 2] + 2 * v[i - 3];
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << v[n] << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


