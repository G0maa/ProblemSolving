#include <bits/stdc++.h>
using namespace std;

#define mp					make_pair
#define pb                  push_back
#define sz(i)               (int)i.size()
#define clr(v, d)			memset(v, d, sizeof(v)) // clear stuff
#define all(v)				((v).begin()), ((v).end()) // begin to end
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)

typedef vector<int> vi;
typedef long long ll;
const ll OO = 1e9 + 1; // Big number.
const double EPS = (1e-7); // Small number.

// Double compare, if equal return 0, x bigger return -1, y bigger return 1.
int dcmp(double x, double y) { return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b);}

// CF#236 - D2 - C - Searching for Graph = 02/07/22 (DD,MM,YY)
// https://codeforces.com/contest/402/problem/C

// One of the solutions I'm proud of, 2 Hours thinking, 10 minutes coding.
// Thought prcess:
// - I was thinking at first of mimicking the given test case solution,
// until I realized that would create erm... "unbalanced" graph.
// - I drew lots of graphs, that why I probably noticed that this ^ would be wrong.
// - Eventaully at some point I generalized the problem to where:
// "I am trying to draw a graph progressively such that each 
// vertex has edges that can't exceed the edges of other vertexes by 2."
// Even here I wasn't sure I could solve this in a "coencice" way,
// I thought of using a vector<set<int>>, thankfully I eventually got here.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("D:\\3_Studies\\MyGithubFolder\\2_ProblemSolving\\in.txt", "r", stdin);
    // freopen("D:\\3_Studies\\MyGithubFolder\\2_ProblemSolving\\out.txt", "w", stdout);

    int t; 
    cin >> t;
    while(t--) {
        int n, p;
        cin >> n >> p;
        int edges = (2 * n) + p;

        int jmp = 1, stopped_at = 0, tries = n, temp;

        // If edges are more than (n*(n-1))/2 it would produce wrong answers.
        while(edges--) {
            temp = ((stopped_at + jmp) % n) + 1;

            cout << stopped_at + 1 << ' ' << temp << '\n';

            stopped_at = (stopped_at + 1) % n;

            // a graph of n vertcies has (n-1) / 2 "Iterations",
            // all of n steps but the last one.
            tries--;
            if(tries == 0) {
                jmp++;
                tries = n;
            }
        }
    }

    // cout << "\n\nSalam :)\n\n";
    return 0;
}