#include <stdio.h>
#include <stdlib.h>

#define N 9
#define UNASSIGNED 0

void getInput(int puzzle[N][N], const char *filename);
void printPuzzle(int puzzle[9][9]);
int solve(int puzzle[][9]);
int find_empty_cell(int puzzle[][9], int *row, int *column);
int valid(int puzzle[][9], int row, int column, int guess);

void getInput(int puzzle[N][N], const char *filename)
{

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (fscanf(file, "%d", &puzzle[i][j]) != 1)
            {
                printf("Invalid input in file. Please make sure the file contains a valid Sudoku puzzle.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);

    printf("\nEntered Sudoku puzzle:\n");
    printPuzzle(puzzle);

    printf("\n\n");

    if (solve(puzzle))
    {
        printf("The Solution for the Puzzle  : \n");
        printPuzzle(puzzle);

        FILE *outputFile = fopen("output.txt", "w");
        if (outputFile == NULL)
        {
            perror("Error opening file for writing");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                fprintf(outputFile, "%d", puzzle[i][j]);
                if ((j + 1) % 3 == 0)
                    fprintf(outputFile, " ");
                else
                    fprintf(outputFile, " ");
            }
            fprintf(outputFile, "\n");
            if ((i + 1) % 3 == 0)
                fprintf(outputFile, "\n");
        }

        printf("Solution saved to 'output.txt'\n");

        fclose(outputFile);
    }
    else
    {
        printf("\n\nNO SOLUTION FOUND\n\n");
    }
}

void printPuzzle(int puzzle[9][9])
{
    printf("  +-----+-----+-----+-----+-----+-----+\n");
    for (int i = 0; i < 9; i++)
    {
        printf("  |  ");
        for (int j = 0; j < 9; j++)
        {
            printf("%d", puzzle[i][j]);
            if ((j + 1) % 3 == 0)
                printf("  |  ");
            else
                printf("  ");
        }
        printf("\n");
        if ((i + 1) % 3 == 0)
            printf("  +-----+-----+-----+-----+-----+-----+\n");
    }
}

int solve(int puzzle[][9])
{
    int row;
    int column;

    if (!find_empty_cell(puzzle, &row, &column))
        return 1;

    for (int guess = 1; guess < 10; guess++)
    {
        if (valid(puzzle, row, column, guess))
        {
            puzzle[row][column] = guess;

            if (solve(puzzle))
                return 1;
            puzzle[row][column] = 0;
        }
    }
    return 0;
}

int find_empty_cell(int puzzle[][9], int *row, int *column)
{
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (!puzzle[x][y])
            {
                *row = x;
                *column = y;

                return 1;
            }
        }
    }
    return 0;
}

int valid(int puzzle[][9], int row, int column, int guess)
{
    int corner_x = row / 3 * 3;
    int corner_y = column / 3 * 3;

    for (int x = 0; x < 9; ++x)
    {
        if (puzzle[row][x] == guess)
            return 0;
        if (puzzle[x][column] == guess)
            return 0;
        if (puzzle[corner_x + (x % 3)][corner_y + (x / 3)] == guess)
            return 0;
    }
    return 1;
}

int main()
{

    int row = 0;
    int column = 0;

    int puzzle[9][9];

    printf("Enter the Sudoku puzzle in the given file   :  \n");
    printf("Valid Numbers       -->         1 - 9       :\n");
    printf("For Empty Space     -->         0           :\n");
    printf("Enter elements in a row seperated by space  :\n");
    printf("Total number of elements                    : 81\n\n\n\n");
    // int puzzle[9][9];
    const char *filename;

    printf("Enter the preffered difficulty for the puzzle\n");
    printf("Levels              -->          1 - 5      : ");
    printf("\n");
    int x;
    scanf("%d", &x);

    switch (x)
    {
    case 1:
        filename = "lv1.txt";
        break;
    case 2:
        filename = "lv2.txt";
        break;
    case 3:
        filename = "lv3.txt";
        break;
    case 4:
        filename = "lv4.txt";
        break;
    case 5:
        filename = "lv5.txt";
        break;

    default:
        filename = "sudoku_input.txt";
        break;
    }

    getInput(puzzle, filename);

    return 0;
}