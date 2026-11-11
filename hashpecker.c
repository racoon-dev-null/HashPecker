#include <stdio.h>
#include <string.h>
#include "md5.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <hash_md5> <file_wordlist>\n", argv[0]);
        return 1;
    }

    char *hash_target = argv[1];


    char riga[256];

    FILE *wordlist = fopen(argv[2], "r");

    if (wordlist == NULL) {
    printf("PICCOLO BAKA QUESTO FILE NON ESISTE!!\n");
    return 1;
    }
     while (fgets(riga, sizeof(riga), wordlist)) {
        riga[strcspn(riga, "\r\n")] = '\0';

        uint8_t hash_grezzo[16];
        md5String(riga, hash_grezzo);
        char hash_stringa[33];
        for (int i = 0; i < 16; i++) {
            sprintf(hash_stringa + (i * 2), "%02x", hash_grezzo[i]);
        }
        hash_stringa[32] = '\0';
        if (strcmp(hash_stringa, hash_target) == 0) {

            printf("Senpai ho trovato la password! ecco a te la password: %s\n",riga);
            fclose(wordlist);
            return 0;
        }
    }
    



    return 0;   
}