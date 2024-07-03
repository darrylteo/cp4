#include <bits/stdc++.h>

using namespace std;
/*
FIVE CASES

ROW 1: 2 patterns
    - 1, 4: blank*(s+2)
    - others: blank + s*- + blank
ROW 2 TO ROW s+1: 3 patterns
    - 1, 2, 3, 7: blank*(s+1) + |
    - 5, 6: | + blank*(s+1)
    - others: | + s*blank + |
ROW s+2: 2 patterns
    - 1, 7, 0: blank*(s+2)
    - others: blank + s*- + blank
ROW s+3 TO ROW 2s+2: 3 patterns
    - 6, 8, 0: | + s*blank + |
    - 2: | + blank*(s+1)
    - others: blank*(s+1) + |
ROW 2s+3: 2 patterns
    - 1, 4, 7: blank*(s+2)
    - others: blank + s*- + blank
*/


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int s;
    string n;
    while (cin >> s >> n) {
        if (s == 0) break;

        // ROW 1
        for (int i = 0; i < n.size(); i++) {
            if (n[i] == '1' || n[i] == '4') {
                cout << " ";
                for (int j = 0; j < s; j++) cout << " ";
                cout << " ";
                if (i != n.size() - 1) cout << " ";
            } else {
                cout << " ";
                for (int j = 0; j < s; j++) cout << "-";
                cout << " ";
                if (i != n.size() - 1) cout << " ";
            }
        }

        cout << endl;

        // ROW 2 TO ROW s+1
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < n.size(); j++) {
                if (n[j] == '1' || n[j] == '2' || n[j] == '3' || n[j] == '7') {
                    cout << " ";
                    for (int k = 0; k < s; k++) cout << " ";
                    cout << "|";
                    if (j != n.size() - 1) cout << " ";
                } else if (n[j] == '5' || n[j] == '6') {
                    cout << "|";
                    for (int k = 0; k < s; k++) cout << " ";
                    cout << " ";
                    if (j != n.size() - 1) cout << " ";
                } else {
                    cout << "|";
                    for (int k = 0; k < s; k++) cout << " ";
                    cout << "|";
                    if (j != n.size() - 1) cout << " ";
                }
            }
            cout << endl;
        }

        // ROW s+2
        for (int i = 0; i < n.size(); i++) {
            if (n[i] == '1' || n[i] == '7' || n[i] == '0') {
                cout << " ";
                for (int j = 0; j < s; j++) cout << " ";
                cout << " ";
                if (i != n.size() - 1) cout << " ";
            } else {
                cout << " ";
                for (int j = 0; j < s; j++) cout << "-";
                cout << " ";
                if (i != n.size() - 1) cout << " ";
            }
        }
        cout << endl;

        // ROW s+3 TO ROW 2s+2
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < n.size(); j++) {
                if (n[j] == '6' || n[j] == '8' || n[j] == '0') {
                    cout << "|";
                    for (int k = 0; k < s; k++) cout << " ";
                    cout << "|";
                    if (j != n.size() - 1) cout << " ";
                } else if (n[j] == '2') {
                    cout << "|";
                    for (int k = 0; k < s; k++) cout << " ";
                    cout << " ";
                    if (j != n.size() - 1) cout << " ";
                } else {
                    cout << " ";
                    for (int k = 0; k < s; k++) cout << " ";
                    cout << "|";
                    if (j != n.size() - 1) cout << " ";
                }
            }
            cout << endl;
        }

        // ROW 2s+3
        for (int i = 0; i < n.size(); i++) {
            if (n[i] == '1' || n[i] == '4' || n[i] == '7') {
                cout << " ";
                for (int j = 0; j < s; j++) cout << " ";
                cout << " ";
                if (i != n.size() - 1) cout << " ";
            } else {
                cout << " ";
                for (int j = 0; j < s; j++) cout << "-";
                cout << " ";
                if (i != n.size() - 1) cout << " ";
            }
        }

        cout << endl << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
