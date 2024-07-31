#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int main()
{
	srand(time(0));
	int row,column,i,j,count=0;
	cout<<"Enter rows: ";
	cin>>row;
	cout<<"Enter column: ";
	cin>>column;
	int array[row][column], temp[row][column];
	for(i=0;i<row;i++)// filling the arrow
	{	
		for(j=0;j<column;j++)
		{	
			array[i][j]=rand()%2;
			temp[i][j]=0;
		}
	}
	cout<<"The Initial population is: "<<endl;
	for(i=0;i<row;i++)// displaying the arrow
	{	
		for(j=0;j<column;j++)
		{	
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}	
	for(i=0;i<row;i++)
	{	
		for(j=0;j<column;j++)
		{	count=0;
			if(i==0 && j==0)// for the only top left of the matrix
			{	
				if(array[i+1][j]==1)// bottom of the cell
				{
					count++;
					
				}
				if(array[i][j+1]==1)// right to the cell
				{
					count ++;
				}
				if(array[i+1][j+1]==1)// right bottom diagonal to the cell
				{
					count++;
				}
			}
			else if(i==0 && j<column-1 && j>0)// cell in the first row other than the left most and the right most
				{
				if(array[i+1][j]==1)// bottom of the cell
				{
					count++;
					
				}
				if(array[i][j-1]==1)//left to the cell
				{
					count++;
				}
				
				if(array[i][j+1]==1)// right to the cell
				{
					count ++;
				}
				if(array[i+1][j+1]==1)//  right bottom diagonal cell to the cell
				{
					count++;
				}
				if(array[i-1][j-1]==1)//  left bottom diagonal cell to the cell
				{
					count++;
				}
				} 
			else if (i==0 && j==column-1)// right most element of the cell
			{
				if(array[i+1][j]==1)// bottom of the cell
				{
					count++;
					
				}
				if(array[i][j-1]==1)//left to the cell
				{
					count++;
				}
				if(array[i+1][j-1]==1)//  left bottom diagonal to the cell
				{
					count++;
				}
			}
			else if (i==row-1 && j==0)// for the last row left most cell
			{
				if(array[i-1][j]==1)// top of the cell
				{
					count++;
					
				}
				if(array[i][j+1]==1)//right to the cell
				{
					count++;
				}
				if(array[i-1][j+1]==1)//   top right  diagonal cell to the cell
				{
					count++;
				}
			}
			else if(i== row-1 && j==column-1)// for the right most element of the last row
			{
				if(array[i-1][j]==1)// top of the cell
				{
					count++;
					
				}
				if(array[i][j-1]==1)//left  to the cell
				{
					count++;
				}
				if(array[i-1][j-1]==1)//   top left  diagonal cell to the cell
				{
					count++;
				}
			}
			else if(i==row-1 && j>0 && j<column-1)// for the element in the between the left and right most element in the last of the matric
			{
				if(array[i-1][j]==1)//top
				{
					count++;
				}
				if(array[i][j+1]==1)//right
				{
					count++;
				}
				if(array[i][j-1]==1)//left
				{
					count++;
				}
				if(array[i-1][j-1]==1)//top left diagonal cell to the cell
				{
					count++;
				}
				if(array[i+1][j-1]==1)// top right diagonal to the cell
				{
					count++;
				}
			}	
			else if(i>0 && i<row -1 && j>0 && j<column-1)
			{
				if(array[i-1][j]==1)//top
				{
					count++;
				}
				if(array[i+1][j]==1)//bottom
				{
					count++;
				} 
				if(array[i][j+1]==1)//right
				{
					count++;
				}
				if(array[i][j-1]==1)//left
				{
					count++;
				}
				if(array[i-1][j-1]==1)//top left diagonal cell to the cell
				{
					count++;
				}
				if(array[i-1][j+1]==1)// bottom left diagonal cell to the cell
				{
					count++;
				}
				if(array[i+1][j+1]==1)// bottm right diagonal cell to the cell
				{
					count++;
				}
				if(array[i+1][j-1]==1)// top right diagonal cell to the cell
				{
					count++;
				}
			}
			else if( j==0 && i>0 && i<row-1)// for the element in the first column other than the first and the last cell
			{
				if(array[i-1][j]==1)//top
				{
					count++;
				}
				if(array[i+1][j]==1)//bottom
				{
					count++;
				} 
				if(array[i][j+1]==1)//right
				{
					count++;
				}
				if(array[i+1][j+1]==1)// bottm right diagonal cell to the cell
				{
					count++;
				}
				if(array[i+1][j-1]==1)// top right diagonal cell to the cell
				{
					count++;
				}
			}
			else if(j==column-1 && i>0 && i<row-1)// for the elements in the last cell other than the first and last
			{
				if(array[i-1][j]==1)//top
				{
					count++;
				}
				if(array[i+1][j]==1)//bottom
				{
					count++;
				}
				if(array[i][j-1]==1)//left
				{
					count++;
				}
				if(array[i-1][j-1]==1)//top left diagonal cell to the cell
				{
					count++;
				}
				if(array[i-1][j+1]==1)// bottom left diagonal cell to the cell
				{
					count++;
				} 
			}
			if(count<2)
			{
				temp[i][j]=0;
			}
			else if ((count ==3 || count==2) && (array[i][j]==1))
			{
				temp[i][j]=1;
			}
			else if(count>3)
			{
				temp[i][j]=0;
			}
			else if(array[i][j]==0 && count==0)
			{
				temp[i][j]=1;
			}
		}
	}
	cout<<"After a generation: "<<endl;
	for(i=0;i<row;i++)
	{	
		for(j=0;j<column;j++)
		{	

			cout<<temp[i][j]<<" ";
				

		}
		cout<<endl;
	}
}
