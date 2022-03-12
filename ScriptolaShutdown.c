#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int h, htos;

    printf("Desligar pc em quantas horas? (0 = agora)\n");
    scanf("%d", &h);

    char st[10];

    htos = h * 3600;

    char htos_s[50] = "C:\\WINDOWS\\System32\\shutdown -s -t ";
    sprintf(st, "%d", htos);
    strcat(htos_s, st);

    system(htos_s);

    return 0;
}