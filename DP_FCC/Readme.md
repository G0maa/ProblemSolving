# My try at: [Dynamic Programming - Learn to Solve Algorithmic Problems & Coding Challenges](https://youtu.be/oBt53YbR9Kk)
### To revise & summarize, uncomplete.
* About tracing recursive calls:
  * To-do.
* Think on paper not on computer.
  * Draw stuff when needed, you are studying.
* Dynamic Programming, a problem that has overlapping sub-problems.
* Any function with no _optimization_ and many (2+) recursive calls,
  * has exponential time complexity.
* **You always have to notice if a given problem does repeating evalutaions.**
  * Notice in fibonacci, you are given n, yet solving 2^n,
  * so therefore, there has to be repeated calculations.
* You may start with small inputs to visualize the problem easier,
  * And to build base-cases,
  * May happen to discover edge-cases too.
  * This idea, generally puts you thinking towards, "Where's the over lapping sup-problems that I can DP?"
  * Building a tree of small inputs may eventually lead to noticing the repating sup-problems, therefore coming close to a solution.
    * Generally, I'd say it depends on **your** observation skills, you may start with a wrong idea that ends with a non-dp like tree.
* In an interview context, expressing **why** that function has a time complexity of _something_, is beneficial.
  * **I kind-of skipped over that part.** -> Revise, if you can't essentially calcualte the complexity of a solution, you might be lead to think it's a DP while it's not (or vice versa), basically shooting yourself in the foot.
* About Alvin's `Memoization Recipe` for DP:
  1. Make it work.
    * Visualize the problem as a tree.
    * Implement the tree using recursion.
      * The leaves are the base-cases.
    * test it.
  2. Make it efficient.
    * Add a memo data structure.
      * Where keys = function arguments, values = return values of these function calls.
      * Note: a unique set of arguments gives a particular result.
    * add a base-case to return memo values. 
    * store return values into the memo.
* Do not try to get an efficient algorithm from the get go, get a brute-force working solution, then optimize.
* "Encode the arguments of your function into the nodes you are drawing. -> To test.
* About calculating complexity _after_ drawing a tree:
  1. Analyze the height of the tree.
    * What is the maximal distance from a top-level call to a base-case (i.e. what is the maximal distance from the root of the tree to the farthest leaf?)
      * This probably depends on the input, so keep an eye out on the worst-case.
  2. Identify the branching factor, i.e. how does the number of nodes change from level to the next.
    * Again, keep an eye out on the worst-case scenario.
  * e.g. `m` height and multiply by `2` for each level => `O(2^m)` for time, `O(m)` for space.
* How to code recursive functions:
  * Think of the base case(s), how to add the current recursive call to it.
```
"Try to think of your recursive functions in terms of a tree... from there I can use that tree to not only implement a brute-force, but to also recognize where I an optimize that brute-force."
```
* Note for competitive programming people, you can implement the `call stack` of C++ using STL stack.
  * This way you might be able to go around some limitations.
* Yet again another small note for CP people, considering your function arguments are `(i, q)` i.e. `O(i * q)`, if `i * q > 100M`, then you can reasonably assume it can't be solved in less than `1 Second`, unless you do some magic.
  * I think in some Online Judges it's `40M`.
  * This is without calculating internal recursive function complexity (like vector copy if it exists).
  * In general, if you visualize your recursion using a call tree, the complexity would be the `branching factor` to the `height` power.
    * \+ any other operation in the logic of the function itself.
* About XSum problem:
  * canSum -> Can you do it? yes/no -> Decision problem
  * howSum -> How will you do it? -> Combinatoric problem
  * bestSum -> What is the best way to do it? -> Optimization Problem
```
When you make your recursive call you assume your function works.
```
* In tabulation method, instead of doing the prolem recusively, we are doing it iteratively by building a table.
* About Alvin's `Tabulation Recipe` for DP:
  1. Visualize the problem as a table, it has to represent some kind of _again_ overlapping sub-problems... ?is it mostly one of the function arguments that gets minimized??
  2. Size the table based on the inputs.
  3. Initialize the table with default values, that are close to the problem outputs. => ture/false, integers,...
  4. Seed the trivial answer ?base-case? into the table.
  5. Iterate through the table.
  6. Fill further positions based on the current position. ?similar branching-factor in memo?
---
---
* Took `13H35M`, to finish `4H38M`.
* I take notes (this file), and write code, _which is the way to do these stuff_, but regardless you might have less-time... especially if you don't use C++.
* It looks like the main "styles" covered here are memoization & tabulation methods.
  * I suppose there are a few other styles/methods:
    * Maybe-Do. [Arabic Playlist](https://www.youtube.com/playlist?list=PLPt2dINI2MIattDutu7IOAMlUuLeN8k2p)
* This course is more intended for _I guess_ interview like questions, I took it for problem solving / CP, so we will see how we do in the long run.
  * Hopefully update this repo with DP problems.
* There's a small note, the DP styles we studied so far _kind of_ work on small numbers **in case of CP**.
