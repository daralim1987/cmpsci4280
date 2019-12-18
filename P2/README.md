# P2

## CFG

```
<program>   ->      program <vars> <block>
<block>     ->      start <vars> <stats> stop
<vars>      ->      empty | int Identifier <mvars> 
<mvars>     ->      empty | : Identifier <mvars>
<expr>      ->      <M> * <expr> | <M>
<M>         ->      <T> / <M> | <T>
<T>         ->      <F> + <T> | <F> - <T> | <F>
<F>         ->      & <F> | <R>
<R>         ->      ( <expr> ) | Identifier | Number   
<stats>     ->      <stat>  <mStat>
<mStat>     ->      empty | <stat>   <mStat>
<stat>      ->      <in> | <out> | <block> | <if> | <loop> | <assign>
<in>        ->      read >> Identifier ; 
<out>       ->      print << <expr>  
<if>        ->      decision ( <expr> <RO> <expr> ) <block>             
<loop>      ->      while ( <expr> <RO> <expr> ) <block>
<assign>    ->      Identifier = <expr> ;                               // = is one token here
<RO>        ->      << | << = | >> | >> = | == | =!                     // == is one token here
```

## Suggestions

**Implement the parser in two iterations:**

1. Starting without the parse tree. Have your parses generate error (line number and tokens involved) or print OK message upon successful parse. 
   - For each nonterminal, use a void function named after the nonterminal and use only explicit returns. Decide how to pass the token. Have the main program call the parser after setting up the scanner if any.
   - Be systematic: assume each function starts with unconsumed token (not matched yet) and returns unconsumed token. Use version control and be ready to revert if something gets messed up.
2. Only after completing and testing the above to satisfaction, modify each function to build a subtree, and return its root node. Assume each function builds just the root and connects its subtrees. Modify the main function to receive the tree built in the parser, and then display it (for testing) using the preorder treePrint().

**Some hints for tree:**

- every node should have a label consistent with the name of the function creating it (equal the name?)
- every function creates exactly one tree node (or possibly none)
- the number of children seems as 3 or 4 max but it is your decision
- all syntactic tokens can be thrown away, all other tokens (operators, IDs, Numbers) need to be stored
- when storing a token, you may need to make a copy depending on your interface

## Test files for good programs

Create files using the algorithm to generate programs from the grammar, starting with simplest programs one different statement at a time and then building sequences of statements and nested statements. You may skip comments but then test comment in some files.

## Test files for bad programs

Create some bad programs, possibly by modifying with an error each program that was good. Make sure the error is discovered.
