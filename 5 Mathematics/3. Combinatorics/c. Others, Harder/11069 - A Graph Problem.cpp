#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
//                                                                  : end with seq   end with seq-1
// 4: 13 14 24                                                      : 2     1
// 5: 135 24 25 14                                                  : 2     2
// 6: 135 136 146 246 25                                            : 3     2
// 7: 1357 136 146 147 246 247 257                                  : 4     3
// 8: 1357 1358 1368 1468 147 2468 247 257 2578                     : 5     4
// 9: 13579 1358 1368 1369 1468 1469 1479 2468 2469 2479 2579 2578  : 7     5
//                                                                  : 9     7
//                                                                  : 12    9
// those that end with currseq-2, currseq, will get added to next seq since e.g. from 246 we can produce 246 247.
// wew found it. the left side v[n] = v[n-2] + v[n-3]. same for right side so add also same pattern
// another pattern would be v[n] = v[n-1] + v[n-5]

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<ull> v(100);
    v[0] = 1;
    v[1] = 1;
    v[2] = 2;
    v[3] = 2;
    for (int i = 4; i < 80; i++) {
        v[i] = v[i - 2] + v[i - 3];
    }
    int n;
    while (cin >> n) {
        cout << v[n] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


