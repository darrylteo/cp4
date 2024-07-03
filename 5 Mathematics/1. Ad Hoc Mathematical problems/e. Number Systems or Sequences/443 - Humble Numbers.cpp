#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vi humble_numbers;
    humble_numbers.push_back(1);
    int n2 = 0, n3 = 0, n5 = 0, n7 = 0;
    while (humble_numbers.size() < 5842) {
        int next_humble = min(humble_numbers[n2] * 2, min(humble_numbers[n3] * 3, min(humble_numbers[n5] * 5, humble_numbers[n7] * 7)));
        humble_numbers.push_back(next_humble);
        if (next_humble == humble_numbers[n2] * 2) n2++;
        if (next_humble == humble_numbers[n3] * 3) n3++;
        if (next_humble == humble_numbers[n5] * 5) n5++;
        if (next_humble == humble_numbers[n7] * 7) n7++;
    }
    int n;
    while (cin >> n, n) {
        cout << "The " << n;
        if (n % 10 == 1 && n % 100 != 11) cout << "st";
        else if (n % 10 == 2 && n % 100 != 12) cout << "nd";
        else if (n % 10 == 3 && n % 100 != 13) cout << "rd";
        else cout << "th";
        cout << " humble number is " << humble_numbers[n - 1] << ".\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

