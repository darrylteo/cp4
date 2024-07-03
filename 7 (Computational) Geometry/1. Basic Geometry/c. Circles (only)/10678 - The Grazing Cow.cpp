#include <bits/stdc++.h>

using namespace std;

// max height is b, max width is a. ellipse formula

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;
    while (N--) {
        double D, L;
        cin >> D >> L;
        double b = sqrt((L/2) * (L/2) - (D/2) * (D/2));
        double a = L/2;
        double area = a * b * 2 * acos(0);
        cout << fixed << setprecision(3) << area << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}