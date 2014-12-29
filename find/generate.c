/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int main(int argc, string argv[])
{
    // If the number of command line arguments is not equal to 2 and is also not equal to 3 then return (print) the following message.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    //Convert the 2nd command line argument argv[1] to a variable named 'n' (which is of type integer).
    int n = atoi(argv[1]);

    //If the no. of cmd-line arguments (argc) is equal to 3, then use the integer conversion (atoi) of the 3rd cmd-line argument (argv[2]) as the seed (positive int), else seed is NULL.
    if (argc == 3)
    {
        srand((unsigned int) atoi(argv[2]));
    }
    else
    {
        srand((unsigned int) time(NULL));
    }

    //While i is less than n (n being the required number of psuedorandom numbers) print a psuedorandom number modulo 65536, the pre-defined max range limit. Repeat loop and increment i with each pass. 
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", rand() % LIMIT);
    }

    // that's all folks
    return 0;
}
