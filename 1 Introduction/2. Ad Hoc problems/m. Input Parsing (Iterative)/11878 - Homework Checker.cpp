#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int a, b, correct = 0;
    char c[100], sign;
    while(scanf("%d%c%d=%s\n", &a, &sign, &b, c) != EOF) {
        if(c[0] == '?') continue;
        if(sign == '+') {
            if(a + b == atoi(c)) correct++;
        } else if(sign == '-') {
            if(a - b == atoi(c)) correct++;
        }
    }
    cout << correct << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}