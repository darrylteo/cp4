#include <bits/stdc++.h>
using namespace std;

string Ac, Bc;
int Ai, Bi;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    cin >> Ac >> Bc;
    reverse(Ac.begin(), Ac.end());
    reverse(Bc.begin(), Bc.end());
    Ai = stoi(Ac);
    Bi = stoi(Bc);

    printf("%d", Ai > Bi ? Ai : Bi);

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}