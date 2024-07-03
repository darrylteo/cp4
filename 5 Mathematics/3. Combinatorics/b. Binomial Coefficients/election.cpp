#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull nCk(ull n, ull k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return 1;

    ull result = n;
    for (ull i = 2; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

double binomcdf(ull n, ull k, double p) {
    double cdf = 0;
    for (ull i = 0; i <= k; i++) {
        cdf += nCk(n, i) * pow(p, i) * pow(1 - p, n - i);
    }
    return cdf;
}

// pretty owo seems like a high school question.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, v1, v2, w;
        cin >> n >> v1 >> v2 >> w;
        int votesNeeded = (n / 2) + 1 - v1;
        int votesRemaining = n - v1 - v2;
        if (votesNeeded > votesRemaining) {
            cout << "RECOUNT!" << endl;
            continue;
        }
        if (votesNeeded <= 0) {
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
            continue;
        }
        double p = 0.5;
        double cdf = binomcdf(votesRemaining, votesNeeded - 1, p); // probability of getting less votes i.e. lose
        if (cdf < 1.0 - w / 100.0) { // low chance of losing
            cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
        } else {
            cout << "PATIENCE, EVERYONE!" << endl;
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


