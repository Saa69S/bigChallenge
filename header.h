#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1024
#define MAX_LEN 10000

extern int ukuran;

void lowercase (char *str);
void url (char *kata);
void titleBody (char *hasil);
void tandaBaca (char *baris);

#endif