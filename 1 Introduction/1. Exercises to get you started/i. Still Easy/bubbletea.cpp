#include <bits/stdc++.h>

using namespace std;

int N, M, K, X;



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    // Array of tea prices
    scanf("%d", &N);
    int priceTea[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &priceTea[i]);
    }

    // Array of topping prices
    scanf("%d", &M);
    int priceTopping[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &priceTopping[i]);
    }

    // Array of toppings that can be paired with tea i
    // Return minimum priced tea topping combo
    int minPrice = INT_MAX;
    for (int i = 0; i < N; i++){
        scanf("%d", &K);
        int topping;
        for (int k = 0; k < K; k++) {
            scanf("%d", &topping);
            minPrice = min(minPrice, priceTea[i] + priceTopping[topping - 1]);
        }
    }

    // Print no. of students, he can buy bbt for
    // Cannot buy for negative students!
    scanf("%d", &X);
    printf("%d\n", max(X / minPrice - 1, 0));




    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}