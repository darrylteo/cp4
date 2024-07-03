#include <bits/stdc++.h>

using namespace std;

const string letters = "abcdefghijklmnopqrstuvwxyz";
const string letters2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void printLinePush(int n, string s) {
    while (n < 0) {
        n = 26 + n;
    }
    for (char i : s) {
        if (!isalpha(i)) {
            cout << i;
            continue;
        } else {
            if (isupper(i)) {
                int index = letters2.find(i);
                cout << letters2[(index + n) % 26];
            } else {
                int index = letters.find(i);
                cout << letters[(index + n) % 26];
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    string s;
    while (cin >> n, n){
        getline(cin, s);
        getline(cin, s);
        printLinePush(n, s);
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


