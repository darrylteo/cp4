#include <bits/stdc++.h>

using namespace std;

int aWinsThis(const string &a1, const string &a2, const string &b1, const string &b2) {
    if (a1 == "1" && a2 == "2" || a1 == "2" && a2 == "1") {
        if (b1 == "1" && b2 == "2" || b1 == "2" && b2 == "1") { // lose mia b
            return 0;
        }
        return 1; // if b both same or both different a wins
    }

    if (a1 == a2) {
        if (b1 == "1" && b2 == "2" || b1 == "2" && b2 == "1") { // lose mia b
            return 0;
        }
        if (b1 == b2) { // both same
            if (a1 > b1) return 1;
            return 0; // lose if b >= a
        }
        return 1; // if b both different a wins
    }

    // if reach here, both a diff
    if (b1 == "1" && b2 == "2" || b1 == "2" && b2 == "1" || b1 == b2) { // lose mia b or both same b
        return 0;
    } else {
        int a = stoi(max(a1, a2) + min(a1, a2));
        int b = stoi(max(b1, b2) + min(b1, b2));
        if (a > b) return 1;
        return 0;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string a1, a2, b1, b2;
    while (cin >> a1 >> a2 >> b1 >> b2) {
        int possibilities = 0, aWins = 0;
        if (a1 == "0" && a2 == "0" && b1 == "0" && b2 == "0") break;
        int a1Star = a1 == "*" ? 6 : 1;
        int a2Star = a2 == "*" ? 6 : 1;
        int b1Star = b1 == "*" ? 6 : 1;
        int b2Star = b2 == "*" ? 6 : 1;
        for (int i1 = 1; i1 <= a1Star; ++i1) {
            if (a1Star == 1) i1 = stoi(a1);
            for (int i2 = 1; i2 <= a2Star; ++i2) {
                if (a2Star == 1) i2 = stoi(a2);
                for (int i3 = 1; i3 <= b1Star; ++i3) {
                    if (b1Star == 1) i3 = stoi(b1);
                    for (int i4 = 1; i4 <= b2Star; ++i4) {
                        if (b2Star == 1) i4 = stoi(b2);
                        possibilities++;
                        aWins += aWinsThis(to_string(i1), to_string(i2), to_string(i3), to_string(i4));
                    }
                }
            }
        }

        int gcd = __gcd(aWins, possibilities);
        aWins = aWins / gcd;
        possibilities = possibilities / gcd;

        if (possibilities == 1) {
            cout << aWins << '\n';
        } else {
            cout << aWins << "/" << possibilities << '\n';
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


