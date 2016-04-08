#  Akshay Deo
* Bugs Found:
  * In the InBound function inside will return false even if the poistion is invalid.
    * e.g.
      * If h is less than 0 ( or greater than set height) and if w is within boundary conditions the expected return would be false , but true is returned.

  * In constructor for ConnectX if any one of the condition is true then the default values are set even if the other conditions might be false.
    *e.g.
      *If send 0,1,2 as values the condition for wide<=0 will be true, but rest are fasle and even then the default values will be assigned.
