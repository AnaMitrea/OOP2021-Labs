#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char s[50];
    char v[50][50];
    scanf("%[^\n]",s);
    char* p = strtok(s," ");
    int i = 0;
    while(p) {
        strcpy(v[i],p);
        i++;
        p = strtok(NULL," ");
    }

    for(int a = 0 ; a < i - 1; a++)
        for(int b = a + 1 ; b < i; b++)
        {
            if(strlen(v[a]) < strlen(v[b]))
            {
                char aux[50];
                strcpy(aux,v[a]);
                strcpy(v[a],v[b]);
                strcpy(v[b],aux);
            }
            else
                if(strlen(v[a]) == strlen(v[b]))
                {
                    if(strcmp(v[a],v[b]) > 0)
                    {
                        char aux[50];
                        strcpy(aux,v[a]);
                        strcpy(v[a],v[b]);
                        strcpy(v[b],aux);
                    }
                }
        }

    for(int k = 0; k < i; k++)
        printf("Cuvantul este: %s \n",v[k]);

    return 0;
}
