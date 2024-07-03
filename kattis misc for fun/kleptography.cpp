#include <bits/stdc++.h>

using namespace std;

char subtractChar(char b, char k) {
    return (b - k + 26) % 26 + 'a';
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string z, b;
    cin >> z >> b;
    z = string(m - n, '-') + z; // pad to align to back
    for (int i = m - 1; i >= n; i--) {
        z[i - n] = subtractChar(b[i], z[i]);
    }
    cout << z << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}