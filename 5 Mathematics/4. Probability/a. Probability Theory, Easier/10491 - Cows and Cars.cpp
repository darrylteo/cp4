#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double cows, cars, shows;
    while (cin >> cows >> cars >> shows) {
        double total = cows + cars;
        double probability = cows / total * (cars / (total - shows - 1)) +
                            cars / total * ((cars - 1) / (total - shows - 1));
        cout << fixed << setprecision(5) << probability << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


