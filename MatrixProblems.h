#include "common.h"


struct Rotateconfig
{
   int col_start = 0;
   int col_end = 0;
   int row_start = 0;
   int row_end = 0;
};

void rotateMatrix(int a[][4], Rotateconfig rotateconfig)
{
    int row_idx = 0, col_idx=0;
    int temp1=0, temp2=0;
    for(col_idx = rotateconfig.col_start; col_idx < rotateconfig.col_end; col_idx++)
    {
        if(col_idx == rotateconfig.col_start)
        {
            temp1 = a[rotateconfig.row_start][col_idx];
        }
        a[rotateconfig.row_start][col_idx] = a[rotateconfig.row_start][col_idx+1];
    }
    for(row_idx = rotateconfig.row_end; row_idx > rotateconfig.row_start; row_idx--)
    {
        if(row_idx == rotateconfig.row_end)
        {
            temp2 = a[row_idx][rotateconfig.col_start];
        }
        if(row_idx == rotateconfig.row_start+1)
        {
            a[row_idx][rotateconfig.col_start] = temp1;
        }
        else
        {

            a[row_idx][rotateconfig.col_start] = a[row_idx-1][rotateconfig.col_start];
        }

    }

    for(col_idx = rotateconfig.col_end; col_idx > rotateconfig.col_start; col_idx--)
    {
        if(col_idx == rotateconfig.col_end)
        {
            temp1 = a[rotateconfig.row_end][col_idx];
        }
        if(col_idx==rotateconfig.col_start+1)
        {
            a[rotateconfig.row_end][col_idx]= temp2;
        }
        else
        {
            a[rotateconfig.row_end][col_idx] = a[rotateconfig.row_end][col_idx-1];
        }
    }

    for(row_idx = rotateconfig.row_start; row_idx < rotateconfig.row_end; row_idx++)
    {
        if(row_idx == rotateconfig.row_end-1)
        {
            a[row_idx][rotateconfig.col_end] = temp1;
        }
        else
        {
            a[row_idx][rotateconfig.col_end] = a[row_idx+1][rotateconfig.col_end];
        }

    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
}
