#include<bits/stdc++.h>
using namespace std;
const int boardsize=9;
const int cellsize=3;
int board[boardsize][boardsize];
int ans=0;
int logarr[10010];
int trow[boardsize],tcol[boardsize],tgrid[cellsize][cellsize];

void move(int ch,int row,int col)
{
    board[row][col]=ch;
    trow[row]^=(1<<ch);
    tcol[col]^=(1<<ch);
    tgrid[row/cellsize][col/cellsize]^=(1<<ch);
}

void reversemove(int ch,int row,int col)
{
    board[row][col]=0;
    trow[row]^=(1<<ch);
    tcol[col]^=(1<<ch);
    tgrid[row/cellsize][col/cellsize]^=(1<<ch);
}

int choices(int row,int col)
{
    int taken=(trow[row]|tcol[col]|tgrid[row/cellsize][col/cellsize]);
    int nottaken=((1<<(boardsize+1))-1)^taken;
    if(nottaken&1)nottaken^=1;
    return nottaken;
}

void rec(int row,int col)
{
    if(col==boardsize)
    {
        rec(row+1,0);
    }
    if(row==boardsize)
    {
        ans++;
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
        int cmask=choices(row,col);
        while(cmask)
        {
            int last1=cmask^(cmask&(cmask-1));
            int last1position=logarr[last1];
            move(last1position,row,col);
            rec(row,col+1);
            reversemove(last1position,row,col);
            cmask=cmask&(cmask-1);
        }
    }
    else{
            rec(row,col+1);
        }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int i,j;
    for(i=0;i<=9;i++)
    {
        logarr[1<<i]=i;
    }
    for(i=0;i<boardsize;i++)
    {
        for(j=0;j<boardsize;j++)
        {
            int ch=0;
            move(ch,i,j);
        }
    }
    rec(0,0);
    cout<<ans;
}