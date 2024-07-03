#include <bits/stdc++.h>
using namespace std;

int N;
char str[100];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (fgets(str, 100, stdin) != NULL){
        printf("%s", str);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}