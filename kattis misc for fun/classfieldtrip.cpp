#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    vector<char> v;
    cin >> s;
    for (char c: s) {
        v.push_back(c);
    }
    cin >> s;
    for (char c: s) {
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    for (char c: v) {
        cout << c;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
