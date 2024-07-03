#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T, start = 0;
    cin >> T;
    while (T--) {
        if (start) {
            cout << '\n';
        } else {
            start = 1;
        }
        string chars;
        cin >> chars;
        double MINI, MAXI, MINR, MAXR, PRECI, PRECR;
        cin >> MINI >> MAXI >> PRECI >> MINR >> MAXR >> PRECR;
        int r = (MAXI - MINI + 1e-9) / PRECI + 1;
        int c = (MAXR - MINR + 1e-9) / PRECR + 1;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                double CI = MINI + i * PRECI, CR = MINR + j * PRECR;
                double ZI = 0, ZR = 0, tmpI, tmpR; // use formula for mutiply complex numbers (a+bi)(a+bi) = (aa-bb) + (ab+ba)i
                int k = 0;
                while (k < 13 && (ZI * ZI + ZR * ZR) <= 4 + 1e-9) {
                    tmpI = 2 * ZI * ZR + CI;
                    tmpR = ZR * ZR - ZI * ZI + CR;
                    ZI = tmpI;
                    ZR = tmpR;
                    k++;
                }
                if (k == 13) {
                    cout << ' ';
                } else {
                    cout << chars[k];
                }
            }
            cout << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

