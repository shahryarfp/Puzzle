#include <iostream>
#include <fstream>
using namespace std;

char shapes[12][5][5];
char board[6][10];
int shapeRotationCount[12];
int usedShapes[12]={0};
int numberOfAnswers=0;
//void LoadShapes
void LoadShapes()
{
	int i,j,k;
	ifstream Shapes;
Shapes.open("Shapes.txt");
for(k=0;k<12;k++)
{
Shapes>>shapeRotationCount[k];
for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
	{
Shapes>>shapes[k][i][j];
if (shapes[k][i][j]=='1')
shapes[k][i][j]='a'+k;
}
}
}
Shapes.close();
}
//void PrintShape
void PrintShape(int shapeNo)
{
int i,j;
for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
	{
cout<<shapes[shapeNo][i][j]<<" ";
}
cout<<endl;
}
}
//void RotateShape
void RotateShape(int shapeNo)
{
	int i,j;
	char Helper[1][5][5];
for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
	{
Helper[0][i][j]=shapes[shapeNo][i][j];
}
}
int c=5;
for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
	{
shapes[shapeNo][j][4-i]=Helper[0][i][j];
}
}
for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
	{
		if(shapes[shapeNo][i][j]!='0')
		{
		if (c>j)
		c=j;
	}
	}
}
for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
	{
		Helper[0][i][j-c]=shapes[shapeNo][i][j];
	}
	}
