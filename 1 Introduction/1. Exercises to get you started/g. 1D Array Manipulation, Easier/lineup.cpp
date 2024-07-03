#include <bits/stdc++.h>

using namespace std;


// N becomes -1 because it checks if N==0, true,
// decrements to -1 and does not run the loop
int N;
string currName, nextName;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &N);
    cin >> currName >> nextName;
    N -= 2;
    if (currName < nextName) {
        while (N--) {
            currName = nextName;
            cin >> nextName;
            if (currName < nextName) {
            } else {
                printf("NEITHER\n");
                break;
            }
        }
        if (N == -1) printf("INCREASING\n");
    } else if (currName > nextName) {
        while (N--) {
            currName = nextName;
            cin >> nextName;
            if (currName > nextName) {
            } else {
                printf("NEITHER\n");
                break;
            }
        }
        if (N == -1) printf("DECREASING\n");
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}