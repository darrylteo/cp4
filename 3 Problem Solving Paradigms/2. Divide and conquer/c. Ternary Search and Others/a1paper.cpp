#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<double> longSides(30);
    cin >> n;
    --n;
    vector<int> qtyAvailable(n);
    for (int i = 0; i < n; ++i) {
        cin >> qtyAvailable[i];
    }
    double sideA = pow(2, -0.75), sideB = pow(2, -1.25);
    longSides[0] = sideA;
    for (int i = 1; i < 30; ++i) {
        if (sideA > sideB) {
            sideA /= 2; // you cut long side
            longSides[i] = sideB; // this becomes the new longer side since it didn't get cut
        } else {
            sideB /= 2;
            longSides[i] = sideA;
        }
    }
    // we need 2 A2 papers ... tape required is qty/2
    // from 1st example, qty of A3 required is 2, we will prepare 1 A3 tape to stick them later
    // qty of A4 required is 4, we will use 2 A4 tape to stick them straight away to get 2 A3 papers, then use the tape above
    int qty = 2, okay = 0;
    double tape = 0;
    for (int i = 0; i < n; ++i) {
        tape += qty / 2 * longSides[i];
        qty -= qtyAvailable[i];
        if (qty <= 0) {
            okay = 1;
            break;
        } else {
            qty *= 2;
        }
    }
    if (!okay) {
        cout << "impossible\n";
        return 0;
    }
    cout << fixed << setprecision(10) << tape << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
