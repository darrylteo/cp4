#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a;
    cin >> a;
    if (a <= 0.2) cout << "Logn";
    else if (a <= 1.5) cout << "Andvari";
    else if (a <= 3.3) cout << "Kul";
    else if (a <= 5.4) cout << "Gola";
    else if (a <= 7.9) cout << "Stinningsgola";
    else if (a <= 10.7) cout << "Kaldi";
    else if (a <= 13.8) cout << "Stinningskaldi";
    else if (a <= 17.1) cout << "Allhvass vindur";
    else if (a <= 20.7) cout << "Hvassvidri";
    else if (a <= 24.4) cout << "Stormur";
    else if (a <= 28.4) cout << "Rok";
    else if (a <= 32.6) cout << "Ofsavedur";
    else cout << "Farvidri";


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}



