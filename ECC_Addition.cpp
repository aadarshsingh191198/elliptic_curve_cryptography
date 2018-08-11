#include <bits/stdc++.h>
using namespace std;

class Point{
	public:
	int x,y;
};

int returnSquare(int a,vector< vector<int> > lookIn,int size)
{
	return lookIn[a][size];
}

bool isSquare(int a,vector< vector<int> > lookIn)
{
	if(lookIn[a].size()>0)
		return true;
		
	else
		return false;
}

bool isprime(int n)
{
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	
	return true;
}

int main()
{
	int a, b, p;
	cout<<"Enter the values of a,b and p";
	
	cin>>a >>b>>p;
	
	while(!isprime(p))
	{
		cout<<"The entered value of p is not prime\n Reenter...";
		cin>>p;	
	}
	
	while(!(4*a*a*a + 27*b*b)%p)
	{
		cout<<"The discriminant is zero\n";
		cout<<"Renter a,b: ";
		cin>>a>>b;
	}

	
	vector < vector<int> > lookUpTable(p);
	
	for(int i=0;i<p;i++)
	{
		int sq= (i*i)%p;
		lookUpTable[sq].push_back(i);
	}

	
	vector <Point> grp;
	for(int i=0;i<p;i++)
	{
		int y2 = (i*i*i + a*i +b)%p;
		if(isSquare(y2,lookUpTable))
		{
			Point temp;
			int size=lookUpTable[y2].size();
			temp.x= i;
			while(size--)
			{
				temp.y= returnSquare(y2,lookUpTable,size);
				grp.push_back(temp);
			}
		}
	}
	
	cout<<"The group has "<<grp.size()<<"elements and an identity element\n";
	
	for(int i=0;i<grp.size();i++)
	{
		cout<<"("<<grp[i].x<<","<<grp[i].y<<")\n";
	}
	
	int choice ;
	
	do
	{
		cout<<"Choose :\n1.Point addition\n2.Point Doubling\n3.Exit";
		switch(choice)
		{
			case 1: 
				cout<<"Choose any two points: ";
				Point P,Q;
				
				cin>>P.x>>P.y;
				cin>>Q.x>.Q.y;
				Point R = point_add(a,b,p,P,Q);
				cout<<"The sum is ("<<R.x<<","<<R.y<<")\n";
				break;
				
			case 2:
				cout<<"Choose a point: ";
				Point P;
				
				cin>>P.x>>P.y;
				Point R = point_double(a,b,P);
				cout<<"The sum is ("<<R.x<<","<<R.y<<")\n";
				break;
				
			case 3:
				exit(0);
				break;
			
			default:
				cout<<"Sorry! Can't find that menu item.\n";
		}
	}while(1);
	
	
	
	
		
}
