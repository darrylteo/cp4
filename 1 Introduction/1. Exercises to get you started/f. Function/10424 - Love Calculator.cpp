#include <bits/stdc++.h>
using namespace std;

char a[26], b[26];

int stringToScore(string line) {
    int score = 0;
    string temp = "";
    for (int i = 0; i < line.size(); ++i) {
        if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) {
            line[i] = tolower(line[i]);
            temp = temp + line[i];
        }
    }
    line = temp;
    for (int i = 0; i < line.size(); ++i) {
        score += line[i] - 'a' + 1;
    }
    while (score >= 10) {
        int temp = 0;
        while (score > 0) {
            temp += score % 10;
            score /= 10;
        }
        score = temp;
    }
    return score;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (gets(a)) {
        gets(b);
        int scoreA = stringToScore(a);
        int scoreB = stringToScore(b);
        if (scoreA > scoreB) printf("%.2f %%\n", (float)scoreB / scoreA * 100);
        else printf("%.2f %%\n", (float)scoreA / scoreB * 100);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}