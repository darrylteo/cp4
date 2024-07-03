#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, pass = 1;
    cin >> n;
    for (int i = 0; i < 3; ++i) {
        int hasSeven = 0;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x == 7) {
                hasSeven = 1;
            }
        }
        if (!hasSeven) {
            pass = 0;
        }
    }
    cout << (pass ? 777 : 0) << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


