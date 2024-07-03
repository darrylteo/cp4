#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> v1(5), v2(5);
    for (int i = 0; i < 5; i++) {
        cin >> v1[i] >> v2[i];
    }
    int mean = 0;
    for (int i = 0; i < 5; i++) {
        mean += v1[i] * v2[i];
    }
    mean /= 5;
    int N, KWF;
    cin >> N >> KWF;
    cout << mean * N / KWF << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

