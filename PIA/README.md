# Report Producto Integrador
Programacion Estructurada.
This Program is the clasical game of Connect four. 

Connect Four is a two-player game in which players alternately place pieces on a vertical board 7 columns across and 6 rows high. 
Each player uses pieces of a particular color, and the object is to be the first to obtain four pieces in a horizontal, vertical, or diagonal line. 
Because the board is vertical, pieces inserted in a given column always drop to the lowest unoccupied row of that column. 
As soon as a column contains 6 pieces, it is full and no other piece can be placed in the column.

Both players begin with 21 identical pieces, and the first player to achieve a line of four connected pieces wins the game. 
If all 42 places are played and no player has places four pieces in a row, the game is drawn.

Since it cannot be used colors in the program to play, it let the users choose their symbol they want to use during the game.
Then by turns the program will ask for the number of the column that the player wants to play Then the board will start to fill.
Example:

        |   |   |   |   |   |   |   |                                                                               
        |   |   |   |   |   |   |   |                                                                               
        |   |   |   |   |   |   |   |                                                                               
        |   |   |   |   | X |   |   |                                                                               
        |   |   | O | X | O |   |   |                                                                               
        | X | O | X | X | O |   | O |                                                                               
         ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ 
          1   2   3   4   5   6   7
          
Win examples:

        |   |   |   |   |   |   |   |        |   |   |   |   |   |   |   |        |   |   |   |   |   |   |   |
        |   |   |   |   |   |   |   |        |   |   |   |   |   |   |   |        |   |   |   |   |   |   |   |
        |   |   |   |   |   |!X!|   |        |   |   |   |   |   |   |   |        |   |   |!X!|   |   |   |   |
        |   |   |   | O |!X!| X |   |        |   |   |   |   |   |   |   |        |   |   |!X!|   |   |   |   |
        |   |   | O |!X!| O | O | X |        |   |   |   | O | O |   |   |        |   | O |!X!|   |   |   |   |
        | X | O |!X!| X | O | O | O |        |   | O |!X!|!X!|!X!|!X!|   |        | O | O |!X!| O | O | X |   |
         ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯          ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯          ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯

With this program you can play Connect four in two player mode or in single player mode, in single player mode the program
has a medium intelligence, that is capable of blocking your attempts to connect 4 and also tries to connect 4, and it has 3 different 
difficulties where the the more difficult it only blocks you and always tries to win and the easier the possibility of blocking you or to win is less.

Then after playing the program saves a record in a file of each time you play, saving the time you played, the game mode, and who won.

## Link to the video of the program: 
https://www.youtube.com/watch?v=28nnOfaZXaI 
## Link to use the program: 
Feel free to play and enjoy: 
https://www.onlinegdb.com/yuLJXjqps 

## References: 
- Weisstein, Eric W. "Connect-Four." From MathWorld--A Wolfram Web Resource. https://mathworld.wolfram.com/Connect-Four.html
- Kernighan, B. W., & Ritchie, D. M. (2006). The C programming language.
