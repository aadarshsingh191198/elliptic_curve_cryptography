#include <bits/stdc++.h>
using namespace std;

class Point{
	public:
	int x,y;
};

vector <Point> S1,S2,S3;

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

int points_in_the_group(int a,int b,int p)
{
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
	
//	cout<<"The group has "<<grp.size()<<"elements and an identity element\n";
	
	for(int i=0;i<grp.size();i++)
	{
		cout<<"("<<grp[i].x<<","<<grp[i].y<<")\n";
	}
	for(int i=0;i<floor(grp.size()/3.0);i++)
		S1.push_back(grp[i]);
		
	for(int i=floor(grp.size()/3.0)+1;i<floor(2*grp.size()/3.0);i++)
		S2.push_back(grp[i]);
		
	for(int i=floor(2*grp.size()/3.0);i<grp.size();i++)
		S3.push_back(grp[i]);
	
	return grp.size();
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
	
	
	cout<<"The available points are :";
	int n = points_in_the_group(a,b,p);
	cout<<"Choose points P and Q: \n";

	Point P,Q;
	cout<<"P: ";	
	cin>>P.x>>P.y;
	cout<<"Q: ";	
	cin>>Q.x>>Q.y;
	
	cout<<"The groups are divided with sizes: "<<S1.size()<<", "<<S2.size()<<" and "<<S3.size()<<"respectively\n";
	
//	cout<<
	
}
