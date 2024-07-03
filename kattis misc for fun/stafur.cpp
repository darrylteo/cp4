#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    cin >> c;
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        cout << "Jebb" << endl;
    else if (c == 'Y')
        cout << "Kannski " << endl;
    else
        cout << "Neibb" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}