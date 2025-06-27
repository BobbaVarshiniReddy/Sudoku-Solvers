#include<bits/stdc++.h>
using namespace std;
const int boardsize=9;
const int cellsize=3;
int board[boardsize][boardsize];
bool check(int val,int row,int col)
{
    for(int c=0;c<boardsize;c++)
    {
        if(c!=col && board[row][c]==val)
        {
            return false;
        }
    }
    for(int r=0;r<boardsize;r++)
    {
        if(r!=row && board[r][col]==val)
        {
            return false;
        }
    }
    int corx=(row/cellsize)*cellsize,cory=(col/cellsize)*cellsize;
    for(int dx=0;dx<cellsize;dx++)
    {
        for(int dy=0;dy<cellsize;dy++)
        {
            if(corx+dx==row && cory+dy==col)continue;
            if(board[corx+dx][cory+dy]==val)
            {
                return false;
            }
        }
    }
    return true;
}
void rec(int row,int col)
{
    if(col==boardsize)
    {
        rec(row+1,0);
    }
    if(row==boardsize)
    {
        for(int i=0;i<boardsize;i++)
        {
            for(int j=0;j<boardsize;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    if(board[row][col]==0)
    {
        for(int temp=1;temp<=boardsize;temp++){
            if(check(temp,row,col))
            {
                board[row][col]=temp;
                rec(row,col+1);
                board[row][col]=0;
            }
        }
    }
    else{
        if(check(board[row][col],row,col)){
            rec(row,col+1);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int i,j;
    for(i=0;i<boardsize;i++)
    {
        for(j=0;j<boardsize;j++)
        {
            cin>>board[i][j];
        }
    }
    rec(0,0);
}