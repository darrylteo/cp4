#include <bits/stdc++.h>

using namespace std;

// coin change. the dp way is kinda trolling since this is classic problem

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    int cache[100005];
    int coins[10];
    coins[0] = 1;
    for (int i = 1; i < 9; ++i) {
        coins[i] = coins[i - 1] * i;
    }
    for (int & i : cache) {
        i = 1e9;
    }
    cache[0] = 0;
    for (int i = 1; i < 100005; ++i) {
        for (int j = 1; j < 9; ++j) { // 1! to 8!
            if (i - coins[j] >= 0) {
                cache[i] = min(cache[i], cache[i - coins[j]] + 1);
            }
        }
    }
    while (cin >> N) {
        cout << cache[N] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


