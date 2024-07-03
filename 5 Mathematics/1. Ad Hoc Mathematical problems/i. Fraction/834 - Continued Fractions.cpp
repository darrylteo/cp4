#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num, den;
    while (cin >> num >> den) {
        vector<int> b;
        while (den != 0) {
            b.push_back(num / den);
            num = num % den;
            swap(num, den);
        }
        cout << "[" << b[0];
        for (int i = 1; i < b.size(); i++) {
            if (i == 1) cout << ";";
            else cout << ",";
            cout << b[i];
        }
        cout << "]\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}