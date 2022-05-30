/*
 ============================================================================
 Name        : LynnerP2.c
 Author      : Skylar Lynner
 Description : ICS 365 Program 2 - Spring 2022
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INTS 100

char *inFile, *outFile;
FILE *readFile, *writeFile;
int inputArray[MAX_INTS];
int outputArray[MAX_INTS];
int arraySize;

// reads input file
void read_file (char* file)
{
        int i = 0;
        if ( (readFile = fopen(file, "r")) == NULL )
        {
                printf("error opening file %s \n", file);
                exit(1);
        }
        else
        {
                printf("reading %s \n", file);
                while(!feof(readFile))
                {
                        fscanf(readFile, "%d", &inputArray[i]);
                        i++;
                }
                arraySize = i - 1;
                fclose(readFile);
        }
}
// copies inputArray into outputArray
void copy_array()
{
        for (int i=0; i<arraySize; i++) {
                outputArray[i] = inputArray[i];
        }
}

// swaps first and second values
void swap(int* first, int* second)
{
        int temp = *first;
        *first = *second;
        *second = temp;
}

// sort array smallest value to largest value
void sort_array() {
        int min;
        for (int i=0;i<arraySize;i++)
        {
                min = i;
                for(int j=i+1;j<arraySize;j++)
                {
                        if(outputArray[j] < outputArray[min]) {
                                min = j;
                        }
                        swap(&outputArray[min], &outputArray[i]);
                }
        }
}

// compares inputArray and outputArray
// returns false if arrays are the same
bool are_arrays_different()
{
        for (int i=0; i<arraySize; i++)
        {
                if (inputArray[i] != outputArray[i]) { return true; }
        }
        return false;
}

// writes outputArray into file
void write_file (const char* file_name)
{
        printf("writing to file %s \n", file_name);
        if ( (writeFile = fopen(file_name, "w")) == NULL)
        {
                printf("error opening file %s \n", file_name);
                exit(1);
        }

        for(int i=0;i<arraySize;i++)
        {
                fprintf(writeFile, "%d\n", outputArray[i]);
        }
        fclose(writeFile);
}

int main(int argc, char **argv)
{
        inFile = argv[1];
        outFile = argv[2];

        read_file(inFile);
        copy_array();
        sort_array();

        if (are_arrays_different()) { write_file(outFile); }
        else
        {
                puts("File already sorted.");
                return 1;
        }

        return EXIT_SUCCESS;
}
