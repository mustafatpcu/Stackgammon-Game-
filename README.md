## **Stackgammon Game**

Stackgammon Game is an assignment given in Advanced Programming Course that focused on OOP and Data Structures .

**Data sets used:** 
- Doubly Linked List
-  Stack

**Description of the Game:**

- The game is basically a version of famous backgammon game. There are variable number of slots on the board.    Each slot can either be empty or claimed by one of the user.     
- If claimed by a user, a particular slot can contain only one type of piece (x or o). The maximum number of pieces that can be put on a slot is 4. However, when the number of pieces on a slot reaches 4, the slot is entirely destroyed; thus we never see a slot with 4 pieces on it.     
- The game is played in rounds and at each round both players play in turn. A user plays first by throwing a die that returns a random number between and including 1 and 4. Then the user plays one of its pieces on a selected claimed slot (the one on the top of the slot if there are multiple pieces on the selected slot), die amount of slots toward left or right. However, the target slot must either be claimed by the same user or must be empty for a valid move. 
- If the target slot has been claimed by the other player or beyond the boundaries of the board, then such a move is invalid. That means, you cannot throw a piece out of board and you cannot place a piece on top of your opponent's piece. During the game, it'd be possible to have situations that the user cannot play any of its pieces; in such a case, the user should create a new slot (to the beginning or to the end, depending on its choice) and put one piece there. As you can see, the number of pieces at the original setup remains the same if a piece is moved from one slot to another. However, when a particular slot reaches 4 same type pieces, since we destroy that slot, number of pieces is reduced. 
- Moreover, when a move is not possible, one piece is added on a new slot and the number of pieces is increased. The strategy of the game is to end up with smallest number of pieces at the end of the game. The player with smallest number of pieces wins the game (of course tie is also possible). You may check out the sample runs to better understand the game logic.


**Sample Run:**

```cpp
[*] Welcome to the Stackgammon Game!
[*] Enter a board configuration:
1x/2x/3x/3o/2o/1o
xo
xxoo
xxxooo
^^^^^^
[*] Enter a round limit:
1
[*] Enter a random number generator seed:
1
[*] Round 0
[x] X's turn:
Throwing die...
Die is 2.
[x] Make your move. State the index (starts from 0) of your piece you want to move, and right (1) or left (0):
0 1
o
xoo
xooo
^^^^^
[o] O's turn:
Throwing die...
Die is 4.
[o] Make your move. State the index (starts from 0) of your piece you want to move, and right (1) or left (0):
4 0
o
xoo
oxoo
^^^^^
[*] Game over!
```


