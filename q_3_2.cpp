// toll booth
#include <bits/stdc++.h>
using namespace std;

void take_inputs(string type[],int fees[],string path[],int N,int T)
{
	
	for(int i=0;i<T;i++)
	{
		cin>>type[i];
		cin>>fees[i];
	}
	
	for(int i=0;i<N;i++)
	{
		cin>>path[i];
	}

}
int TollFee(string toll,string type[],int fees[],int T)
{
	for(int i=0;i<T;i++)
	{
		if(type[i]==toll)
		{
			return(fees[i]);
		}
	}
	return 0;
}

long int Journey(string type[],int fees[],string path[],int N,int T,int k,stack<string> &st) // why & and how???
{
	long int cost=0;
	for(int i=0;i<N;i++)
	{
		
		string prev[k];
		if(st.empty())
		{
			st.push(path[i]);
			cost+=TollFee(path[i],type,fees,T);
			continue;

		}
		if(!st.empty()&& st.top()==path[i])
		{
			st.pop();
			continue;
		}
		for(int j=0;j<k;j++)
		{
			
			if(!st.empty()&& st.top()!=path[i])
			{
				prev[j]=st.top();
				st.pop();
			}
			if(st.empty())
			{
				for(int s=0;s<j+1;s++)
				{
					if(j-s>=0)
					{
						st.push(prev[j-s]);
					}
					
				}
				st.push(path[i]);
				cost+=TollFee(path[i],type,fees,T);
				break;
			}
			if(st.top()==path[i])
			{
				st.pop();
				for(int s=0;s<j+1;s++)
				{
					if(j-s>=0)
					{
						st.push(prev[j-s]);
					}
					
				}
				break;

			}
			
		}
		
	}
	return cost;
}

int main()
{
	int N,T,k;
	cin >>N>>T>>k;
	 stack <string> st;
	 cout<<&st<<endl;
	string type[T];
	int fees[T];
	string path[N];
	take_inputs(type,fees,path,N,T);
	long int cost=Journey(type,fees,path,N,T,k,st);
	int number=0;
	while(!st.empty())
	{
		number++;
		st.pop();
	}
	cout<<cost<<" "<<number;
}
/* 
 5 3 2
 A 5
 B 10
 C 15
 A B A C C 
 */
