#include <bits/stdc++.h>
using namespace std;

// Just needed for printing logic
#define fromTo(var, from, to)          for(int var = from; var < to; ++var)
typedef long long ll;
// Just making sure I don't screw stuff up :)
// int globalCounter = 0;

// Implementing this in CPP is a nightmare.
// Most of the difference here was in the brute-force logic, not the memoization logic.
// again I'm not 100% sure about the use of { } here, I think this should be an initialization
// not assignment (in contrast with the one in the last problem).
int maxNumCount = 301;
int enterdNumCount;
vector<int> arr(301);

// n is arr length.
// * m for each vector copy.
// O(n^m * m) time, sapce O(m)
vector<int> howSum (int m) {
    if(m == 0) return { 0 };
    if(m < 0) return { -1 }; // *shrug*

    for(int i = 0; i < enterdNumCount; ++i) {
        vector<int> temp = howSum(m - arr[i]);
        if(temp.back() != -1) {
            // temp.pop_back(); cant do that here.
            temp.push_back(arr[i]);
            return temp;
        }
    }

    return { -1 };
}

int maxM = 501;
vector<vector<int>> mem(maxM);

// For space: m keys, each key has at most m sized array.
// O(n * m^2) time, sapce O(m^2)
vector<int> howSumMemo (int m) {
    if(m == 0) return { 0 };
    if(m < 0) return { -1 }; // *shrug*
    if(mem[m].size() >= 1) return mem[m];

    for(int i = 0; i < enterdNumCount; ++i) {
        vector<int> temp = howSumMemo(m - arr[i]); // copy
        if(temp.back() != -1) {
            // temp.pop_back(); cant do that here.
            temp.push_back(arr[i]);
            mem[m] = temp;
            return mem[m];
        }
    }

    mem[m] = { -1 };
    return mem[m];
}

int main() {
    // Print output after excution => Less time, remove if needed.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Non-relative address is needed for debugging.
    freopen("D:\\3_Studies\\MyGithubFolder\\2_ProblemSolving\\ProblemSolving\\DP_FCC\\in.txt", "r", stdin);
    freopen("D:\\3_Studies\\MyGithubFolder\\2_ProblemSolving\\ProblemSolving\\DP_FCC\\out.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--) {
        fromTo(i, 0, maxM)
            mem[i].clear();
        arr.clear();

        int targetSum;
        cin >> enterdNumCount >> targetSum;
        fromTo(i, 0, enterdNumCount)
            cin >> arr[i];

        vector<int> ans = howSumMemo(targetSum);
        
        // Note, we start from 1, empty line = no answer,
        if((int) ans.size() == 1)
            cout << "-1";

        fromTo(i, 1, (int) ans.size())
            cout << ans[i] << ' ';
        cout << '\n';
    }
    cout << "\nBe Proactive : )\n";
    return 0;
}

// in.txt:
// 7
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
// 1 7
// 7
// 1 7
// 6
