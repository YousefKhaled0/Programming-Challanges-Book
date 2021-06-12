#include <bits/stdc++.h>

using namespace std;

char** grid(int m, int n)
{
    char ** mat = new char*[m + 2];

    for (int i = 0 ; i < m + 2 ; i++)
    {
        mat[i] = new char [n + 2];
    }

    for (int i = 0 ; i < n + 2 ; i++)
    {
        mat[0][i] = 'a';
    }
    for (int i = 0 ; i < n + 2 ; i++)
    {
        mat[m + 1][i] = 'a';
    }
    for (int i = 0 ; i < m + 2 ; i++)
    {
        mat[i][0] = 'a';
    }
    for (int i = 0 ; i < m + 2 ; i++)
    {
        mat[i][n + 1] = 'a';
    }


    return mat;
}

void del (char ** mat, int m, int n)
{

    for (int i = 0 ; i < m + 2 ; i ++)
    {
        delete [] mat[i];
    }

    delete [] mat;

}

int oneOrZero(char ** mat, int i, int j)
{

    if (mat[i][j] == '*') return 1;
    else return 0;
}

char cell(char ** mat, int i, int j)
{
    if (mat[i][j] == '*') return '*';

    char total = oneOrZero(mat, i - 1, j) + oneOrZero(mat, i + 1, j)
                 + oneOrZero(mat, i, j - 1) + oneOrZero(mat, i, j + 1) + oneOrZero(mat, i - 1, j + 1)
                 + oneOrZero(mat, i - 1, j - 1) + oneOrZero(mat, i + 1, j - 1) + oneOrZero(mat, i + 1, j + 1);

    return total + '0';
}



int main()
{
   //ofstream txtOut;
   //txtOut.open("newFile.txt");
    int f = 0;
    while(true)
    {
        f++;
        int m, n;
        cin >> m >> n;
        if (n == m && n == 0) return 0;
        char ** mat = grid(m, n);
        for (int i = 1 ; i < m + 1 ; i++)
            for (int j = 1 ;  j < n + 1 ; j++)
                cin >> mat[i][j];
        cout << "Field #" << f << ":" << endl;
        //txtOut << "Field #" << f << ":" << endl;
        for (int i = 1 ; i < m + 1 ; i++)
        {
            for (int j = 1 ;  j < n + 1 ; j++){
                cout << cell(mat, i, j);
//                txtOut << cell(mat, i, j);
            }
            cout << endl;
//            txtOut << endl;

        }
        cout << endl;
      //  txtOut << endl;
        del(mat, m, n);
    }
//     txtOut.close();
    return 0;
}
