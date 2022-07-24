#include <bits/stdc++.h>
using namespace std;

#define sz(i)               (int) i.size()
#define fromTo(var, from, to)          for(int var = from; var < to; ++var)
typedef long long ll;
// Just making sure I don't screw stuff up :)
// int globalCounter = 0;

// Same as the last one, most difference here is in the actual 'getting it to work' part
// not the optimization part.
int maxNumCount = 301;
int enterdNumCount;
vector<int> arr(301);

// For space: for every recursive call you have two vectors, at worst case of length m.
// O(n^m * m) time, sapce O(m^2)

// #2:07 #to-do later, revise his code of the last problem
// This space complexity either I don't get it or:
// This one is 2m^2, with shortest combination vector,
// which is in reality (m * m-1)/2 ~~ m^2
// the last one 4_ is m^2,
vector<int> bestSum (int m) {
    if(m == 0) return { 0 };
    if(m < 0) return { -1 }; // *shrug*

    vector<int> shortestCombination = { -1 };

    for(int i = 0; i < enterdNumCount; ++i) {
        vector<int> temp = bestSum(m - arr[i]);
        if(temp.back() != -1) {
            // temp.pop_back(); cant do that here.
            temp.push_back(arr[i]);
            if(shortestCombination[0] == -1 || (int) temp.size() < shortestCombination.size())
                shortestCombination = temp;
        }
    }

    return shortestCombination;
}

int maxM = 501;
vector<vector<int>> mem(maxM);

// For space: m keys, each key has at most m sized array.
// O(n * m^2) time, sapce O(m^2)
vector<int> bestSumMemo (int m) {
    if(m == 0) return { 0 };
    if(m < 0) return { -1 }; // *shrug*
    if(mem[m].size() >= 1) return mem[m];

    vector<int> shortestCombination = { -1 };

    for(int i = 0; i < enterdNumCount; ++i) {
        vector<int> temp = bestSumMemo(m - arr[i]);
        if(temp.back() != -1) {
            // temp.pop_back(); cant do that here.
            temp.push_back(arr[i]);
            if(shortestCombination[0] == -1 || (int) temp.size() < shortestCombination.size())
                shortestCombination = temp;
        }
    }

    mem[m] = shortestCombination;
    return mem[m];
}

// O(n*m^2) for time, O(m^2) for space.
vector<int> bestSumTabu(int m) {
    vector<vector<int>> tabu(m + 1);

    tabu[0] = { 0 };

    fromTo(i, 0, m + 1) {
        if(sz(tabu[i]) >= 1) {
            fromTo(j, 0, enterdNumCount) {
                if(i + arr[j] <= m) {
                    // If next position is embty or 
                    // current position + addition size is less than next position current size.
                    if(sz(tabu[i + arr[j]]) == 0 || sz(tabu[i]) + 1 < sz(tabu[i + arr[j]])) {
                        tabu[i + arr[j]] = tabu[i]; // copy
                        tabu[i + arr[j]].push_back(arr[j]);
                    }
                }
            }
        }
    }

    return tabu[m];
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

        vector<int> ans = bestSumTabu(targetSum);
        
        // Note, we start from 1, empty line = no answer,
        if((int) ans.size() <= 1)
            cout << "-1";

        fromTo(i, 1, (int) ans.size())
            cout << ans[i] << ' ';
        cout << '\n';
    }
    cout << "\nBe Proactive : )\n";
    return 0;
}

// in.txt:
// 4
// 4 7
// 5 3 4 7
// 3 8
// 2 3 5
// 3 8
// 1 4 5
// 4 100
// 1 2 5 25
