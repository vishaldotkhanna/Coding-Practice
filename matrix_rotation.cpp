#include<iostream>
#include<vector>

#define MATRIX_SIZE 3

using namespace std;

typedef long long LL;

//Inplace matrix rotation.

int display_matrix(int m[][MATRIX_SIZE])
{
    for(int i = 0;i < MATRIX_SIZE;i++)
    {
        for(int j = 0;j < MATRIX_SIZE;j++)
            cout<<m[i][j]<<" ";

        cout<<endl;
    }

    return 0;
}

int transpose_matrix(int m[][MATRIX_SIZE])
{
    for(int i = 0;i < MATRIX_SIZE;i++)
    {
        for(int j = i;j < MATRIX_SIZE;j++)
        {
            int temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }

    return 0;
}

int rotate_anticlockwise(int m[][MATRIX_SIZE])
{
    transpose_matrix(m);

    for(int j = 0;j < MATRIX_SIZE;j++)
    {
        for(int i = 0;i < (MATRIX_SIZE - i - 1);i++)
        {
            int temp = m[i][j];
            m[i][j] = m[MATRIX_SIZE - i - 1][j];
            m[MATRIX_SIZE - i - 1][j] = temp;
        }
    }

    display_matrix(m);

    return 0;
}

int rotate_clockwise(int m[][MATRIX_SIZE], bool display_result)
{
    transpose_matrix(m);

    for(int i = 0;i < MATRIX_SIZE;i++)
    {
        for(int j = 0;j < (MATRIX_SIZE - j - 1);j++)
        {
            int temp = m[i][j];
            m[i][j] = m[i][MATRIX_SIZE - j - 1];
            m[i][MATRIX_SIZE - j - 1] = temp;
        }
    }

    if(display_result)
        display_matrix(m);

    return 0;
}

int main()
{
    int mat[MATRIX_SIZE][MATRIX_SIZE] = {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                    };

    rotate_clockwise(mat, true);

    cout<<endl;

    int i = 3;
    while(i--)
        rotate_clockwise(mat, false);   //To bring the matrix back to its original state before rotating anti-clockwise.

    rotate_anticlockwise(mat);
}
