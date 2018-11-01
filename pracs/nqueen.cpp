#include<iostream>
using namespace std;

bool isSafe(int board[8][8],int row,int col)
{
	for(int i=0;i<col;i++)
	{
		if(board[row][i]==1)return false;
	}
	
	for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
	{
		if(board[i][j]==1)return false;
	}
	
	for(int i=row+1,j=col-1;i<8 &&col>=0; i++,j--)
	{
		if(board[i][j]==1)return false;
	}
	
	return true;
}

bool solve(int board[8][8],int col)
{
	if(col>=8)return true;
	
	for(int i=0;i<8;i++)
	{
		if(isSafe(board,i,col))
		{
			board[i][col]=1;
			
			if(solve(board,col+1))
			return true;
			
			board[i][col]=0;
		}	
	}
	return false;
		
}


int main()
{
	//int n=4;
	int board[8][8]={};
	
	if(solve(board,0))
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				cout<<board[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	else cout<<"No solution";
}
