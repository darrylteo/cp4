#include <bits/stdc++.h>

using namespace std;

// weird qns again!!
// they require that every letter to touch every other letter
// from their example
// 2 2 2
// AB
// CC
//
// zz
// zz
// we see A touches (adjacent to) B and C on its floor and z downstairs
// B touches A and C on its floor and z downstairs
// C touches A and B on its floor and z downstairs
// z touches A and B and C on upstairs (need 3d visualization ? :S)
// to be safe, we print top floor all same letter
// bottom floor all diff letter for each row so sure touch all letters e.g.
// 2 4 4
// AAAA
// BBBB
// CCCC
// zzzz
//
// ABCz
// ABCz
// ABCz
// ABCz
// so we can see that every letter touches every other letter between floors
// we can then ignore within floor

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    while (cin >> n) {
        cout << 2 << " " << n << " " << n << endl;
        char c = 'A';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << alphabet[i];
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << alphabet[j];
            }
            cout << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}