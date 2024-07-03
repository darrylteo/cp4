#include <bits/stdc++.h>

using namespace std;

// UGHH no wonder it is a 3.2 qn. i went to find the first cycle i.e. mu -_-
// he just wanted the first time a number was repeated

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Q;
    cin >> Q;
    while (Q--) {
        int m;
        cin >> m;
        int visited[1000] = {}, idx = 2;
        int xn = 1, xn1 = 2;
        while (!visited[xn1]) {
            visited[xn1] = idx++;
            int xn2 = (xn1 + xn) % m;
            xn = xn1;
            xn1 = xn2;
        }
        cout << visited[xn1] << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}