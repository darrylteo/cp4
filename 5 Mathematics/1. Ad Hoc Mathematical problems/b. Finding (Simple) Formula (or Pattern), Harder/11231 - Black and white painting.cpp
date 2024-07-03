#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

// if both even, (a - 7) * (b - 7) is odd so if divide 2 we round down if c==0 and round up if c==1

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    while (cin >> a >> b >> c, a) {
        if (a % 2 == 0 && b % 2 == 0 && c) cout << (a - 7) * (b - 7) / 2 + 1 << '\n';
        else cout << (a - 7) * (b - 7) / 2 << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


