#include <cs50.h>
#include <stdio.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#define _GNU_SOURCE
#include <crypt.h>

int main(void)
{
    string letra = get_string("Introduzca la letra que quiere encriptar: ");
    string hash = crypt(letra, "50");
    printf("%s\n", hash);
}