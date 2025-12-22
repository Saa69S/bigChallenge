#include "header.h"

    int main () {
    /*Buka File untuk dibaca*/
    FILE *in = fopen("Data-50k.txt","r");
    if (in == NULL) {
        printf("Error: File 'text.txt' tidak ditemukan\n");
        return 1;
    }
    
    /*Buka File untuk ditulis*/
    FILE *out = fopen("output.bin", "wb");
    if (out == NULL) {
        printf("Error: File 'file.txt' tidak dapat ditemukan\n");
        fclose(in);
        return 1;
    }

    char baris[MAX_LEN];
    rewind(in);
    while (fgets(baris, sizeof(baris), in) != NULL) {
        char temp[MAX_LEN];
        strcpy (temp, baris);

        /*Lowercase*/
        lowercase (temp);

        /*Abaikan URL*/
        url(temp);

        /*Himpun Title dan Body*/
        titleBody(temp);

        /*Abaikan Tanda Baca*/
        tandaBaca(temp);
        
        /*Abaikan Digit*/
        int i = 0, j = 0;
        while (temp[i]) {
            if (!isdigit((unsigned char)temp[i])) {
                temp[j++] = temp[i];
            }
            i++;
        }
        temp[j] = '\0';
        fputs(temp, out);
    }


fclose(in);
fclose(out);

printf("Proses telah selesai\n");
return 0;
}
