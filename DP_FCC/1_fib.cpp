#include <bits/stdc++.h>
using namespace std;

#define fromTo(var, from, to)          for(int var = from; var < to; ++var)
typedef long long       ll;

// Just making sure I don't screw stuff up :)
int globalCounter = 0;

// classic implementation, O(2^n) for time, O(n) for space
// About the tree structure of this function:
// Starting from the root, each recursive call will have 2 "Children"
// A tree of n height, with 1 * 2 ...children in each level.
// See function dib() in the video.
ll fib(int n) {
    if(n <= 2)
        return 1;

    return fib(n - 1) + fib(n - 2);
}


// Memoization, stroing answers to those overlapping sub-problems
// o(n) for time & space
// P.S: In very tight situations (?maybe embedded systems?),
// you have to think of the cost of recursive call Vs. the cost of a normal array fetch,
// meaning, production code != problem solving or competitive programming code, imho.

int memoSize = 51;
vector<ll> mem(memoSize, -1); // Note: vector initializes to 0 by defaut.
ll fibMemo(int n) {
    // Just for it to be 1-indexed.
    if(n <= 2)
        return 1;

    if(mem[n] != -1)
        return mem[n];
    
    // globalCounter++:
    mem[n] = fibMemo(n - 1) + fibMemo(n - 2);
    return mem[n];
}

// O(n) time, O(n) space 
ll fibTabu(int n) {
    vector<ll> arr(n + 1);
    arr[0] = 0;
    arr[1] = 1;

    fromTo(i, 0, n + 1) {
        if (i + 1<= n)
            arr[i + 1] += arr[i];
        
        if (i + 2 <= n)
            arr[i + 2] += arr[i];
    }
    return arr[n];
}

int main() {
    // Print output after excution => Less time, remove if needed.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fib(6) << '\n';
    cout << fib(7) << '\n';
    cout << fibMemo(50) << '\n';
    cout << fibTabu(50) << '\n';
    // cout << globalCounter << '\n';

    cout << "Be Proactive : )";
    return 0;
}