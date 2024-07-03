#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string buf;
    int lower = 0, upper = 0, ws = 0;
    getline(cin, buf);
    for (char c : buf) {
        if (islower(c)) lower++;
        else if (isupper(c)) upper++;
        else if (c == '_') ws++;
    }
    cout << fixed << setprecision(10) << (double) ws / buf.size() << '\n';
    cout << fixed << setprecision(10) << (double) lower / buf.size() << '\n';
    cout << fixed << setprecision(10) << (double) upper / buf.size() << '\n';
    cout << fixed << setprecision(10) << (double) (buf.size() - upper - lower - ws)/ buf.size() << '\n';



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
