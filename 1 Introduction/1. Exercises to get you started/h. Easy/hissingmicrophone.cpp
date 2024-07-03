#include <bits/stdc++.h>

using namespace std;

string hiss;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> hiss;
    regex r("ss");

    if (regex_search(hiss, r)) {
        printf("hiss\n");
        return 0;
    } printf("no hiss\n");

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}