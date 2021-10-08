#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int loShuWorks[3][3] = {
    {4, 9, 2},
    {3, 5, 7},
    {8, 1, 6}
};

int loShuFails[3][3] = {
    {4, 1, 2},
    {3, 5, 7},
    {8, 9, 6}
};

int testLoShu(int square[3][3]);

void createLoShu()
{
    time_t t;
    int square[3][3];
    int usedNumbers[9];
    int isLoShu = 0;
    int count = 0;
    int randNumber;
    srand((unsigned) time(&t));
    do{
        for (int i = 1; i < 10; i++) {   
            usedNumbers[i] = i;
        }

        for (int i = 0; i < 10; i++) {    
            int temp = usedNumbers[i];
            int randomIndex = (rand() % 8) + 1;
            usedNumbers[i] = usedNumbers[randomIndex];
            usedNumbers[randomIndex] = temp;
        }

        int usedNumbersCounter = 0;
        for(int row = 0; row < 3; row++)
        {
            for(int column = 0; column < 3; column++)
            {
                square[row][column] = usedNumbers[usedNumbersCounter];
                usedNumbersCounter++;
            }
        }
        isLoShu = testLoShu(square);
        count++;
    } while(isLoShu == 0);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
        {
            if(j == 0) {
                printf("[");
            }
            printf("%3d ", square[i][j]);
            if(j == 2) {
                printf("]\n");
            }
        }
    }
    printf("The count is: %d", count);
}

int testLoShu(int square[3][3])
{
    int row1 = 0;
    int row2 = 0;
    int row3 = 0;
    int column1 = 0;
    int column2 = 0;
    int column3 = 0;
    int diagonal1 = 0;
    int diagonal2 = 0;

    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            if(row == 0)
            {
                row1 += square[row][column];
            } else if(row == 1)
            {
                row2 += square[row][column];
            } else if(row == 2)
            {
                row3 += square[row][column];
            }

            if(column == 0)
            {
                column1 += square[row][column];
            } else if(column == 1)
            {
                column2 += square[row][column];
            } else if(column == 2)
            {
                column3 += square[row][column];
            }

            if(column == row) {
                diagonal1 += square[row][column];
            }

            if(column == 2 & row == 0 || row == 2 && column == 0 || column == 1 & row == 1)
            {
                diagonal2 += square[row][column];
            }
        }
    }

    if(row1 == row2 && row2 == row3 && row1 == column1 && column1 == column2 && column2 == column3)
    {
        return 1;
    } else 
    {
        return 0;
    }
}

int main() {
    printf("Testing correct square: %d\n", testLoShu(loShuWorks));
    printf("Testing incorrect square: %d\n", testLoShu(loShuFails));
    printf("Printing randomly generate LoShu Square\n");
    createLoShu();
}