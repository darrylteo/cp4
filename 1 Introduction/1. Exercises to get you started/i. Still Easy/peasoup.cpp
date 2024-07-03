#include <bits/stdc++.h>

using namespace std;

// 150 chars includes \n from fgets and \0 naturally... else runtime error
char n[10], k[10], restaurantName[150], dishName[150];
int N, K;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    fgets(n, 10, stdin);
    sscanf(n, "%d", &N);
    int totalRestaurantFlag = 0;
    for (int i = 0; i < N; i++) {
        int peaFlag = 0, pancakeFlag = 0;
        fgets(k, 10, stdin);
        sscanf(k, "%d", &K);
        fgets(restaurantName, 150, stdin);
        for (int j = 0; j < K; j++) {
            fgets(dishName, 150, stdin);
            // need to split pea and pancake since there might be multiple pea soup or pancake
            if (strcmp(dishName, "pea soup\n") == 0) {
                peaFlag = 1;
            }
            if (strcmp(dishName, "pancakes\n") == 0) {
                pancakeFlag = 1;
            }
        }
        if (peaFlag + pancakeFlag == 2) {
            printf("%s", restaurantName);
            totalRestaurantFlag += 1;
            break; // only need 1st restaurant that meet the criteria
        }
    }
    if (totalRestaurantFlag == 0) {
        printf("Anywhere is fine I guess\n");
    }



    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}