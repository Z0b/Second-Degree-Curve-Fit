/* 
Panth Patel 
AU1841020
*/

#include <stdio.h>
#include <math.h>

int main()
{
    float matrix1[3][3], matrix2[3][1], determinant = 0, inv1[3][3], final[3][1];
    float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0, sum_xy = 0, sum_x2y = 0;
    int i, j, k, n;
    printf("Enter no of data: ");
    scanf("%d", &n);
    float xy[n][2];
    printf("Enter the data: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &xy[i][0], &xy[i][1]);
    }

    for (i = 0; i < n; i++)
    {
        sum_x = sum_x + xy[i][0];
        sum_y = sum_y + xy[i][1];
        sum_x2 = sum_x2 + pow(xy[i][0], 2);
        sum_x3 = sum_x3 + pow(xy[i][0], 3);
        sum_x4 = sum_x4 + pow(xy[i][0], 4);
        sum_xy = sum_xy + (xy[i][0]) * (xy[i][1]);
        sum_x2y = sum_x2y + (pow(xy[i][0], 2)) * (xy[i][1]);
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matrix1[i][j] = 0;
        }
    }

    matrix1[0][0] = n;
    matrix1[0][1] = sum_x;
    matrix1[0][2] = sum_x2;
    matrix2[0][0] = sum_y;
    matrix1[1][0] = sum_x;
    matrix1[1][1] = sum_x2;
    matrix1[1][2] = sum_x3;
    matrix2[0][1] = sum_xy;
    matrix1[2][0] = sum_x2;
    matrix1[2][1] = sum_x3;
    matrix1[2][2] = sum_x4;
    matrix2[0][2] = sum_x2y;

    // Calculating Determinant

    for (i = 0; i < 3; i++)
    {
        determinant = determinant + (matrix1[0][i] * (matrix1[1][(i + 1) % 3] * matrix1[2][(i + 2) % 3] - matrix1[1][(i + 2) % 3] * matrix1[2][(i + 1) % 3]));
    }

    // Finding Inverse

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            inv1[i][j] = (((matrix1[(j + 1) % 3][(i + 1) % 3] * matrix1[(j + 2) % 3][(i + 2) % 3]) - (matrix1[(j + 1) % 3][(i + 2) % 3] * matrix1[(j + 2) % 3][(i + 1) % 3])) / determinant);
        }
    }


    //Printing the solution of a b c

    for (i = 0; i < 3; i++)
    {
        final[i][0] = inv1[i][0] * matrix2[0][0] + inv1[i][1] * matrix2[1][0] + inv1[i][2] * matrix2[2][0];
    }

    printf("Solution : \n");
    printf("a = %0.1f\nb = %0.1f\nc = %f\n", final[0][0], final[1][0], final[2][0]);
    printf("Value corresponding to 185cm is %f", final[0][0] + (final[1][0]) * 185 + pow(185, 2) * final[2][0]);

    //Plotting
    FILE *fp = NULL;
    fp = fopen("plot.txt", "w");
    float x, y;
    for (x = 100; x < 201; x++)
    {
        y = final[0][0] + (final[1][0]) * x + pow(x, 2) * final[2][0];
        fprintf(fp, "%f\t %f\n", x, y);
    }
    fclose(fp);
    fp = fopen("plot.txt", "a");

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%f\t %f\n", xy[i][0], xy[i][1]);
    }
    fclose(fp);
}
