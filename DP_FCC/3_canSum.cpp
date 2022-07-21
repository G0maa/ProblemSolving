#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// Just making sure I don't screw stuff up :)
// int globalCounter = 0;

// It is of utmost importance observing that if m is too large,
// and arr has very small numbers e.g. 1,
// this may lead to Memory Limit Exceeded (MLE)
// Solution => Go Greedy or Go Home.

// O(n^m) time, O(m) space.
vector<int> arr;
bool canSum (int m) {
    if(m == 0)
        return true;
    if(m < 0)
        return false;
    
    for(int i = 0; i < (int) arr.size(); ++i)
        if(canSum(m - arr[i]) == true)
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

    bool flag = false;
    for(int i = 0; i < (int) arr.size(); ++i) {
        if(canSumMemo(m - arr[i]) == true) {
            mem[m] = true;
            return true;
        }
    }
        
    mem[m] = false;
    return false;
}

int main() {
    // Print output after excution => Less time, remove if needed.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // I'm not %100 sure about this assignment.
    arr = {7, 14};

    cout << canSumMemo(300) << '\n';
    cout << "Be Proactive : )";
    return 0;
}