#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int k, b, n;
        cin >> k >> b >> n;
        vi digits;
        while (n) {
            digits.push_back(n % b);
            n /= b;
        }
        int sum = 0;
        for (int i = 0; i < digits.size(); i++) {
            sum += digits[i] * digits[i];
        }
        cout << k << " " << sum << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
