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

int main()
{
	int p;
	cout<<"Enter the value of p";
	
	cin>>p;
	cout<<p+1+2*sqrt(p)<<" "<<p+1-2*sqrt(p)<<"\n";
	
	int avg = p+1;
//	while(!prime(p))
//	{
//		cout<<"The entered value of p is not prime\n Reenter...";
//		cin>>p;	
//	}
	int valid =0 ;
	int first=0,second=0;
	for(int a=0;a<p;a++)
	{
		for(int b=0;b<p;b++)
		{
			if(!((4*a*a*a + 27*b*b)%p))
			{
				continue;
			}
			valid++;
			
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
			
			cout<<"a: "<<a<<"b: "<<b<<"n: "<<grp.size()<<"\n";
			
			if(grp.size()>avg)
				second++;
			else
				first++;
			
			
		}
	}
	cout<<valid<<"\n";
	cout<<first<<" "<<second;
	
}
