#include "header.h"
/*Lowercase*/
void lowercase (char *huruf) {
    for (int i = 0; huruf[i] != '\0'; i++) {
        if (huruf[i] >= 'A' && huruf[i] <= 'Z'){
            huruf[i] = huruf[i] + 32;
        }
    }
}

/*Abaikan URL*/
 void url (char *kata) {
    char *p = kata;
    while (*p) {
        if (*p == '<' && *(p+1) == 'u' && *(p+2) == 'r' && *(p+3) == 'l' && *(p+4) == '>') {
            char *awal = p;
            p +=5;
            char *akhir = NULL;
            while(*p) {
                if (*p == '<' && *(p+1) == '/' && *(p+2) == 'u' && *(p+3) == 'r' && *(p+4) == 'l' && *(p+5) == '>') {
                    akhir = p + 6;
                    break;
                }
                p++;
            }
            if (akhir) {
                char *src = akhir;
                char *dst = awal;
                while ((*dst++ = *src++));
                p = awal;
            }else {
                break;
            }
        }else {
            p++;
        }
    }
}

/*Himpun Title dan Body*/
void titleBody(char *html) {
    char *p = html;
    while (*p) {
        if (*p == '<') {
            // Cek tag <title>
            if (*(p+1) == 't' && *(p+2) == 'i' && *(p+3) == 't' && *(p+4) == 'l' && *(p+5) == 'e' && *(p+6) == '>') {
                char *awal = p;
                p += 7;
                char *akhir = NULL;
                while (*p) {
                    if (*p == '<' && *(p+1) == '/' && *(p+2) == 't' && *(p+3) == 'i' && *(p+4) == 't' && *(p+5) == 'l' && *(p+6) == 'e' && *(p+7) == '>') {
                        akhir = p;
                        break;
                    }
                    p++;
                }
                
                if (akhir) {
                    char *src = akhir + 8;
                    char *dst = awal;
                    char *konten = awal + 7;
                    while (konten < akhir) *dst++ = *konten++;
                    while ((*dst++ = *src++));
                    p = awal;
                }
            }
            // Cek tag <body>
            else if (*(p+1) == 'b' && *(p+2) == 'o' && *(p+3) == 'd' && *(p+4) == 'y' && *(p+5) == '>') {
                char *awal = p;
                p += 6;
                char *akhir = NULL;
                
                // Cari </body>
                while (*p) {
                    if (*p == '<' && *(p+1) == '/' && *(p+2) == 'b' && *(p+3) == 'o' && *(p+4) == 'd' && *(p+5) == 'y' && *(p+6) == '>') {
                        akhir = p;
                        break;
                    }
                    p++;
                }
                
                if (akhir) {
                    char *src = akhir + 7;
                    char *dst = awal;
                    char *konten = awal + 6;
                    while (konten < akhir) *dst++ = *konten++;
                    while ((*dst++ = *src++));
                    p = awal;
                }
            } else {
                p++;
            }
        } else {
            p++;
        }
    }
}

/*Mengabaikan Tanda Baca*/
void tandaBaca (char *teks) {
    int i = 0, j = 0;
    while (teks[i]) {
        if (!ispunct(teks[i]) || teks[i] == ' ' || teks[i] == '\n' || teks[i] == '\t') {
            teks[j++] = teks[i];
        }
        i++;
    }
    teks[j] = '\0';
}