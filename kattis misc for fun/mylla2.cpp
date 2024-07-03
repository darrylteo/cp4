#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<string> v(3);
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }
    int win = 0;
    for (int i = 0; i < 3; i++) {
        if (v[i] == "OOO") win = 1;
    }
    for (int i = 0; i < 3; i++) {
        if (v[0][i] == 'O' && v[1][i] == 'O' && v[2][i] == 'O') win = 1;
    }
    if (v[0][0] == 'O' && v[1][1] == 'O' && v[2][2] == 'O') win = 1;
    if (v[0][2] == 'O' && v[1][1] == 'O' && v[2][0] == 'O') win = 1;
    if (win) cout << "Jebb\n";
    else cout << "Neibb\n";

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}