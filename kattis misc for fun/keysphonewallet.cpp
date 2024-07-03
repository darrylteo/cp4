#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    int keys = 0, phone = 0, wallet = 0;
    while (n--) {
        string s;
        cin >> s;
        if (s == "keys") {
            keys = 1;
        } else if (s == "phone") {
            phone = 1;
        } else if (s == "wallet"){
            wallet = 1;
        }
    }
    if (keys && phone && wallet) {
        cout << "ready";
    } else {
        if (!keys) cout << "keys\n";
        if (!phone) cout << "phone\n";
        if (!wallet) cout << "wallet\n";
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


