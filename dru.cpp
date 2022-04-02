#include<iostream>
using namespace std;

int main()
{
	long long int koniec,n,m,ilosc=0,pion,poziom,numerlitery;
	cin>>n>>m;
	if(n>1000 || m>1000)
	{
		return 0;
	}
	char memory[n][m],tablica[n][m];
	long long int wyniki[100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>tablica[i][j];
			memory[i][j]=1;
		}
	}
	for(long long int dlugoscszablonu=1;dlugoscszablonu<=n || dlugoscszablonu<=m;dlugoscszablonu++)
	{	koniec=0;
		if((m*n)%dlugoscszablonu==0)
		{
			for(long long int i=0;i<n;i++)
			{
				for(long long int j=0;j<m;j++)
				{
					memory[i][j]=1;
				}
			}
			char szablon[dlugoscszablonu][1];
			pion=0;
			poziom=0;
			for(numerlitery=0;numerlitery<dlugoscszablonu;numerlitery++)
			{
				szablon[numerlitery][0]=tablica[0][numerlitery];
			}
			for(long long int numerszablonu=1;numerszablonu<=m*n/dlugoscszablonu;)
			{
				if(numerszablonu==n*m/dlugoscszablonu)
				{
					numerszablonu=0;
					wyniki[ilosc]=dlugoscszablonu;
					ilosc++;
					goto koniec;
				}
				here:
				if(poziom==m)
				{
					pion++;
					poziom=0;
				}
				if(memory[pion][poziom]==0)
				{
					poziom++;
					goto here;
				}
				if(dlugoscszablonu>m-poziom)
				{
					goto pion;
				}
				
				for(numerlitery=0;numerlitery<dlugoscszablonu;poziom++,numerlitery++)
				{
					if(memory[pion][poziom]==0)
					{
						poziom--;
						numerlitery--;
						for(;numerlitery>0;poziom--,numerlitery--)
						{
							memory[pion][poziom]=1;
						}
						goto pion;
					}
					else if(szablon[numerlitery][0]!=tablica[pion][poziom])
					{
						for(;numerlitery>0;poziom--,numerlitery--)
						{
							memory[pion][poziom]=1;
						}
						goto pion;
					}
					memory[pion][poziom]=0;
				}
				numerszablonu++;
				goto poziom;
				pion:
				if(dlugoscszablonu>n-pion)
				{
					numerszablonu=0;
					goto szablon2;
				}
				for(long long int i=pion,numerliteryi=0;numerliteryi<dlugoscszablonu;i++,numerliteryi++)
				{
					if(szablon[numerliteryi][0]!=tablica[i][poziom])
					{
						numerszablonu=0;
						goto szablon2;
					}
					memory[i][poziom]=0;
				}
				numerszablonu++;
				poziom++;
				goto poziom;
				szablon2:
				if(koniec==1)
				{
					goto koniec;
				}
				koniec++;
				for(long int i=0;i<n;i++)
				{
					for(long int j=0;j<m;j++)
					{
						memory[i][j]=1;
					}
				}
				if(n<dlugoscszablonu)
				{
					goto koniec;
				}
				for(pion=0,poziom=0,numerlitery=0;numerlitery<dlugoscszablonu;numerlitery++)
				{
					szablon[numerlitery][0]=tablica[numerlitery][poziom];
				}
				poziom:;
			}
		}
		koniec:;
	}
	cout<<ilosc<<endl;
	for(long long int i=0;i<ilosc;i++)
	{
		cout<<wyniki[i]<<" ";
	}
	return 0;
}
