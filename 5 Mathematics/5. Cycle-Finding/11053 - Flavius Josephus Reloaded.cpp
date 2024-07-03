#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef unsigned long long ull;

string line;
int N, L; // what to mod, first number
int a, b;

inline ull f(ull x) {
    return ((a * x % N) * x + b) % N;
}

inline ii floydCycleFinding(int x0) {                   // f(x) is defined above
    // 1st part: finding k*mu, hare h's speed is 2x tortoise t's
    ull t = f(x0), h = f(f(x0));                   // f(x0) is after x0. int should be able to hold the val by here
    while (t != h) {
        t = f(t);
        h = f(f(h));
    }
    // 2nd part: finding mu, hare h and tortoise t move at the same speed
    int mu = 0;
    h = x0;
    while (t != h) {
        t = f(t);
        h = f(h);
        ++mu;
    }
    // 3rd part: finding lambda, hare h moves, tortoise t stays
    int lambda = 1;
    h = f(t);
    while (t != h) {
        h = f(h);
        ++lambda;
    }
    return {mu, lambda};
}

// direct application

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    L = 0;
    while (cin >> N >> a >> b) {
        auto [mu, lambda] = floydCycleFinding(L);
        cout << N - lambda << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}