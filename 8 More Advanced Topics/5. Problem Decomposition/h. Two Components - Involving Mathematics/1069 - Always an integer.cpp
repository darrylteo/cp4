#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll modpow(ll base, ll exp, ll mod) {
    base %= mod;
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// un-concrete proof for test up to P(largestPow + 1)
// diff between terms for degree 1 is constant
// diff between diff between terms for degree 2 is constant
// (diff between)^n terms for degree n is constant
// for degree 1, if P(1) is multiple of div, and P(2) multiple of div, P(2) - P(1) is multiple of div
// this means all differences (since they are constant) are multiples of div
// for degree 2, diff between diff is (P(3)-P(2)) - (P(2)-P(1)) is multiple of div, P(1), P(2) and P(3) are multiples of div. so check up to P(3).
// for general degree n, check up to n+1

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int cases = 1;
    while (cin >> s, s != ".") {
        istringstream iss(s);
        string eqn;
        getline(iss, eqn, '/');
        eqn.erase(0, 1); // remove '('
        string divv;
        getline(iss, divv, '/');
        int div = stoi(divv);

        vector<int> coeffs(101);
        string coeff, pow;
        bool readCoeff = true, first = true;
        for (char c: eqn) {
            if (c == 'n') {
                readCoeff = false;
            } else if (!first && (c == '+' || c == '-' || c == ')')) {
                if (pow.empty() && readCoeff) pow = "0";
                if (pow.empty() && !readCoeff) pow = "1";
                if (coeff.empty() || coeff == "-" || coeff == "+") coeff += "1";
                if (pow[0] == '^') pow.erase(0, 1); // remove '^'
                int b = stoi(coeff);
                int p = stoi(pow);
                coeffs[p] += b;
                coeff.clear();
                pow.clear();
                coeff += c; // sign
                readCoeff = true;
            } else {
                if (readCoeff) coeff += c;
                else pow += c;
            }
            first = false;
        }

        int lar = -1;
        for (int i = 0; i < coeffs.size(); ++i) {
            if (coeffs[i]) lar = i;
        }
        int found = 0;
        for (int i = 0; i <= lar + 1; ++i) { // we test up to P(largestPow + 1)
            ll ans = 0;
            for (int j = 0; j <= lar; ++j) {
                ans += modpow(i, j, div) * coeffs[j];
                ans %= div;
            }
            if (ans) {
                found = 1;
                break;
            }
        }
        cout << "Case " << cases++ << ": ";
        if (!found) cout << "Always an integer\n";
        else cout << "Not always an integer\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
