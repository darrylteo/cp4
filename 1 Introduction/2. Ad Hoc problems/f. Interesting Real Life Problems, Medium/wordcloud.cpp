#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int W, N, cloud = 1;
    while (scanf("%d %d", &W, &N), W) {
        int tmp;
        vector<int> chars, cnt, pt, width;
        char words[1000];
        for (int i = 0; i < N; i++) {
            scanf("%s %d", words, &tmp);
            chars.push_back(strlen(words));
            cnt.push_back(tmp);
        }
        int cmax = *max_element(cnt.begin(), cnt.end());
        for (int i: cnt) {
            pt.push_back(8 + ceil(40.0 * (i - 4) / (cmax - 4)));
        }
        for (int i = 0; i < N; i++) {
            width.push_back(ceil(9.0 / 16 * chars[i] * pt[i]));
        }

        int height = 0, currWidth = 0, currHeight = 0;
        for (int i = 0; i < N; i++) {
            if (currWidth + width[i] <= W) {
                currWidth += width[i] + 10;
                currHeight = max(currHeight, pt[i]);
            } else {
                height += currHeight;
                currWidth = width[i] + 10;
                currHeight = pt[i];
            }
        }
        height += currHeight;
        printf("CLOUD %d: %d\n", cloud++, height);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
