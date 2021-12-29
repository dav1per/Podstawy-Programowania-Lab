/*
Autor: Igor Wlodarczyk
Grupa: PN/P 13:15
Temat: Laboratorium 5 zadanie 1
Data: 29.12.2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

// Inicjalizacja dynamicznej tablicy dwuwymiarowej
void InitTab(char **&WSK);
// Dodawanie nowego imienia do tablicy dynamiczne
void AddName(char *buf, char **&WSK);
// Usuwanie imienia znajduj¹cego siê w tablicy na pozycji nr
void RemoveName1(int nr, char **&WSK);
//Usuwanie z tablicy imienia, wprowadzonego z klawiatury
void RemoveName2(char *buf, char **&WSK);
// Drukowanie na ekranie wszystkich imion
void PrintAllNames(char **WSK);
// Drukowanie na ekranie imion rozpoczynajacych sie wskazana litera
void PrintNames(char first_letter, char **WSK);
// Sortowanie imion zawartych w tablicy wedlug alfabetu
void SortAlphabet(char **WSK);
// Sortowanie imion zawartych w tablicy wed³ug dlugosci
void SortLength(char **WSK); 


int main()
{
	char **WSK; // wskaznik na dwuwymiarowa tablice dynamiczna
	char buf[81]; // bufor na dane wczytywane z klawiatury
	InitTab(WSK);

	bool menu = true;
	char n;
	while(menu)
	{
		printf("Autor: Igor Wlodarczyk\n");
		printf("| Menu\n");
		printf("| 1. Dodaj imie\n");
		printf("| 2. Usun imie po numerze pozycji\n");
		printf("| 3. Usun imie wprowadzone z klawiatury\n");
		printf("| 4. Drukowanie wszystkich imion\n");
		printf("| 5. Drukowanie imion rozpoczynajacych sie wskazana litera\n");
		printf("| 6. Sortowanie alfabetyczne\n");
		printf("| 7. Sortowanie wedlug dlugosci\n");
		printf("| 8. Koniec\n");
		n = getch();
		switch(n)
		{
			case '1':
				AddName(buf, WSK);
				break;
			case '2':
				unsigned int nr;
				printf("Podaj indeks wiersza, z ktorego ma byc usuniete imie\n");
				scanf("%d", &nr);
				fflush(stdin);
				RemoveName1(nr, WSK);
				break;
			case '3':
				RemoveName2(buf, WSK);
				break;
			case '4':
				PrintAllNames(WSK);
				break;
			case '5':
				printf("Podaj litere\n");
				char first_letter;
				scanf("%c", &first_letter);
				fflush(stdin);
				PrintNames(first_letter, WSK);
				break;
			case '6':
				SortAlphabet(WSK);
				printf("Imiona zostaly posortowane alfabetycznie\n");
				break;
			case '7':
				SortLength(WSK);
				printf("Imiona zostaly posortowane wedlug dlugosci\n");
				break;
			case '8':
				menu = false;
				break;
		}
		if(n>='1' && n<='8')
		{
			char znak = 0;
			printf("Wcisnij 'p', aby przejsc dalej\n");
			while(znak!='p')
			{
				znak = getch();
			}
		}
		
		system("cls");

	}

	return 0;
}

void InitTab(char **&WSK)
{
	WSK = (char**)malloc(sizeof(char*));
	WSK[0] = NULL;
}

void AddName(char *buf, char **&WSK)
{
	int poz = 0;
	while(WSK[poz]!=NULL) poz++;
	WSK = (char**)realloc(WSK, (poz+2)*sizeof(char*));
	WSK[poz+1] = NULL;
	printf("Podaj imie, ktore chcesz wprowadzic\n");
	fgets(buf, 81, stdin);
	WSK[poz] = strdup(buf);
}

void RemoveName1(int nr, char **&WSK)
{
	int poz = 0;
	while(WSK[poz]!=NULL) poz++;
	if(nr>=poz)
	{
		printf("Bledny indeks\n");
	}else
	{
		free(WSK[nr]);
		for(int i=nr; i<poz; i++) WSK[i]=WSK[i+1];
		WSK = (char**)realloc(WSK, poz*sizeof(char*));
	}

}

void PrintAllNames(char **WSK)
{
	int i, j;
	for(i=0; WSK[i]!=NULL; i++)
	{
		printf("Nr %d: ", i);
		for(j=0; WSK[i][j]!=0; j++)
		{
			printf("%c", WSK[i][j]);
		}
	}
}

void RemoveName2(char *buf, char **&WSK)
{
	char name[81];
	int result;
	int i;
	printf("Jakie imie chcesz usunac?\n");
	fgets(name, 81, stdin);
	
	for(i=0; WSK[i]!=NULL; i++)
	{
		result = strcmp(name, WSK[i]);
		if(result == 0)
		{
			RemoveName1(i, WSK);
			i--;
		}
	}
}

void PrintNames(char first_letter, char **WSK)
{
	int i,j;
	for(i=0; WSK[i]!=NULL; i++)
	{
		if(WSK[i][0]==first_letter)
		{
			printf("Nr %d: ", i);
			for(j=0; WSK[i][j]!=0; j++)
			{
				printf("%c", WSK[i][j]);
			}
			
		}
	}
}

void SortAlphabet(char **WSK)
{
	int i, j;
	int poz = 0;
	int result;
	char swap[81];
	while(WSK[poz]!=NULL) poz++;
	for(i=0; i<poz; i++)
	{
		for(j=1; j<poz-i; j++)
		{
			result = strcmp(WSK[j-1], WSK[j]);
			if(result>0)
			{
				int k = -1;
				do
				{
					k++;
					swap[k] = WSK[j-1][k];
					
				}while(WSK[j-1][k]!=0);
				
				WSK[j-1] = strdup(WSK[j]);
				WSK[j] = strdup(swap);
			}
			
		}
	}
}

void SortLength(char **WSK)
{
	int i, j;
	int poz = 0;
	int len1, len2;
	char swap[81];
	while(WSK[poz]!=NULL) poz++;
	for(i=0; i<poz; i++)
	{
		for(j=1; j<poz-i; j++)
		{
			len1 = strlen(WSK[j-1]);
			len2 = strlen(WSK[j]);
			
			if(len2<len1)
			{
				int k = -1;
				do
				{
					k++;
					swap[k] = WSK[j-1][k];
					
				}while(WSK[j-1][k]!=0);
				
				WSK[j-1] = strdup(WSK[j]);
				WSK[j] = strdup(swap);
			}
			
		}
	}
}