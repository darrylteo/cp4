#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

// correct no. is
// R: 4 + 5 + ... + n = (n - 3) * (4 + n) / 2
// T: 3 + 4 + ... + (n - D) = (n - D - 2) * (3 + n - D) / 2
// can brute force 1000 candles < 45 yrs old

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int D, R, T;
    while(cin >> D >> R >> T){
        int total = R + T;
        for (int n = 4; n <= 50; ++n) {
            int rita = (n - 3) * (4 + n) / 2;
            int theo = (n - D - 2) * (3 + n - D) / 2;
            if (rita + theo == total) {
                cout << R - rita << '\n';
                break;
            }
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

