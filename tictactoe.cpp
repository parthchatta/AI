#include<iostream>
using namespace std;
int board[3][3];
void showboard()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==0)
				cout<<'O';
			else
				cout<<'X';
			if(j!=2)
				cout<<"  |  ";	
		}
		cout<<"\n";
	}
}
bool emptypos()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==-1)
				return true;
		}
	}
	return false;
}

bool canplace(int p)
{
	switch(p)
	{
		case 7:
			if(board[0][0]!=-1)
				return false;
			break;
		case 8:
			if(board[0][1]!=-1)
				return false;
			break;
		case 9:
			if(board[0][2]!=-1)
				return false;
			break;
		case 4:
			if(board[1][0]!=-1)
				return false;
			break;
		case 5:
			if(board[1][1]!=-1)
				return false;
			break;
		case 6:
			if(board[1][2]!=-1)
				return false;
			break;
		case 1:
			if(board[2][0]!=-1)
				return false;
			break;
		case 2:
			if(board[2][1]!=-1)
				return false;
			break;
		case 3:
			if(board[2][2]!=-1)
				return false;
			break;
	}

}

 
void makemove(int &choice)
{
	if(choice == 0)
	{
		
	}
	else
	{
		cout<<"enter position to place: "
		int p;
		cin>>p;
		while(!canplace(p))
		{
			cout<<"enter correct position.";
			cin>>p;
		}
			switch(p)
			{
				case 7:
					board[0][0]=1;
					break;
				case 8:
					board[0][1]=1;
					break;
				case 9:
					board[0][2]=1;
					break;
				case 4:
					board[1][0]=1;
					break;
				case 5:
					board[1][1]=1;
					break;
				case 6:
					board[1][2]=1;
					break;
				case 1:
					board[2][0]=1;
					break;
				case 2:
					board[2][1]=1;
					break;
				case 3:
					board[2][2]=1;
					break;
			}
			choice =0;
			
	}
}
int main()
{	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			board[i][j]=-1;
		}
	}
	cout<<"whose first move? ai 0 | human 1\n";
	int choice;
	cin>>choice;
	while(emptypos())
	{
		makemove(choice);
		
	}
	
	
	showboard();
	return 0;	
}
