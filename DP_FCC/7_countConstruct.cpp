#include <bits/stdc++.h>
using namespace std;

#define sz(i)               (int) i.size()
#define mp					make_pair
#define fromTo(var, from, to)          for(int var = from; var < to; ++var)
typedef long long ll;


int wordsCount;
int maxWordsCount = 301;
vector<string> words(301);

// O(n^m * m) time, O(m^2) space.
int countConstruct(string target) {
    if(target == "")
        return 1;
    
    int ans = 0;

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

            ans += countConstruct(sub);
        }
    }

    return ans;
}


map<string, int> mem;
// O(n * m^2) time, O(m^2) space.
int countConstructMemo(string target) {
    if(target == "")
        return 1;
    
    map<string, int>::iterator it = mem.find(target);
    if(it != mem.end())
        return it->second;

    int ans = 0;

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

            ans += countConstructMemo(sub);
        }
    }

    mem.insert(mp(target, ans));
    return ans;
}

// O(m^2 * n) time, O(m) space.
int countConstructTabu(string target) {
    int siz = sz(target) + 1;
    vector<int> tabu(siz); // Visualizing as a table & filling with "default value"

    tabu[0] = 1; // seed value

    // Iterating through the table
    fromTo(i, 0, siz) {
        if(tabu[i] != 0) {
            fromTo(j, 0, wordsCount) {
                string targetSlice = "";
                // potenial segmentation fault bug
                fromTo(k, i, sz(words[j]) + i)
                    targetSlice += target[k];
                
                if(targetSlice == words[j])
                    tabu[i + sz(words[j])] += tabu[i]; // NOT ONE
            }
        }
    }

    return tabu[siz - 1];
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
        mem.clear();

        string target;
        cin >> wordsCount >> target;
        fromTo(i, 0, wordsCount)
            cin >> words[i];
        
        int ans = countConstructTabu(target);
        cout << ans << '\n';
    }
    cout << "\nBe Proactive : )\n";
    return 0;
}

// in.txt:
// 5
// 5 purple
// purp p ur le purpl
// 5 abcdef
// ab abc cd def abcd
// 7 skateboard
// bo rd ate t ska sk boar
// 7 enterapotentpot
// a p ent enter ot o t
// 6 eeeeeeeeeeeeeeeeeeeeeeeeeeeeef
// e
// ee
// eee
// eeee
// eeeee
