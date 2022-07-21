#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
// Just making sure I don't screw stuff up :)
// int globalCounter = 0;
// int globalCounter1 = 0;

// Grid, start: top-left, end: bottom-right, moves: down, right, how many ways to reach end?
// Visualize small inputs, and start observing.

// P.S: Again notice the difference between Problem solving or Competitive programming
// and generlly production code, I guess in a real-life situation, you'd think of a
// mathmatical soltuion, you may not have that kind of time in a contest.
// O(2^(n + m)) for time, O(n + m) for space.
ll gridTraveller(int n, int m) {
    if(n == 1  && m == 1)
        return 1;

    if(n == 0 || m == 0)
        return 0;
    
    // globalCounter1++;
    return gridTraveller(n - 1, m) + gridTraveller(n, m - 1);
}

// You can initalize it in anyway you like, or use any STL at that :)
int memoSizeRow = 51;
int memoSizeCol = 51;
vector<vector<ll>> mem(memoSizeRow, vector<ll> (memoSizeCol, -1));
// O(n * m) time, space O(n + m).
ll gridTravellerMemo(int n, int m) {
    if(n == 1  && m == 1)
        return 1;

    if(n == 0 || m == 0)
        return 0;
    
    if(mem[n][m] != -1)
        return mem[n][m];

    // globalCounter++;
    mem[n][m] = gridTravellerMemo(n - 1, m) + gridTravellerMemo(n, m - 1);
    mem[m][n] = mem[n][m]; // ~ /2

    return mem[n][m];
}

int main() {
    // Print output after excution => Less time, remove if needed.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cout << gridTraveller(1, 1) << '\n';
    // cout << gridTraveller(2, 3) << '\n';
    // cout << gridTraveller(3, 2) << '\n';
    cout << gridTraveller(5, 5) << '\n';
    cout << gridTravellerMemo(5, 5) << '\n';
    // cout << globalCounter << '\n';
    // cout << globalCounter1 << '\n';

    cout << "Be Proactive : )";
    return 0;
}