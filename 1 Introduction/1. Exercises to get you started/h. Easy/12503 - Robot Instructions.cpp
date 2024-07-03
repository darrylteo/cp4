#include <bits/stdc++.h>

using namespace std;

int T, n;



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        char instruction[10];
        string instructionList[n];
        int sameAs;
        for (int i = 0; i < n; i++){
            scanf("%s", instruction);
            if (strcmp(instruction, "SAME") == 0){
                scanf("%*s");
                scanf("%d", &sameAs);
                instructionList[i] = instructionList[sameAs - 1];
            } else {
                instructionList[i] = instruction;
            }
        }
        int score = 0;
        for (int i = 0; i < n; i++){
            if (instructionList[i] == "RIGHT")
                score++;
            else if (instructionList[i] == "LEFT")
                score--;
        }
        printf("%d\n", score);
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}