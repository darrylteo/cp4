#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;
    string binary;
    // by default it is reversed.. usually we reverse it to make it normal
    while (x > 0) {
        binary += to_string(x % 2);
        x /= 2;
    }
    // u can put a address into nullptr argument if u want to know how many characters processed
    cout << stoi(binary, nullptr, 2) << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
