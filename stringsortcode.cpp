#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	char c[n+1];
	c[0]=' ';
	n++;
	map <char, int> p;
	map <char, int>:: iterator it = p.begin();
	char ch;
	for(int i=1;i<n;i++)
	{
		cin>>ch;
		p.insert(pair <char, int> (ch, i));
		c[i]=ch;
	}
	int s[m],t;
	string temp;
	for(int i=0;i<m;i++)
	{
		cin>>temp;
		int sum=0;
		for(int k=0;k<temp.length();k++)
			sum=sum*n+p.find(char(temp[k]))->second;
		s[i]=sum;
		//cout<<s[i]<<"\n";
	}
	sort(s,s+m);
	string z;
	for(int i=0;i<m;i++)
	{
		temp="";
		cout<<"\n"<<s[i]<<"  --->  ";
		while(s[i]>0)
		{
			it=p.begin();
			t=s[i]%n;
			s[i]=s[i]/n;
			z=string(1,c[t]);
			temp.insert(0,z);
		}
		cout<<"  "<<temp;
	}
}
