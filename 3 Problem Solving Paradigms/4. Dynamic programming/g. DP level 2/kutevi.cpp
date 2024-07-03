#include <bits/stdc++.h>

using namespace std;

// 2 star rating on kattis surely not a dp right
// weird that it is not stated he can draw 360 degrees
// Theorem: For integers a, b, not both 0, the smallest positive linear combination of a and b equals
gcd (a, b).
// https://www.math.umd.edu/~immortal/MATH406/lecturenotes/ch3-3.pdf
// basically it is saying any steps will be multiple of all divisors incl gcd. so gcd must be the smallest practical step

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    int ans = 360; // only way to solve sample input 2.. ?
    while (N--) {
        int x;
        cin >> x;
        ans = __gcd(ans, x);
    }
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        if (x % ans == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


