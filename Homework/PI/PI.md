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
        |   |   |   |   |   |   |   |        |   |   |   |   |   |   |   |        |   |   |   |   |   |   |   |
        |   |   |   |   |   |   |   |        |   |   |   |   |   |   |   |        |   |   |   |   |   |   |   |
        |   |   |   |   |   |!X!|   |        |   |   |   |   |   |   |   |        |   |   |!X!|   |   |   |   |
        |   |   |   | O |!X!| X |   |        |   |   |   |   |   |   |   |        |   |   |!X!|   |   |   |   |
        |   |   | O |!X!| O | O | X |        |   |   |   | O | O |   |   |        |   | O |!X!|   |   |   |   |
        | X | O |!X!| X | O | O | O |        |   | O |!X!|!X!|!X!|!X!|   |        | O | O |!X!| O | O | X |   |
         ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯          ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯          ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯ ¯¯¯



