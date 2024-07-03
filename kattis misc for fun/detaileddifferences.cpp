#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--) {
        string a, b, c;
        cin >> a >> b;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == b[i]) {
                c += '.';
            } else {
                c += '*';
            }
        }
        cout << a << endl << b << endl << c << endl << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