for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
	{
		shapes[shapeNo][i][j]=Helper[0][i][j];
	}
	}
}
//void PrintSolution
void PrintSolution()
{
	int i,j;
	char AsciiCode[6][20];
	for(i=0;i<5;i++)
	{
	for(j=0;j<19;j++)
	{
	if(board[i][j]==board[i+1][j]&&board[i+1][j]==board[i][j+1]&&board[i][j+1]==board[i+1][j+1])
	{
	AsciiCode[i][2*j]=32;
	AsciiCode[i][2*j+1]=32;
	}
	if(board[i][j]==board[i+1][j]&&board[i+1][j]==board[i][j+1]&&board[i][j]!=board[i+1][j+1])
	{
	AsciiCode[i][2*j]=218;
	AsciiCode[i][2*j+1]=196;
	}
	if(board[i][j]==board[i+1][j]&&board[i+1][j]==board[i+1][j+1]&&board[i][j]!=board[i][j+1])
	{
	AsciiCode[i][2*j]=192;
	AsciiCode[i][2*j+1]=196;
	}
	if(board[i+1][j+1]==board[i+1][j]&&board[i+1][j]==board[i][j+1]&&board[i+1][j+1]!=board[i][j])
	{
	AsciiCode[i][2*j]=217;
	AsciiCode[i][2*j+1]=32;
	}
	if(board[i][j]==board[i+1][j+1]&&board[i+1][j+1]==board[i][j+1]&&board[i][j]!=board[i+1][j])
	{
	AsciiCode[i][2*j]=191;
	AsciiCode[i][2*j+1]=32;
	}
	if(board[i][j]==board[i+1][j]&&board[i][j+1]==board[i+1][j+1]&&board[i][j]!=board[i][j+1])
	{
	AsciiCode[i][2*j]=179;
	AsciiCode[i][2*j+1]=32;
	}
	if(board[i][j]==board[i][j+1]&&board[i+1][j]==board[i+1][j+1]&&board[i][j]!=board[i+1][j])
	{
	AsciiCode[i][2*j]=196;
	AsciiCode[i][2*j+1]=196;
	}
	if(board[i][j]==board[i+1][j]&&board[i][j]!=board[i][j+1]&&board[i][j]!=board[i+1][j+1]&&board[i][j+1]!=board[i+1][j+1])
	{
	AsciiCode[i][2*j]=195;
	AsciiCode[i][2*j+1]=196;
	}
	if(board[i][j]==board[i][j+1]&&board[i][j]!=board[i+1][j]&&board[i][j]!=board[i+1][j+1]&&board[i+1][j]!=board[i+1][j+1])
	{
	AsciiCode[i][2*j]=194;
	AsciiCode[i][2*j+1]=196;
	}
	if(board[i+1][j]==board[i+1][j+1]&&board[i][j]!=board[i+1][j]&&board[i][j+1]!=board[i+1][j]&&board[i][j]!=board[i][j+1])
	{
	AsciiCode[i][2*j]=193;
	AsciiCode[i][2*j+1]=196;
	}
	if(board[i][j+1]==board[i+1][j+1]&&board[i][j]!=board[i+1][j+1]&&board[i+1][j]!=board[i+1][j+1]&&board[i][j]!=board[i+1][j])
	{
	AsciiCode[i][2*j]=180;
	AsciiCode[i][2*j+1]=32;
	}
	if(board[i][j]!=board[i][j+1]&&board[i][j]!=board[i+1][j]&&board[i][j+1]!=board[i+1][j+1]&&board[i+1][j]!=board[i+1][j+1])
	{
	AsciiCode[i][2*j]=197;
	AsciiCode[i][2*j+1]=196;
	}
	}
	}
	char Border=196;
	char border=218;
	cout<<border<<Border;
	for(j=0;j<9;j++)
	{
	if(board[0][j]==board[0][j+1])
	border=196;
	else
	border=194;
	cout<<border<<Border;
	}
	border=191;
	cout<<border;
	cout<<endl;
	for(i=0;i<5;i++)
	{
	if(board[i][0]==board[i+1][0])
	{
	border=179;
	Border=32;
	}
	else
	{
	border=195;
	Border=196;
	}
	cout<<border<<Border;
	for(j=0;j<18;j++)
	{
	cout<<AsciiCode[i][j];
	}
	if(board[i][9]==board[i+1][9])
	border=179;
	else
	border=180;
	cout<<border<<endl;
	}
	border=192;
	Border=196;
	cout<<border<<Border;
	for(j=0;j<9;j++)
	{
	if(board[5][j]==board[5][j+1])
	border=196;
	else
	border=193;
	cout<<border<<Border;
	}
	border=217;
	cout<<border<<endl;
}
//void FragmentSize and its helper
void FragmentSizeHelper(int row,int col)
{
	int i,j;
    if (row<0||col<0||row>5||col>9||board[row][col]!='0')
    return;
    board[row][col]='X';
    FragmentSizeHelper(row+1,col);
    FragmentSizeHelper(row,col+1);
    FragmentSizeHelper(row-1,col);
    FragmentSizeHelper(row,col-1);
}
void FragmentSize(int row ,int col,int &fz)
{
	int i,j;
	FragmentSizeHelper(row,col);
	fz=0;
    for(i=0;i<6;i++)
    {
      for(j=0;j<10;j++)
      {
        if (board[i][j]=='X')
        fz++;
    }
    }
    for(i=0;i<6;i++)
	{
		for(j=0;j<10;j++)
		{
			if(board[i][j]=='X')
			board[i][j]='0';
		}
	}
}
//int BoardHasFragment
int BoardHasFragment()
{
	int i,j,k;
	for(i=0;i<6;i++)
    {
    	for(j=0;j<10;j++)
    	{
    		FragmentSize(i,j,k);
    		if(k%5!=0)
    		return 0;
		}
	}
	return 1;
}
//int CanPush
int CanPush(int shapeNo,int row,int col)
{
	int i,j,c=0;
	for(i=0;i<5;i++)
	{
	   	for(j=0;j<5;j++)
	   	{
	   		if(shapes[shapeNo][i][j]!='0')
	   		{
	   			if(row+i>5||col+j>9)
	   			return 0;
	   		    if(board[row+i][col+j]=='0')
	   			c++;
			}
		}
	}
	if(c==5)
	return 1;
	else
	return 0;
}
//void PushShape
void PushShape(int shapeNo,int row,int col)
{
	int i,j;
	for(i=0;i<5;i++)
	    {
	    	for(j=0;j<5;j++)
	    	{
	    		if(shapes[shapeNo][i][j]!='0')
	    		board[row+i][col+j]=shapes[shapeNo][i][j];
			}
		}
}
//void PopShape
void PopShape(int shapeNo,int row,int col)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
	   		if(shapes[shapeNo][i][j]!='0')
			board[row+i][col+j]='0';
		}
	}
}
//void FindSolution
void FindSolution(int shapeNumber,int row,int col)
{
	int i,j,k,t;
//	PrintSolution();	//baraye didane amalkard
    if(shapeNumber==12)
	{
		PrintSolution();
        numberOfAnswers++;
        ofstream answers;
        answers.open("answers.txt",ios_base::app);
        for(i=0;i<6;i++)
		{
  			for(j=0;j<10;j++)
  			{
  				answers<<board[i][j]<<" ";	
			}
			answers<<endl;
		}
		answers<<endl;
        return;
    }
    if(BoardHasFragment()==0)
	{
        return;
    }
    for(i=0;i<6;i++)
	{
        for(j=0;j<10;j++)
		{
            for(k=0;k<shapeRotationCount[shapeNumber];k++)
			{
				for(t=0;t<k;t++)
				{
					RotateShape(shapeNumber);
				}
                if(CanPush(shapeNumber,i,j)==1)
				{
                    PushShape(shapeNumber,i,j);
                    FindSolution(shapeNumber+1,row,col);
                    PopShape(shapeNumber,i,j);
                }
            }
        }
    }
}

int main()
{
int i,j;
for(i=0;i<6;i++)
{
  	for(j=0;j<10;j++)
  	{
  	board[i][j]='0';	
	}
}  

LoadShapes();
FindSolution(0,0,0);
cout<<numberOfAnswers;
  return 0;
}
