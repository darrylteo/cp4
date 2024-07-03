#include <bits/stdc++.h>
using namespace std;

char m[5];
int d;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%s %d", &m, &d);

    printf(strcmp(m, "OCT") == 0 && d == 31 || strcmp(m, "DEC") == 0 && d == 25 ? "yup" : "nope");

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}