#include <bits/stdc++.h>

using namespace std;

bool check9(const string s) {
    int B, U, S, P, F, T, M;
    B = U = S = P = F = T = M = 0;
    for (char i: s) {
        if (i == 'B') {
            B++;
            if (B > 9) return false;
        } else if (i == 'U') {
            U++;
            if (U > 9) return false;
        } else if (i == 'S') {
            S++;
            if (S > 9) return false;
        } else if (i == 'P') {
            P++;
            if (P > 9) return false;
        } else if (i == 'F') {
            F++;
            if (F > 9) return false;
        } else if (i == 'T') {
            T++;
            if (T > 9) return false;
        } else if (i == 'M') {
            M++;
            if (M > 9) return false;
        }
    }
    return true;
}

const string order = "BUSPFTM";

bool checkOrder(const string s) {
    int check = 0;
    for (int i = 0; i < s.size() - 1; i++){
        if (order.find(s[i]) > order.find(s[i+1])){
            check = 1;
            break;
        }
    }
    if (check == 1) {
        for (int i = 0; i < s.size() - 1; i++){
            if (order.find(s[i]) < order.find(s[i+1])){
                return false;
            }
        }
    }
    return true;
}

int stringToVal (const string s) {
    int val = 0;
    for (char i: s) {
        if (i == 'B') val += 1;
        else if (i == 'U') val += 10;
        else if (i == 'S') val += 100;
        else if (i == 'P') val += 1000;
        else if (i == 'F') val += 10000;
        else if (i == 'T') val += 100000;
        else if (i == 'M') val += 1000000;
    }
    return val;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    string s;
    while (n--){
        cin >> s;
        checkOrder(s) && check9(s) ? cout << stringToVal(s) << endl : cout << "error" << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}