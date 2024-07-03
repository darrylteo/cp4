#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> fibs(50);
    fibs[0] = 0;
    fibs[1] = 1;
    for (int i = 2; i <= 45; i++) {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }

    int n;
    cin >> n;
    cout << fibs[n-1] << " " << fibs[n] << "\n";


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


