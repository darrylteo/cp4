#include <bits/stdc++.h>

using namespace std;

int N, i, j;

// see the diagram in pdf. 'i' represent its numbering in next match
// Round 1: i = 2, j = 5
// Round 2: i = 1, j = 3
// Round 3: i = 1, j = 1

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (scanf("%d %d %d", &N, &i, &j) != EOF) {
        int ans = 0;
        while (i != j) {
            i = (i + 1) / 2;
            j = (j + 1) / 2;
            ans++;
        }
        printf("%d\n", ans);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

