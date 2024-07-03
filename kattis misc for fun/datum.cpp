#include <bits/stdc++.h>

using namespace std;

const int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int D, M;
    cin >> D >> M;
    int d = D;
    for (int i = 0; i < M - 1; i++) d += months[i];
    cout << days[(d + 2) % 7] << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}