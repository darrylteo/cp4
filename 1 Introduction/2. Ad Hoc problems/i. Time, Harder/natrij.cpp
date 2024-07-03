#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int h1, m1, s1, sOnly1, h2, m2, s2, sOnly2;
    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);
    sOnly1 = h1 * 3600 + m1 * 60 + s1;
    sOnly2 = h2 * 3600 + m2 * 60 + s2;

    int diff = sOnly2 - sOnly1;
    if (diff < 0) diff += 24 * 3600;
    if (diff == 0) diff = 24 * 3600;
    printf("%02d:%02d:%02d\n", diff / 3600, (diff % 3600) / 60, diff % 60);

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}