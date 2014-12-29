/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
//TODO:
    
//Populate with numbers    
    
    int n = (d*d)-1;

    for (int i = 0; i < d; i++ ) //While we are not on bottom right tile
    {           
        //Populate columns (j) for row (i)
        
        for (int j = 0; j < d; j++)         
        {
            board[i][j] = n;     
            n--;                 
        }
    }          
           
//If odd number of sqaures, then swap 2 and 1  
    
    if ((d % 2) == 0)
    {
        int temploc = board[d-1][d-2];     
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = temploc;
        
    }         
}

/**
 * Prints the board in its current state.
 */
 
void draw(void)
{
// TODO
    
    for (int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            if(board[i][j] == 0)
            {
                printf("%2c", 95);
            }
            else
            {
                printf("%2i",board[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{

// TODO
    
    int rowbox;
    int colbox;
    int space = 0;    
    int row;
    int col;
    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                col = j;
                row = i;
            }    
            if (board[i][j] == tile)
            {
                colbox = j;
                rowbox = i; 
            }
        }
    }
    
    
    
    if (rowbox == row)
    {
    
        // First col test
    
        if(colbox == d - d)
        {    
                        
            //Switch boxes using temp locations
            
            if (board[rowbox][colbox + 1] == space)
            {
                int temp_loc = board[rowbox][colbox];
                board[rowbox][colbox] = board[row][col];
                board[row][col] = temp_loc;
                return true;
            }
            else
            {
                return false;
            }
         }  
    
        //Final col test
    
        else if (colbox == d-1)
        {
        
            //Switch boxes using temp locations
        
            if (board[rowbox][colbox-1] == space)
            {
                int temp_loc = board[rowbox][colbox];
                board[rowbox][colbox] = board[row][col];
                board[row][col] = temp_loc;
            
                return true;
            }
            else
            {
                return false;
            }    
        }
    
        //Center col test
    
        else
        {

            //Switch boxes using temp locations
        
            if ((board[rowbox][colbox + 1] == space) || (board[rowbox][colbox - 1] == space))
            {

                int temp_loc = board[rowbox][colbox];
                board[rowbox][colbox] = board[row][col];
                board[row][col] = temp_loc;
            
                return true;
            }
            else
            {
                return false;
            }   
        }
    }
        //Test: space && tile in same col then switch if true
    
        if (colbox == col)
        {
    
            //Test: tile in 1st row
        
            if(rowbox == d - d) /* could be ERROR - test*/
            {
        
                //Switch boxes using temp locations
        
                if (board[rowbox + 1][colbox] == space)
                {

                    int temp_loc = board[rowbox][colbox];
                    board[rowbox][colbox] = board[row][col];
                    board[row][col] = temp_loc;
            
                    return true;
                }
                else
                {
                    return false;
                } 
                
            }
   
            // Test: Tile in last row
            if (rowbox == d-1)
            {
                if (board[rowbox - 1][colbox] == space)
                {   
                    //switch
                    int temp_loc = board[rowbox][colbox];
                    board[rowbox][colbox] = board[row][col];
                    board[row][col] = temp_loc;
                
                    return true;
                }
                else
                {
                    return false;
                }
            }
    
            // Test: Tile in last row
            
            else
            {
                if ((board[rowbox + 1][colbox] == space) || (board[rowbox - 1][colbox] == space))
                {
                
                //switch
            
                    int temp_loc = board[rowbox][colbox];
                    board[rowbox][colbox] = board[row][col];
                    board[row][col] = temp_loc;
                    
                    return true;
                 }
                 else
                 {
                    return false;
                 }
            }
        
        }
    
    else 
    {   
        return false;
    }
}


/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
// TODO
    
    int tile = 1;
    int counter = 1;
    
    for (int i = 0; i < d; i++)
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile && counter == tile)
            {
                if (tile == d*d-1)return true;
                    tile++;
            }
            counter++;
        }
    return false;    
}

/**
 * Saves the current state of the board to disk (for testing).
 */
 
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}
