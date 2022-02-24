/*
Autor: Igor Wlodarczyk
Grupa: PN/P 13:15
Temat: Laboratorium 5 zadanie 2
Data: 29.12.2021
*/
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <conio.h>
#include <windows.h>

#include <stdio.h>
using namespace std;
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
		cout<<"Autor: Igor Wlodarczyk"<<endl;
		cout<<"| Menu"<<endl;
		cout<<"| 1. Dodaj imie"<<endl;
		cout<<"| 2. Usun imie po numerze pozycji"<<endl;
		cout<<"| 3. Usun imie wprowadzone z klawiatury"<<endl;
		cout<<"| 4. Drukowanie wszystkich imion"<<endl;
		cout<<"| 5. Drukowanie imion rozpoczynajacych sie wskazana litera"<<endl;
		cout<<"| 6. Sortowanie alfabetyczne"<<endl;
		cout<<"| 7. Sortowanie wedlug dlugosci"<<endl;
		cout<<"| 8. Koniec"<<endl;
		n = getch();
		switch(n)
		{
			case '1':
				AddName(buf, WSK);
				break;
			case '2':
				unsigned int nr;
				cout<<"Podaj indeks wiersza, z ktorego ma byc usuniete imie"<<endl;
				cin>>nr;
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
				cout<<"Podaj litere"<<endl;
				char first_letter;
				cin>>first_letter;
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
			cout<<"Wcisnij 'p', aby przejsc dalej"<<endl;
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
	WSK = new char*[1];
	WSK[0] = NULL;
}

void AddName(char *buf, char **&WSK)
{
	int poz = 0;
	while(WSK[poz]!=NULL) poz++;
	char **WSKcopy;
	WSKcopy = new char*[poz+1];
	memcpy(WSKcopy, WSK, (poz+1)*sizeof(WSK));
	delete[] WSK;
	WSK = new char*[poz+2];
	memcpy(WSK, WSKcopy, (poz+1)*sizeof(WSK));
	delete[] WSKcopy;
	WSK[poz+1] = NULL;
	cout<<"Podaj imie, ktore chcesz wprowadzic"<<endl;
	fgets(buf, 81, stdin);
	WSK[poz] = strdup(buf);
}
void RemoveName1(int nr, char **&WSK)
{
	int poz = 0;
	while(WSK[poz]!=NULL) poz++;
	char **WSKcopy;
	WSKcopy = new char*[poz];
	if(nr>=poz)
	{
		cout<<"Bledny indeks"<<endl;
	}else
	{
		delete WSK[nr];
		for(int i=nr; i<poz; i++) WSK[i]=WSK[i+1];
		memcpy(WSKcopy, WSK, poz*sizeof(WSK));
		delete[] WSK;
		WSK = new char*[poz];
		memcpy(WSK, WSKcopy, poz*sizeof(WSK));
		delete[] WSKcopy;
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