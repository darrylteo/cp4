#include <bits/stdc++.h>

using namespace std;

int n;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (scanf("%d", &n), n){
        while (n >= 10){
            int sum = 0;
            while (n > 0){
                sum += n % 10;
                n /= 10;
            }
            n = sum;
        }
        printf("%d\n", n);
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}