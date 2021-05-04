#include<stdio.h>
#include <string.h>
#include <time.h>

FILE *file;
int counter = 0;
char args[100] = "";

void reader() {
    int lenarg = strlen(args);
    char buf[100];
    while (fscanf(file,"%s",buf)==1) {
	    if (strncmp(buf, args, lenarg) == 0 || strcmp(&buf[strlen(buf)-lenarg], args) == 0) {
		    counter++;
	    }
    }
}

int main(int argc, char *argv[]) {
    file = fopen("endgame_script.tex","r");
    if (file == NULL) {
        printf("no such file.");
        return 0;
    }
    strcpy(args, argv[1]);
    printf("%s\n", args);

    clock_t begin = clock();
    
    reader();

    clock_t end = clock();
    printf("Cantidad de palabras \"%s\" en el archivo de texto: %d \n", argv[1], counter);
    printf("Tiempo: %.10f \n", (double) (end-begin)/CLOCKS_PER_SEC);

    return 0;
}


