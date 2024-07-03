#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// N = a^2 - b^2 = (a+b)(a-b) = xy
// x = a+b, y = a-b
// a = (x+y)/2, b = (x-y)/2
// x and y have the same parity (both even or both odd)
// this means N cannot be factorized when it is even but not multiple of 4 (cannot factorize when x and y are different parities)
// if can factorize, just use the easiest. x = N/2, y = 2 or x = N, y = 1.

// one of those problems that can slowly work your way through but takes some time... no magic formula here

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string buf;
    while (getline(cin, buf)) {
        ll N, N1 = (ll) 1e10, a, b; // N1 is not signed int range
        stringstream ss(buf);
        ss >> N >> N1;
        if (N1 == (ll) 1e10) { // the one number case
            if (N % 2 == 0 && N % 4 != 0) {
                cout << "Bachelor Number." << '\n';
            } else if (N == 0) {
                cout << 2 << ' ' << 2 << '\n';
            } else {
                ll originalN = N;
                N = abs(N);
                if (N&1) {
                    a = (N + 1) / 2;
                    b = (N - 1) / 2;
                } else {
                    a = (N / 2 + 2) / 2;
                    b = (N / 2 - 2) / 2;
                }
                if (originalN < 0) swap(a, b);
                cout << a << ' ' << b << '\n';
            }
        } else { // the two number case
            ll cnt = 0;
            while (N <= N1 && N % 4 != 0) {
                if (N % 2 == 0) {
                    cnt++;
                }
                N++;
            }
            while (N1 >= N && N1 % 4 != 0) {
                if (N1 % 2 == 0) {
                    cnt++;
                }
                N1--;
            }
            cnt += (N1 - N) / 4;
            cout << cnt << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


