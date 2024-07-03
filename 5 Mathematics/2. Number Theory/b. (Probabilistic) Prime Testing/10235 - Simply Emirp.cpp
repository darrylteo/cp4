#include <bits/stdc++.h>
using namespace std;

int isPrime(long n) {
    long i;

    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n%2 == 0) return 0;

    for (i = 3; i*i <= n; i += 2)
        if (n%i == 0)
            return 0;

    return 1;
}

long reverse(long n) {
    long rev;
    for (rev = 0; n; n /= 10)
        rev = rev*10 + n%10;
    return rev;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long N;

    while (scanf("%ld",&N)!=EOF) {
        if (!isPrime(N)) printf("%ld is not prime.\n", N);
        else {
            if (N != reverse(N) && isPrime(reverse(N)))
                printf("%ld is emirp.\n", N);
            else printf("%ld is prime.\n", N);
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}