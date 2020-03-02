#include<iostream>
using namespace std;


void print(int a[][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

bool equal(int a[][3],int b[][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]!=b[i][j])
				return false;
		}
	}
	return true;
}

//void assign(int start[][3] int end[][3])

bool find(int init[][3],int start[][3],int end[][3],int bx,int by)
{
	cout<<"in\n"; 
	cout<<bx<<" "<<by<<endl;
	return true;
	if(equal(start,end))
	{
		print(end);
		return true;
	}
	/*if(equal(start,init))
		return false;
		*/
	
	if(bx+1<=2)
	{
	
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				init[i][j]=start[i][j];
			}
		}
		start[bx][by]=start[bx+1][by];
		start[bx+1][by]=0;
		
		if(find(init,start,end,bx+1,by))
		{
			print(init);
			return true;
		}
		else
		{
			start[bx+1][by]=start[bx][by];
			start[bx][by]=0;
		}
	}
	
	if(by-1>=0)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				init[i][j]=start[i][j];
			}
		}
		start[bx][by]=start[bx][by-1];
		start[bx][by-1]=0;
		
		if(find(init,start,end,bx,by-1))
		{
			print(init);
			return true;
		}
		else
		{
			start[bx][by-1]=start[bx][by];
			start[bx][by]=0;
		}
	}

	if(bx-1>=0)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				init[i][j]=start[i][j];
			}
		}
	
		
		start[bx][by]=start[bx-1][by];
		start[bx-1][by]=0;
		
		if(find(init,start,end,bx-1,by))
		{
			print(init);
			return true;
		}
		else
		{
			start[bx-1][by]=start[bx][by];
			start[bx][by]=0;
		}
	}
	if(by+1<=2)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				init[i][j]=start[i][j];
			}
		}
		
		start[bx][by]=start[bx][by+1];
		start[bx][by+1]=0;
		
		if(find(init,start,end,bx,by+1))
		{
			print(init);
			return true;
		}
		else
		{
			start[bx][by+1]=start[bx][by];
			start[bx][by]=0;
		}
	}
	
	return false;

}
	

int main()
{
	int start[3][3] = 
    { 
        {1, 2, 3}, 
        {5, 0, 6}, 
        {7, 8, 4}  
    }; 

    int end[3][3] = 
    { 
        {1, 2, 3}, 
        {5, 6, 0}, 
        {7, 8, 4} 
    }; 
    int init[][3]={{0,0,0},{0,0,0},{0,0,0}};
    int bx=1,by=1;
	if(find(init,start,end,1,1))
		cout<<"possible\n";
	else
		cout<<"not possible\n";
	return 0;
}
