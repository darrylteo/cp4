#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> triplets;
    int n = 1, prod = 6;
    do {
        n++;
        prod = n * (n + 1) * (n + 2);
        triplets.push_back(prod);
    } while (prod < 1e9 + 9);
    int q;
    cin >> q;
    cout << lower_bound(triplets.begin(), triplets.end(), q) - triplets.begin() + 1 << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
