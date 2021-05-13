Proyecto Integrador PI 
Programacion Estructurada

In my project my idea is to program the board game called connect 4. 

Connect Four is a two-player game in which players alternately place pieces on a vertical board 7 columns across and 6 rows high. 
Each player uses pieces of a particular color, and the object is to be the first to obtain four pieces in a horizontal, vertical, or diagonal line. 
Because the board is vertical, pieces inserted in a given column always drop to the lowest unoccupied row of that column. 
As soon as a column contains 6 pieces, it is full and no other piece can be placed in the column.

Both players begin with 21 identical pieces, and the first player to achieve a line of four connected pieces wins the game. 
If all 42 places are played and no player has places four pieces in a row, the game is drawn.

Since I can not use colors in my program to play, I will let the users choose their symbol the want to use in the vistual board.
Using the ASCII caracters I will made the board the following way:

        |   |   |   |   |   |   |   |                                                                               
        |   |   |   |   |   |   |   |                                                                               
        |   |   |   |   |   |   |   |                                                                               
        |   |   |   |   |   |   |   |                                                                               
        |   |   |   |   |   |   |   |                                                                               
        |   |   |   |   |   |   |   |                                                                               
        |   |   |   |   |   |   |   |                                                                               
        |   |   |   |   |   |   |   |                                                                               
         ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ 

Then by turns the program will ask for the number of the column that the player wants to play Then the board will start to fill.
Example:

        |   |   |   |   |   |   |   |                                                                               
        |   |   |   |   |   |   |   |                                                                               
        |   |   |   |   |   |   |   |                                                                               
        |   |   |   |   | X |   |   |                                                                               
        |   |   | O | X | O |   |   |                                                                               
        | X | O | X | X | O |   | O |                                                                               
         ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ 

Until a player achieve to connect 4 pieces i one row and win or until the board has no more available places and in that case that wil be tie.
Win example

        |   |   |   |   |   |   |   |        |   |   |   |   |   |   |   |        |   |   |   |   |   |   |   |
        |   |   |   |   |   |   |   |        |   |   |   |   |   |   |   |        |   |   |   |   |   |   |   |
        |   |   |   |   |   |!X!|   |        |   |   |   |   |   |   |   |        |   |   |!X!|   |   |   |   |
        |   |   |   | O |!X!| X |   |        |   |   |   |   |   |   |   |        |   |   |!X!|   |   |   |   |
        |   |   | O |!X!| O | O | X |        |   |   |   | O | O |   |   |        |   | O |!X!|   |   |   |   |
        | X | O |!X!| X | O | O | O |        |   | O |!X!|!X!|!X!|!X!|   |        | O | O |!X!| O | O | X |   |
         ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯          ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯          ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯

To program this I plan to do:
1. Do a two dimension array that will contain the places of the board where the pieces are played
2. In main It will show a menu with the options to read the rules, play in 2 player mode and play in single player mode with three possible difficulties
3. A funtction that prints the board with the value it has in each cell, | 'X' | 'O' | ' ' |
4. A funtion to request each player where they want to play and store it in the array
5. A recursive function that reads the board every time to check if someone won
6. A function to make random movements of the machine in single player mode
7. Another funtion that the sistem use to read the board and to block you if you are about to win.
   And the difficulties will work so that in Difficult it will just block you, in Normal it will have a 50% chance of blocking you and in Easy it will have a 25% chance of blocking you (all made with ramndom statments)

