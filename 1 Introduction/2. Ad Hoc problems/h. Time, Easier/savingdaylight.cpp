#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    char M[100], D[100], Y[100], T1[100], T2[100];
    while (scanf("%s %s %s %s %s", M, D, Y, T1, T2) != EOF){
        cout << M << " " << D << " " << Y << " ";
        int h1, m1, h2, m2;
        sscanf(T1, "%d:%d", &h1, &m1);
        sscanf(T2, "%d:%d", &h2, &m2);

        int diff = (h2 * 60 + m2) - (h1 * 60 + m1);

        cout << diff / 60 << " hours " << diff % 60 << " minutes" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}