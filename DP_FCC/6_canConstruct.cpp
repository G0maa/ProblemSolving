#include <bits/stdc++.h>
using namespace std;

#define sz(i)               (int) i.size()
#define mp					make_pair
#define fromTo(var, from, to)          for(int var = from; var < to; ++var)
typedef long long ll;
// Just making sure I don't screw stuff up :)
// int globalCounter = 0;

int wordsCount;
int maxWordsCount = 301;
vector<string> words(301);

// |words| = n,  |target| = m.
// O(n^m * m) time, O(m^2) space. again revise space complexity here.
bool canConstruct(string target) {
    if (target == "")
        return true;
    
    
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

            if(canConstruct(sub) == true)
                return true;
        }
    }

    return false;
}

map<string, bool> mem;

// O(n * m^2) for time, O(m^2) for space.
bool canConstructMemo(string target) {
    if (target == "")
        return true;
    
    map<string, bool>::iterator it = mem.find(target);
    if(it != mem.end())
        return it->second;
    
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

            if(canConstructMemo(sub) == true) {
                mem.insert(mp(target, true));
                return true;
            }  
        }
    }

    mem.insert(mp(target, false));
    return false;
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
        mem.clear();

        string target;
        cin >> wordsCount >> target;
        fromTo(i, 0, wordsCount)
            cin >> words[i];
        
        bool ans = canConstructMemo(target);
        cout << (ans ? "True\n" : "False\n");
    }
    cout << "\nBe Proactive : )\n";
    return 0;
}

// in.txt:
// 5
// 5 abcdef
// ab abc cd def abcd
// 7 skateboard
// bo rd ate t ska sk boar
// 7 enterapotentpot
// a p ent enter ot o t
// 6 eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef
// e
// ee
// eee
// eeee
// eeeee
// eeeeee
// 6 eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeff
// e
// ee
// eee
// eeee
// eeeee
// eeeeee
