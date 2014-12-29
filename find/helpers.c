/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include "helpers.h"

// Returns true if value is in array of n values, else false.

bool search(int value, int values[], int n)
{
    if (value < 1)
    {
        return false;       
    }

//Binary search algorithm
    
        //Set variables that enables us to shift first, middle and last values
    
        int firstvalue = 0;
        int lastvalue = n-1;
        int middlevalue = (lastvalue-firstvalue)/2;
        
        //While first value of array block is less than the last value of same array block
        
        while (firstvalue <= lastvalue) 
        {
            if (values[middlevalue] == value) //look at middle of the list, if middle value equals value
            {
                return true; //Value found                
            }
            else if (values[middlevalue] < value) //if middle value is less than desired value 
            {
                firstvalue = middlevalue + 1; //reset firstvalue to be the middle value + 1 (so we don't recheck middle value)
            }
            else if (values[middlevalue] > value) //if middle value is greater than desired value 
            {
                lastvalue = middlevalue - 1; //reset lastvalue to be the middle value - 1 (so we don't recheck middle value)
            }
            middlevalue = (firstvalue + lastvalue)/2; //reset middlevalue based on new first/last value  
         }
            
    return false; // Else number not found
    
}

//Sorts array of n values.
 
void sort(int values[], int n)
{ 

// Selection alorgithm       
 
    int pos, templocation;
     
    for(int i = 0; i < (n-1); i++) 
    {   
        pos =  i;
        
        for (int j = i + 1; j < n ; j++)
        
        {
            
            if (values[j] < values[pos])
            
            { 
                pos = j;
                
            }
            
            if (pos != i)
            {
            
                templocation = values[i]; 
                values[i] = values[pos];
                values[pos] = templocation;
            }
        }   
    }         
    return;
}
