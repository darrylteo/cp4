#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef long double ld;

// temp in B = (tempA - minA) * ((maxB - minB) / (maxA - minA)) + minB

void printTemperature(ll minA, ll maxA, ll minB, ll maxB, ll tempA) {
    ll numerator = (tempA - minA) * (maxB - minB);
    ll denominator = (maxA - minA);
    numerator += minB * denominator;
    ll gcd = __gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    cout << to_string(numerator) + "/" + to_string(denominator) << '\n';
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<pair<ll, ll>> scale(N);
    for (int i = 0; i < N; i++) {
        cin >> scale[i].first >> scale[i].second;
    }
    for (int i = 0; i < Q; i++) {
        ll A, B, tempA;
        cin >> A >> B >> tempA;
        A--;
        B--;
        printTemperature(scale[A].first, scale[A].second, scale[B].first, scale[B].second, tempA);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

