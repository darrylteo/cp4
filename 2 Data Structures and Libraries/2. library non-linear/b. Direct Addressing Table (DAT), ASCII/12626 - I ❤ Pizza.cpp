#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string buf;
    int n;
    cin >> n;
    while (n--) {
        int charset[128] = {};
        getline(cin >> ws, buf);
        for (char &c: buf) {
            charset[c]++;
        }
        int maxPizzas = 100000000;
        maxPizzas = min(maxPizzas, charset['M'] / 1);
        maxPizzas = min(maxPizzas, charset['A'] / 3);
        maxPizzas = min(maxPizzas, charset['R'] / 2);
        maxPizzas = min(maxPizzas, charset['G'] / 1);
        maxPizzas = min(maxPizzas, charset['I'] / 1);
        maxPizzas = min(maxPizzas, charset['T'] / 1);
        cout << maxPizzas << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
