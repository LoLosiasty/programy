#include<iostream>
using namespace std;
void Sortowanie(int **tab,int left,int right)
{
    int i=left;
    int j=right;
    int x=(left+right)/2;
    do
    {
        while(tab[i][1]-tab[i][0]>tab[x][1]-tab[x][0])i++;
        while(tab[j][1]-tab[j][0]<tab[x][1]-tab[x][0])j--;
        if(i<=j)
        {
            swap(tab[i][0],tab[j][0]);
            swap(tab[i][1],tab[j][1]);
            swap(tab[i][2],tab[j][2]);
            i++;
            j--;
        }
    }while(i<=j);
    if(left<j)Sortowanie(tab,left,j);
    if(right>i)Sortowanie(tab,i,right);
}
int main()
{
	int ilosc_filmow,dzien,m=1;
	cin>>ilosc_filmow;
	if(ilosc_filmow<1 || ilosc_filmow>500000) return 0;
	int	**opis_filmu = new int *[ilosc_filmow];
	for(int i=0;i<ilosc_filmow;i++)
	{
		opis_filmu[i]= new int[3];
		cin>>opis_filmu[i][0];
		cin>>opis_filmu[i][1];
		opis_filmu[i][2]=i+1;
	}
	Sortowanie(opis_filmu,0,ilosc_filmow-1);
	int **wynik = new int *[ilosc_filmow];
	wynik[0] = new int[2]; 
	dzien=opis_filmu[0][1]-opis_filmu[0][0];
	wynik[0][0]=opis_filmu[0][2];
	wynik[0][1]=dzien+1;
	for(int i=1;i<ilosc_filmow;i++)
	{
		if(dzien<1) break;
		if(dzien>opis_filmu[i][1]) dzien=opis_filmu[i][1];
		if(dzien>=opis_filmu[i][0])
		{
			dzien-=opis_filmu[i][0];
			m++;
			wynik[i] = new int [2];
			wynik[i][0]=opis_filmu[i][2];
			wynik[i][1]=dzien+1;
		}
		else break;
	}
	cout<<m<<endl;
	for(int i=0;i<m;i++)cout<<wynik[i][0]<<" "<<wynik[i][1]<<endl;
	delete [] opis_filmu;
	delete [] wynik;
	return 0;
}
