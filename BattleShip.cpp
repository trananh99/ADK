//bai toan tau chien


#include <iostream>
#include <fstream>
#define MAX 100


using namespace std;


void Read_Graph(int A[][MAX], int &n)
{
	fstream infile;
	infile.open("input.txt", ios::in );
	infile>>n;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			infile>>A[i][j];
		}
	}
	
}

//in ra ban do sau mo lan nhap
void Graph( int A[][MAX], int n)
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (A[i][j] == -1 ) cout<<A[i][j]<<" ";
			else cout<<"*"<<" ";
		}
		cout<<endl;
	}
}


//ktra da ban ha het tau hay chua
bool Big_Boom(int A[][MAX], int n)
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (A[i][j] > 0) return false;
		}
	}
	return true;
}

//dat boom de danh ha tau
bool Boom( int A[][MAX], int x, int y)
{
	if (A[x][y] > 0) 
	{
		cout<<"\n ban da trung muc tieu "<<A[x][y];
		A[x][y] = -1;
		return true;
	}
	return false;
}

int main()
{
	int x, y;
	int A[11][MAX];
	int n;
	Read_Graph(A, n);
	bool bb;
	do{
		cout<<" nhap toa do x: "; cin>>x;
		cout<<"nhap toa do y: "; cin>>y;
		bool b = Boom( A, x, y);
		if (!b) cout<<"khong trung muc tieu";
		cout<<"\n\n";
		Graph(A, n);
		bb = Big_Boom(A, n);
		cout<<"\n\n====================================\n";
	}while (!bb);
	cout<<" ban da ha duoc muc tieu";
	return 0;
}
