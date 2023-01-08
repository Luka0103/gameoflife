#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Konstanten
#define ARRAY_LENGHT 20


char welt[ARRAY_LENGHT][ARRAY_LENGHT];
char nextGen[ARRAY_LENGHT][ARRAY_LENGHT];
int aktGeneration = 0;
int generationen = 0;

char eingabe='Z';


void fuelleArray() {
	for (size_t i = 0; i < ARRAY_LENGHT; i++)
	{
		for (size_t j = 0; j < ARRAY_LENGHT; j++)
		{
			welt[i][j] = '.';
		}
	}
}
void fuelleArrayNextGen() {
	for (size_t i = 0; i < ARRAY_LENGHT; i++)
	{
		for (size_t j = 0; j < ARRAY_LENGHT; j++)
		{
			nextGen[i][j] = '.';
		}
	}
}
void printArray() {
	printf("-- Generation: %d\n", aktGeneration);
	for (size_t i = 0; i < ARRAY_LENGHT; i++)
	{
		for (size_t j = 0; j < ARRAY_LENGHT; j++)
		{
			printf("%c", welt[j][i]);
		}
		printf("\n");
	}
}
void printArrayNextGen() {
	printf("NEXT GEN\n");
	for (size_t i = 0; i < ARRAY_LENGHT; i++)
	{
		for (size_t j = 0; j < ARRAY_LENGHT; j++)
		{
			printf("%c", nextGen[j][i]);
		}
		printf("\n");
	}
}

void getImputs() {
	scanf("%d", &generationen);
	int x=0;
	int y=0;

	while (1) {
		scanf(" %c", &eingabe);
		if (eingabe == 'e') break;

		scanf("%d %d", &x, &y);
		welt[x][y] = '#';
	}
}


int getNachbarn(int x, int y) {

	int nachbarn = 0;
	int zelleLebt=0;
	if (welt[x][y] == '#') zelleLebt = 1;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (((x - 1) + j >= 0 && (x - 1) + j <= 19) && ((y - 1) + i >= 0 && (y - 1) + i <= 19)) {
				if (welt[(x - 1) + j][(y - 1) + i] == '#') {
					nachbarn++;
				}
			}
			
		}
	}
	return nachbarn-zelleLebt;
}
void berechneFelder() {
	fuelleArrayNextGen();
	for (size_t i = 0; i < ARRAY_LENGHT; i++)
	{
		for (size_t j = 0; j < ARRAY_LENGHT; j++)
		{
			if (welt[j][i] != '#' && getNachbarn(j, i) == 3)nextGen[j][i] = '#';
			if (welt[j][i] == '#') {
				int nachbarn = getNachbarn(j, i);
				if (nachbarn == 2 || nachbarn == 3)nextGen[j][i] = '#';
				
			}
		}
	}
}

void tauschArray() {
	fuelleArray();
	for (size_t i = 0; i < ARRAY_LENGHT; i++)
	{
		for (size_t j = 0; j < ARRAY_LENGHT; j++)
		{
			welt[j][i] = nextGen[j][i];
		}
	}
}

void spielStart() {
	printArray();
	aktGeneration++;
	for(aktGeneration; aktGeneration <= generationen; aktGeneration++)
	{
		berechneFelder();
		tauschArray();
		printArray();
	}
}

int main() {
	fuelleArray();
	getImputs();
	spielStart();
	return 0;
}