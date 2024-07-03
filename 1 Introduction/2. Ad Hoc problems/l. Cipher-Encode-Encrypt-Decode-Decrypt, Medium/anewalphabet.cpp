#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string convert[1000];
    convert['a'] = "@";
    convert['b'] = "8";
    convert['c'] = "(";
    convert['d'] = "|)";
    convert['e'] = "3";
    convert['f'] = "#";
    convert['g'] = "6";
    convert['h'] = "[-]";
    convert['i'] = "|";
    convert['j'] = "_|";
    convert['k'] = "|<";
    convert['l'] = "1";
    convert['m'] = "[]\\/[]";
    convert['n'] = "[]\\[]";
    convert['o'] = "0";
    convert['p'] = "|D";
    convert['q'] = "(,)";
    convert['r'] = "|Z";
    convert['s'] = "$";
    convert['t'] = "']['";
    convert['u'] = "|_|";
    convert['v'] = "\\/";
    convert['w'] = "\\/\\/";
    convert['x'] = "}{";
    convert['y'] = "`/";
    convert['z'] = "2";

    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            cout << convert[s[i]];
        } else {
            cout << s[i];
        }
    }
}


