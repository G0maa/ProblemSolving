#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define sz(i)               (int) i.size()
#define fromTo(var, from, to)          for(int var = from; var < to; ++var)

// Just making sure I don't screw stuff up :)
// int globalCounter = 0;

// It is of utmost importance observing that if m is too large,
// and arr has very small numbers e.g. 1,
// this may lead to Memory Limit Exceeded (MLE)
// Solution => Go Greedy or Go Home.

// O(n^m) time, O(m) space.
int numCount;
int maxNumCount = 301;
vector<int> numArr(maxNumCount);
bool canSum (int m) {
    if(m == 0)
        return true;
    if(m < 0)
        return false;
    
    fromTo(i, 0, numCount)
        if(canSum(m - numArr[i]) == true)
            return true;

    return false;
}

// Can't be bool, you need a value for not visited.
int maxN = 501;
vector<int> mem(maxN, -1);

// O(m * n) time, O(m) space.
// m-levels, each having n nodes.
bool canSumMemo (int m) {
    if(m == 0)
        return true;
    if(m < 0)
        return false;
    if(mem[m] != -1)
        return mem[m];

    fromTo(i, 0, numCount) {
        if(canSumMemo(m - numArr[i]) == true) {
            mem[m] = true;
            return true;
        }
    }
        
    mem[m] = false;
    return false;
}

// m = sz(arr)
// O(nm) time, O(n) space.
bool canSumTabu(int n) {
    vector<bool> tabu(n + 1);

    tabu[0] = true;

    fromTo(i, 0, n + 1) {
        if(tabu[i]) {
            fromTo(j, 0, numCount) {
                if(i + numArr[j] <= n)
                    tabu[i + numArr[j]] = true;
            }
        }
    }

    return tabu[n];
}

int main() {
    // Print output after excution => Less time, remove if needed.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Non-relative address might be needed in case of debugging.
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--) {
        mem.assign(maxNumCount, -1);

        int target;
        cin >> numCount >> target;
        fromTo(i, 0, numCount)
            cin >> numArr[i];
        
        bool ans = canSumTabu(target);
        cout << (ans ? "True\n" : "False\n");
    }
    cout << "\nBe Proactive : )\n";
    return 0;
}

// in.txt
// 5
// 2 7
// 2 3
// 4 7
// 5 3 4 7
// 2 7
// 2 4
// 3 8
// 2 3 5
// 2 300
// 7 14
