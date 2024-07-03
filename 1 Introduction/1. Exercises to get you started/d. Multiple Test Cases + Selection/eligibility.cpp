#include <bits/stdc++.h>
using namespace std;

int N, yearStudies, yearBirth, courses;
char name[100];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    scanf("%d", &N);
    while (N--) {
        scanf("%s %d/%*d/%*d %d/%*d/%*d %d", &name, &yearStudies, &yearBirth, &courses);
        printf(name);
        if (yearStudies >= 2010 || yearBirth >= 1991) {
            printf(" eligible\n");
        } else if (courses > 40) {
            printf(" ineligible\n");
        } else {
            printf(" coach petitions\n");
        }
    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}