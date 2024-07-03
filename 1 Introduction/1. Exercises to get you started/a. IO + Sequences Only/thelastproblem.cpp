#include <bits/stdc++.h>
using namespace std;

char str[100];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    fgets(str, 60, stdin);
    str[strcspn(str, "\n")] = 0; // remove newline

    printf("Thank you, %s, and farewell!", str);

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}