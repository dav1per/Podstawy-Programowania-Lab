/*
Autor: Igor Wlodarczyk
Grupa: PN/P 13:15
Temat: Laboratorium 3 (dodatkowe zadanie 4)
Data: 16.11.2021
*/

#include <stdio.h>
#include <conio.h>

int main()
{
	printf("Autor: Igor Wlodarczyk\n");
	int tab[26];
	int i, i_znaki=0;
	for (i=0; i<26; i++)
	{
		tab[i]=0;
	}
	bool wczytywanie=true;
	char znak;
	printf("Wpisuj litery: ");
	while(wczytywanie==true)
	{
	
		znak=getch();
	
		if(znak==27)
		{
			wczytywanie=false;
		} else 	if(znak>=97 && znak<=122)
		{
			tab[znak-97]++;
			i_znaki++;	
			printf("%c", znak);
		} else if(znak>=65 && znak<=90)
		{
			tab[znak-65]++;
			i_znaki++;
			printf("%c", znak);
		}
	}
	printf("\n Wpisano ogolem %d znakow w tym: \n", i_znaki);
	char litera = 'A';
	int j;
	for (i=0; i<26; i++)
	{
		printf("litera %c %5d ", litera+i, tab[i]);
		for(j=0; j<tab[i]; j++) printf("#");
		printf("\n");
	}

}