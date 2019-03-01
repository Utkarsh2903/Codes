#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,t;
	cin>>s>>t;
	long long int l1=s.length() , l2=t.length() , po[l2] , h1[l1] , h2[l2] , p=31 , count=0;
	po[0]=1;
	h1[0]=s[0]-'a'+1;
	h2[0]=t[0]-'a'+1;
	for(long long int i=1;i<l2;i++)
	{
		po[i]=p*po[i-1];
		h2[i]=h2[i-1]+po[i]*(t[i]-'a'+1);
	}
	for(long long int i=1;i<l1;i++)
	{
		h1[i]=h1[i-1]+po[i]*(s[i]-'a'+1);
	}
	for(long long int i=0;i+l1-1<l2;i++)
	{
		long long int k1=h2[i+l1-1];
		if(i)
		k1=k1-h2[i-1];
		long long int k2=po[i]*h1[l1-1];
		if(k1==k2)
		count++;
	}
	cout<<count<<endl;
	
}
