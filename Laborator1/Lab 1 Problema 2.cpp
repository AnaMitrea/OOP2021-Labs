#include <stdio.h>
#include <string.h>
using namespace std;

int characterToInteger(char str[])
{
    int nr = 0, i = 0;
    while (str[i] != '\0')
    {
        nr *= 10;
        nr += (str[i] - '0');
        i++;
    }
    return nr;
}

int main()
{
	int sum = 0;
	FILE* fp = fopen("in.txt", "r");

	while (feof(fp) == 0)
	{
	    char str[10] = "\0";
	    fscanf(fp,"%s",str);
        sum = sum + characterToInteger(str);;
	}
    printf("Suma numerelor din fisier este: %i", sum);
    fclose(fp);
	return 0;
}
