#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    while (N--) {
        int A, B, C;
        cin >> A >> B >> C;
        bool sol = false; int x, y, z;
        for (x = -22; (x <= 22) && !sol; ++x) if (x*x <= C)
                for (y = -100; (y <= 100) && !sol; ++y) if ((y != x) && (x*x + y*y <= C))
                        for (z = -100; (z <= 100) && !sol; ++z)
                            if ((z != x) && (z != y) &&
                                (x+y+z == A) && (x*y*z == B) && (x*x + y*y + z*z == C)) {
                                vector<int> v;
                                v.push_back(x); v.push_back(y); v.push_back(z);
                                sort(v.begin(), v.end());
                                cout << v[0] << " " << v[1] << " " << v[2] << endl;
                                sol = true;
                            }
        if (!sol) cout << "No solution." << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
