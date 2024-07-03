#include <bits/stdc++.h>

using namespace std;

string c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> c;
    char* combo[6] = {"RBL", "RLB", "BLR", "BRL", "LRB", "LBR"};
    for (int i = 0; i < c.length(); i++){
        string s = c.substr(i, 3);
        if (s.compare(combo[0]) == 0 || s.compare(combo[1]) == 0 || s.compare(combo[2]) == 0 ||
            s.compare(combo[3]) == 0 || s.compare(combo[4]) == 0 || s.compare(combo[5]) == 0) {
            cout << "C";
            i += 2;
        } else if (c[i] == 'R'){
            cout << "S";
        } else if (c[i] == 'B') {
            cout << "K";
        } else if (c[i] == 'L') {
            cout << "H";
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

