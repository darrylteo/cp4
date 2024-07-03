#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll memo[1001];

void init() {
    memo[1] = 1; // base case
    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j < i; j++) {
            if ((i - 1) % j == 0) { // -1 to remove the boss node. j is the number of subtrees
                memo[i] += memo[j]; // add memo[j] (not pow(memo[j], (i - 1) / j) only since ALL subtrees must have the same structure
                memo[i] %= 1000000007;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();
    int n, tc = 1;
    while (cin >> n) {
        cout << "Case " << tc++ << ": " << memo[n] << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
