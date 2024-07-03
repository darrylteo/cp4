#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, B;
        cin >> N >> B;
        ll total = 0;
        while (B--) {
            int K;
            ll subtotal = 1;
            cin >> K;
            while (K--) {
                ll x;
                cin >> x;
                subtotal *= x;
                subtotal %= N; // pretend she already evenly distributes whatever she has here
            }
            total += subtotal;
        }
        cout << total % N << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


