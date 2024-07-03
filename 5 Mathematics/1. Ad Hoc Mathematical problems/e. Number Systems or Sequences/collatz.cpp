#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

// stuck for a while until changed int to ll... owo

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    while (cin >> a >> b, a) {
        vll v1, v2;
        ll curr = a;
        while (curr != 1) {
            v1.push_back(curr);
            if (curr % 2 == 0) {
                curr /= 2;
            } else {
                curr = 3 * curr + 1;
            }
        }
        v1.push_back(1);

        curr = b;
        while (curr != 1) {
            v2.push_back(curr);
            if (curr % 2 == 0) {
                curr /= 2;
            } else {
                curr = 3 * curr + 1;
            }
        }
        v2.push_back(1);

        // once they meet, all remaining future elements are the same. we remove all "same" elements from the end of both vectors
        int i = v1.size() - 1, j = v2.size() - 1;
        while (i >= 0 && j >= 0 && v1[i] == v2[j]) {
            i--;
            j--;
        }
        cout << a << " needs " << i + 1 << " steps, " << b << " needs " << j + 1 << " steps, they meet at " << v1[i + 1] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

