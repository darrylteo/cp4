#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int N, M, cnt = 0;
    cin >> N >> M;
    vector<pair<int, int>> cannotMix;
    while (M--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cannotMix.emplace_back(x, y);
    }
    for (int i = 0; i < 1 << N; i++) {
        bitset<21> ingredients(i);
        bool flag = true;
        for (auto &cannot : cannotMix) {
            if (ingredients[cannot.first] && ingredients[cannot.second]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cnt++;
        }
    }
    cout << cnt << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}