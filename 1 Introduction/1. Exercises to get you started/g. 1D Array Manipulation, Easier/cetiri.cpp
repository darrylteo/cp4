#include <bits/stdc++.h>

using namespace std;

int a, b, c;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d %d %d", &a, &b, &c);
    if (a > b && a > c){
        swap(a, c);
    }
    else if (b > a && b > c){
        swap(b, c);
    }
    if (a > b){
        swap(a, b);
    }

    int diff1, diff2;
    diff1 = b-a;
    diff2 = c-b;
    if (diff1 == diff2){
        printf("%d", c+diff1);
    } else if (diff1 > diff2){
        printf("%d", a+diff2);
    } else {
        printf("%d", b+diff1);
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}