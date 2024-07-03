#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, max = 0;
    string best;
    cin >> n;
    while (n--) {
        string s;
        int x;
        cin >> s >> x;
        if (x>max) {
            max = x;
            best = s;
        }
    }
    cout << best << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
