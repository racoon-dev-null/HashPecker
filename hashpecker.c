#include <stdio.h>
#include <string.h>
#include "md5.h"
#include "sha256.h"
#include "sha1.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Uso: %s <md5|sha256|sha1> <hash> <file_wordlist>\n", argv[0]);
        return 1;
    }

    char *algoritmo = argv[1];
    char *hash_target = argv[2];
    char riga[256];

    FILE *wordlist = fopen(argv[3], "r");

    if (wordlist == NULL) {
        printf("PICCOLO BAKA QUESTO FILE NON ESISTE!!\n");
        return 1;
    }

    while (fgets(riga, sizeof(riga), wordlist)) {
        riga[strcspn(riga, "\r\n")] = '\0';

        char hash_stringa[65];

        if (strcmp(algoritmo, "md5") == 0) {
            uint8_t hash_grezzo[16];
            md5String(riga, hash_grezzo);
            for (int i = 0; i < 16; i++) {
                sprintf(hash_stringa + (i * 2), "%02x", hash_grezzo[i]);
            }
            hash_stringa[32] = '\0';
        }
        else if (strcmp(algoritmo, "sha256") == 0) {
            BYTE hash_grezzo_sha[32];
            SHA256_CTX ctx;
            sha256_init(&ctx);
            sha256_update(&ctx, (BYTE*)riga, strlen(riga));
            sha256_final(&ctx, hash_grezzo_sha);
            for (int i = 0; i < 32; i++) {
                sprintf(hash_stringa + (i * 2), "%02x", hash_grezzo_sha[i]);
            }
            hash_stringa[64] = '\0';
        }
        else if (strcmp(algoritmo, "sha1") == 0) {
    BYTE hash_grezzo_sha1[20];
    SHA1_CTX ctx;
    sha1_init(&ctx);
    sha1_update(&ctx, (BYTE*)riga, strlen(riga));
    sha1_final(&ctx, hash_grezzo_sha1);
    for (int i = 0; i < 20; i++) {
        sprintf(hash_stringa + (i * 2), "%02x", hash_grezzo_sha1[i]);
    }
    hash_stringa[40] = '\0';
}

        else {
            printf("Algoritmo non supportato! Usa md5, sha256 o sha1.\n");
            fclose(wordlist);
            return 1;
        }

        if (strcmp(hash_stringa, hash_target) == 0) {
            printf("Senpai ho trovato la password! ecco a te la password: %s\n", riga);
            fclose(wordlist);
            return 0;
        }
    }

    printf("Senpai non ho trovato nessuna password nella wordlist.\n");
    fclose(wordlist);
    return 0;
}