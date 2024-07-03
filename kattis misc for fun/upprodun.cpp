#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int minGrp = M / N;
    int rem = M % N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < minGrp; ++j) {
            cout << '*';
        }
        if (rem > 0) {
            cout << '*';
            --rem;
        }
        cout << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


