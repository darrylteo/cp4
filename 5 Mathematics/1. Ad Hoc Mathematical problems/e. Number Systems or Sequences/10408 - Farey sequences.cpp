#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

struct fareyPair {
    double value;
    int a, b, maxAB;
};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<fareyPair> v;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            if (__gcd(i, j) == 1) {
                fareyPair f;
                f.value = (double) i / j;
                f.a = i;
                f.b = j;
                f.maxAB = max(i, j);
                v.push_back(f);
            }
        }
    }
    sort(v.begin(), v.end(), [](fareyPair a, fareyPair b) {
        return a.maxAB < b.maxAB;
    });

    int a, b;
    while (cin >> a >> b) {
        vector<fareyPair> curr;
        for (auto &i : v) {
            if (i.maxAB <= a) {
                curr.push_back(i);
            } else {
                break;
            }
        }
        sort(curr.begin(), curr.end(), [](fareyPair a, fareyPair b) {
            return a.value < b.value;
        });
        cout << curr[b - 1].a << "/" << curr[b - 1].b << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

