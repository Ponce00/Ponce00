#include <stdio.h>
#include <ctype.h>

#define MAX 1024

int read_file(char *text, char *filename);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./word file\n");
        return 1;
    }

    char text[MAX];

    if (read_file(text, argv[1])) {
        printf("Archivo no encontrado\n");
        return 1;
    }

    int i = 0, palabras=0, oraciones=0;

    while (text[i] != '\0') {
    
    if (isspace(text[i])){
        palabras++;
    }

    if (text[i] == '.' || text[i] == '?' || text[i] == '?'){
        oraciones++;
    }

    i++;
    }
    palabras++;
    printf("Cantidad de Palabras %d \n",palabras);
    printf("Cantidad de Oraciones %d \n",oraciones);
    return 0;
}

int read_file(char *text, char *filename) {

    FILE *fp;
    char c;
    char full_name[30];
    
    sprintf(full_name, "frases/%s.txt", filename);
    fp = fopen(full_name, "r");
    
    if (!fp) {
        return 1;
    } 
    while ((c = getc(fp)) != EOF) {
        *text = c;
        text++;
    }
    return 0;
}
