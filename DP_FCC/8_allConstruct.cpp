#include <bits/stdc++.h>
using namespace std;

#define sz(i)               (int) i.size()
#define mp					make_pair
#define fromTo(var, from, to)          for(int var = from; var < to; ++var)
typedef long long ll;


int wordsCount;
int maxWordsCount = 301;
vector<string> words(301);

// Memoization this is not worth it because by definiton it
// asks you for all possible cases where it's valid.
// i.e. memoization of this problem doesn't help in case of 'worst-case',
// and last test-case is not the worst-case, it would be this:
// 1
// 3 eeeeeeeeeeeeeeeeeeeeeee
// e ee eee
// Instructor added a memo, but for C++, not worth the hassle :)

// This might need some C++ related optimization (e.g. not copying vector of vectors),
// of which I currently don't care.
// O(n^m * ?) time, ?O(m)? space.
vector<vector<string>> allConstruct(string target) {
    if(target == "")
        return { { } };

    vector<vector<string>> ans;

    fromTo(i, 0, wordsCount) {
        int preIdx = 0;
        fromTo(j, 0, sz(words[i])) {
            if(target[j] == words[i][j])
                preIdx++;
            else
                break;
        }

        if(preIdx == sz(words[i])) {
            string sub = "";
            fromTo(k, preIdx, sz(target))
                sub += target[k];

            vector<vector<string>> test = allConstruct(sub);
            fromTo(j, 0, sz(test)) {
                test[j].push_back(words[i]);
                ans.push_back(test[j]);
            }
        }
    }

    return ans;
}

// O(~n^m) time, O(~n^m) space.
vector<vector<string>> allConstructTabu(string target) {
    int siz = sz(target) + 1;
    // This... looks scary.
    vector<vector<vector<string>>> tabu(siz);

    // I guess closest line to JS in the entire course. 
    tabu[0] = { { } };

        fromTo(i, 0, siz) {
        if(sz(tabu[i]) != 0) {
            fromTo(j, 0, wordsCount) {
                string targetSlice = "";
                // potenial segmentation fault bug
                fromTo(k, i, sz(words[j]) + i)
                    targetSlice += target[k];
                
                if(targetSlice == words[j]) {
                    fromTo(k, 0, sz(tabu[i])) {
                        tabu[i + sz(words[j])].push_back(tabu[i][k]);
                        tabu[i + sz(words[j])].back().push_back(words[j]);
                    }
                }
            }
        }
    }

    return tabu[siz - 1];
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
        string target;
        cin >> wordsCount >> target;
        fromTo(i, 0, wordsCount)
            cin >> words[i];
        
        vector<vector<string>> ans = allConstructTabu(target);

        if(sz(ans) <= 0)
            cout << "-1\n";
        fromTo(i, 0, sz(ans)) {
            // Reversed, I guess a to-do fix.
            fromTo(j, 0, sz(ans[i])) {
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    cout << "\nBe Proactive : )\n";
    return 0;
}

// in.txt:
// 6
// 5 purple
// purp p ur le purpl
// 7 abcdef
// ab abc cd def abcd ef c
// 7 skateboard
// bo rd ate t ska sk boar
// 7 enterapotentpot
// a p ent enter ot o t
// 6 eeeeeeeeeez
// e
// ee
// eee
// eeee
// eeeee
