#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string buf;
    getline(cin, buf);
    int smile = 0, sad = 0;
    if (buf.find(":)") != string::npos) smile++;
    if (buf.find(":(") != string::npos) sad++;
    if (smile && sad) cout << "double agent" << endl;
    else if (smile) cout << "alive" << endl;
    else if (sad) cout << "undead" << endl;
    else cout << "machine" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

