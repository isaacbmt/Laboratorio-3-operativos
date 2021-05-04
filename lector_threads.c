#include<stdio.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

FILE *file;
int counter = 0;
char args[100] = "";

void *reader(void *param) {
    int lenarg = strlen(args);
    char buf[100];
    while (fscanf(file,"%s",buf)==1) {
	    if (strncmp(buf, args, lenarg) == 0 || strcmp(&buf[strlen(buf)-lenarg], args) == 0) {
		    counter++;
	    }
    }
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    file = fopen("endgame_script.tex","r");
    if (file == NULL) {
        printf("no such file.");
        return 0;
    }
    strcpy(args, argv[1]);
    printf("%s\n", args);
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;
    pthread_t t5;

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    clock_t begin = clock();
    pthread_create(&t1, &attr, reader, NULL);
    pthread_create(&t2, &attr, reader, NULL);
    pthread_create(&t3, &attr, reader, NULL); 
    pthread_create(&t4, &attr, reader, NULL);
    pthread_create(&t5, &attr, reader, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);

    clock_t end = clock();
    printf("Cantidad de palabras \"%s\" en el archivo de texto: %d \n", argv[1], counter);
    printf("Tiempo: %.10f \n", (double) (end-begin)/CLOCKS_PER_SEC);

    return 0;
}


