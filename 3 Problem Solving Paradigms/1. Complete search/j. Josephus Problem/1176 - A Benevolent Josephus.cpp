#include <bits/stdc++.h>

using namespace std;

// josephus problem (general)
int F(int n, int k) {
    if (n == 1) return 0;
    return (F(n - 1, k) + k) % n;
}

// josephus problem (k = 2 bitwise)
// uses first formula in wikipedia
/*
public int getSafePosition(int n) {
	// find value of L for the equation
	int valueOfL = n - Integer.highestOneBit(n);
	return 2 * valueOfL  + 1;
}
*/
int F2(int n) {
    return 2 * (n - (1 << (int) log2(n))) + 1;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        int x = n, ans = 0;
        while (x != F2(x)) {
            ans += x - F2(x); // ppl bigger than survivor get paid
            x = F2(x);
        }
        ans += 2 * x; // survivors gets paid 2 taka
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

