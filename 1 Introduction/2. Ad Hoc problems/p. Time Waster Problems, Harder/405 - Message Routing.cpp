#include <bits/stdc++.h>

using namespace std;

// quite a long read...
// try it yourself, check the line after the integer
// SANANTONIO    US            AIR             COLLEGE        UNO
// starting from MTA[SANANTONIO] go down each row until you find the destination
// if destination is SANANTONIO, then you are done (here it is houston line 1)
// go to MTA[HOUSTON] and go down each row until you find the destination
// here none match so routing error.

struct description {
    string D; // destination
    string C; // country
    string A; // ADMD
    string P; // PRMD
    string O; // organization
};

struct MTA {
    string ORIGIN;
    vector<description> DESCRIPTION;
};

string findNextLocation(description message, MTA MTA) {
    // if all(wildcard or match)
    for (auto &item: MTA.DESCRIPTION) {
        if ((item.C == "*" || item.C == message.C) &&
            (item.A == "*" || item.A == message.A) &&
            (item.P == "*" || item.P == message.P) &&
            (item.O == "*" || item.O == message.O)) {
            return item.D;
        }
    }
    return "ERROR";
}


void solveMessage(description message, vector<MTA> MTAs) {
    set<string> visited; // used to check for repeat visits. i like insert().second
    string currLocation = message.D;
    visited.insert(currLocation);

    while (true) {
        int i = 0;
        for (; i < MTAs.size(); i++) {
            if (MTAs[i].ORIGIN == currLocation) { // ORIGIN is the one with int beside it
                break;
            }
        }
        MTA currMTA = MTAs[i];
        string nextLocation = findNextLocation(message, currMTA);
        if (nextLocation == "ERROR") {
            cout << "unable to route at " << currLocation << endl;
            return;
        } else if (nextLocation == currLocation) {
            cout << "delivered to " << currLocation << endl;
            return;
        } else {
            currLocation = nextLocation;
            if (!visited.insert(currLocation).second) { // repeated visit!
                cout << "circular routing detected by " << currLocation << endl;
                return;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, scenario = 1;
    while (cin >> n) {
        cout << "Scenario # " << scenario++ << endl;
        // get all MTAs
        vector<MTA> MTAs;
        for (int i = 0; i < n; i++) {
            MTA mta;
            cin >> mta.ORIGIN;
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                description d;
                cin >> d.D >> d.C >> d.A >> d.P >> d.O;
                mta.DESCRIPTION.push_back(d);
            }
            MTAs.push_back(mta);
        }
        // get all messages
        cin >> n;
        vector<description> messages;
        for (int i = 0; i < n; i++) {
            description d;
            cin >> d.D >> d.C >> d.A >> d.P >> d.O;
            messages.push_back(d);
        }
        // print messages
        for (int i = 1; i <= n; i++) {
            cout << i << " -- ";
            description message = messages[i - 1];
            solveMessage(message, MTAs);
        }
        cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}