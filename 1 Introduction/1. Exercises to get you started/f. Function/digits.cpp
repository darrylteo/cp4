#include <bits/stdc++.h>
using namespace std;

char x[1000001];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%s", x);
    while (strcmp(x,"END")!=0) {
        if (strcmp(x,"1")==0) {
            printf("1\n");
        } else {
            int currLen = strlen(x);
            int newLen = 1;
            int count = 1;
            while (newLen != currLen){
                newLen = strlen(to_string(currLen).c_str());
                currLen = strlen(to_string(newLen).c_str());
                count++;
            }
            printf("%d\n", count + 1); // add 1 since we didnt use first term (too long!)
        }
        scanf("%s", x);
    }



    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}