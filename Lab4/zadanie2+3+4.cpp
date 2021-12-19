/*
Autor: Igor Wlodarczyk
Grupa: PN/P 13:15
Temat: Laboratorium 4 zadanie 2,3,4
Data: 19.12.2021
*/

#include <stdio.h>
#include <string.h>

void wpisywanie(char *str);
//funkcja umozliwia wpisanie tekstu do c stringa
void* wyswietlanie(char str[]);
//funkcja wypisuje zawartosc c stringa
void usuwanie_cyfr(char *str);
//funkcja usuwa wszystkie cyfry z c stringa
char* usuwanie_komentarzy(char *str);
//funkcja usuwa wszystkie komentarze z c stringa


int a = 10;
int b = 11;
float c = 20.5;
float d = 21.5;
void zadanie_4();
//funkcja do zadania 4
void menu1();
//wyswietla menu
int main()
{
	printf("Autor: Igor Wlodarczyk\n\n");
	int n;
	bool menu = true;
	char tekst[81];
	menu1();
	while(menu)
	{
		printf("\n");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
				wpisywanie(tekst);
				break;
			case 2:
				wyswietlanie(tekst);
				break;
			case 3:
				usuwanie_cyfr(tekst);
				break;
			case 4:
				usuwanie_komentarzy(tekst);
				break;
			case 5:
				zadanie_4();
				break;
			case 6:
				menu = false;
				break;	
		}
		
	}
}
void menu1()
{
	printf("Menu\n");
	printf("1. Wpisywanie tekstu\n");
	printf("2. Wyswietlanie tekstu\n");
	printf("3. Usuwanie cyfr\n");
	printf("4. Usuwanie komentarzy\n");
	printf("5. Zadanie 4\n");
	printf("6. Koniec\n");
}

void zadanie_4()
{
	int e = 5;
	int f = 6;
	float x = 24.5;
	double z = 25.5;
	
	int *wsk1 = &a;
	int *wsk2 = &b;
	int *wsk3 = &e;
	int *wsk4 = &f;
	
	float *wsk5 = &c;
	float *wsk6 = &d;
	float *wsk7 = &x;
	double *wsk8 = &z;
	
	printf("Zmienna a - adres: %d. Wartosc: %4d | Rozmiar: %d bajty.  Typ int - zmienna globalna\n", wsk1, a, sizeof(a));
	printf("Zmienna b - adres: %d. Wartosc: %4d | Rozmiar: %d bajty.  Typ int - zmienna globalna\n", wsk2, b, sizeof(b));
	printf("Zmienna c - adres: %d. Wartosc: %4.1f | Rozmiar: %d bajty.  Typ float - zmienna globalna\n", wsk5, c, sizeof(c));
	printf("Zmienna d - adres: %d. Wartosc: %4.1f | Rozmiar: %d bajty.  Typ float - zmienna globalna\n", wsk6, d, sizeof(d));
	printf("Zmienna e - adres: %d. Wartosc: %4d | Rozmiar: %d bajty.  Typ int - zmienna lokalna\n", wsk3, e, sizeof(e));
	printf("Zmienna f - adres: %d. Wartosc: %4d | Rozmiar: %d bajty.  Typ int - zmienna lokalna\n", wsk4, f, sizeof(f));
	printf("Zmienna x - adres: %d. Wartosc: %4.1f | Rozmiar: %d bajty.  Typ float - zmienna lokalna\n", wsk7, x, sizeof(x));
	printf("Zmienna z - adres: %d. Wartosc: %4.1f | Rozmiar: %d bajtow. Typ double - zmienna lokalna\n", wsk8, z, sizeof(z));
	
	*wsk5 = x;
	*wsk6 = c;
	printf("Przypisanie wartosci zmiennym przy uzyciu ich adresow\n");
	printf("*wsk5 = x;\n");
	printf("*wsk6 = c;\n");
	printf("Zmienna c - %.2f\n", c);
	printf("Zmienna d - %.2f\n", d);
	printf("Przypisanie wartosci zmiennym przy uzyciu adresu innej zmiennej\n");
	e = *wsk1;
	f = *wsk2;
	printf("e = *wsk1;\n");
	printf("f = *wsk2;\n");
	printf("Zmienna e - %d\n", e);
	printf("Zmienna f - %d\n", f);
	c = 20.5;
	d = 21.5;
}

void wpisywanie(char *str)
{
	fgets(str, 81, stdin);
}

void* wyswietlanie(char str[])
{
	for(int i=0; str[i]!=0; i++) 
	{
		printf("%c", str[i]);
	}
}

void usuwanie_cyfr(char *str)
{
	int i = 0;
	while(str[i]!=0)
	{
		if(str[i]>=48 && str[i]<=57)
		{
			strcpy(&str[i], &str[i+1]);
		}else i++;
	}
}

char* usuwanie_komentarzy(char str[])
{
	int i;
	int k;
	// usuwanie komentarza - //
	i=0;
	while(str[i]!=0)
	{
		if(str[i]=='/' && str[i+1]=='/')
		{
			str[i]=0;
			i--;
		}
		i++;
	}
	
	//usuwanie komentarza - /* */
	i=0;
	while(str[i]!=0)
	{
		if(str[i]=='/' && str[i+1]=='*')
		{
			k = i;
			i+=2;
			while(str[i]!='*' && str[i+1]!='/' && str[i+1]!=0)
			{
				i++;
			}
			
			if(str[i+1]==0)
			{
				strcpy(&str[k], &str[i]);
				i = k-1;
				
			}else
			{
				strcpy(&str[k], &str[i+2]);
				i = k;
			}
		}
		i++;
	}
	return str;
	
	
}
