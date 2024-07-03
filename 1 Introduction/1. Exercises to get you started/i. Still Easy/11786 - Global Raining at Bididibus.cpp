#include <bits/stdc++.h>

using namespace std;

int N;
char c[10001];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &N);
    while (N--) {
        int ans = 0, seaLevel[10005] = {};
        scanf("%s", c);

        // store the sea level.
        for (int i = 0; i < strlen(c); i++) {
            if (c[i] == '\\'){
                seaLevel[i + 1] = seaLevel[i] - 1;
            } else if (c[i] == '/'){
                seaLevel[i + 1] = seaLevel[i] + 1;
            } else {
                seaLevel[i + 1] = seaLevel[i];
            }
        }
        // each time encounter '/', search backwards until same sea level
        // then add the length of the water.
        for (int i = 0; i < strlen(c); i++) {
            if (c[i] == '/') {
                for (int j = i; j >= 0; j--) {
                    if (seaLevel[j] == seaLevel[i + 1]) {
                        ans += i - j;
                        break;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}