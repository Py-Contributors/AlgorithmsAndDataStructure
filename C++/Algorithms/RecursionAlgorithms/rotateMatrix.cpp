#include<bits/stdc++.h>
using namespace std;
int l,m,row,col,mat[100][100];

void rotation(int l,int m,int row, int col)
{
    int si=l,sj=m,t,f,i,j;
    t = mat[l][m];
    for(i=l+1;i<=row;i++)
    {
        f = mat[i][m];
        mat[i][m] = t;
        t = f;
    }
    l++;
    for(i=m+1;i<=col;i++)
    {
        f = mat[row][i];
        mat[row][i] = t;
        t = f;
    }
    m++;
    if(l-1 < row)
    {
        for(i=row-1;i>=l-1;i--)
        {
        f = mat[i][col];
        mat[i][col] = t;
        t = f;
        }
    }
    col--;
    if(m-1 < col)
    {
        for(i=col;i>=m;i--)
        {
        f = mat[l-1][i];
        mat[l-1][i] = t;
        t = f;
        }
    }
    row--;
    mat[si][sj] = t;
    return;
}


int main()
{
    int r,c,k;
    ios_base::sync_with_stdio(false);
    std::cin>> r >> c >> k;
    l=0;
    m=0;
    row=r-1;
    col=c-1;

    for(int i=0; i<r; i++)
        for(int j=0; j<r; j++)
            std::cin>>mat[i][j];

    while(l<row && m<col)
    {
        int rot = 2*(row-l)+2*(col-m);
        int f = k%rot;
        for(int i=1;i<=f;i++)
        {
            rotation(l,m,row,col);
        }
        l++;
        m++;
        row--;
        col--;
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<r; j++)
            std::cout<<mat[i][j]<<" ";
        std::cout<<endl;
    }
    return 0;
}
