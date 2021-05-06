#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "data.h"

int* registrados = 0; 
int** matrix; 
int totaldesalidas=0; 

int main() {
    
    header();
    int i, j, pin, salir = 0, opcion = 0;

    matrix = (int**)malloc(sizeof(int*) * USUARIOS);
    for (i = 0; i < USUARIOS; i ++){
            matrix[i] = (int*)malloc(sizeof(int) * 6);
            for (j = 0; j <6 ; j++) {
                matrix[i][j] = -1;
            }
    }
}

void data() {
    int i, j, pin, salir = 0, opcion = 0;
    while(!salir) {
        int limite = count();
        printf("\nEn este momento hay %d trabajadores registrados\n", limite);
        printf("Este programa usa la funcion scanf, por favor cuide que su entrada sea correcta antes de dar enter\n");
        printf("Bienvenido\nEscribe\n1 Para registrar una entrada\n2 Para registrar una salida\n3 Para registrar un trabajador\n4 Cerrar el programa\n");
        scanf("%d", &opcion);
        
        if (opcion == 1) {
            printf("Cual es su pin?\n");
            scanf("%d", &pin);
            if (pin <= 0)
                printf("Entrada no valida\n");
            else if (pin<=limite) {
                if (matrix[pin-1][1]==-1);
                 //   entradaosalida(pin, 0);
                else
                    printf("Ya se tenia registrado una entrada de usted\n");
            } else 
                printf("En este momento hay %d trabajadores no puedes poner ese pin\n", limite);
        } else if (opcion == 2) {
            printf("Cual es su pin?\n");
            scanf("%d", &pin);
            if (pin<=0)
                printf("Entrada no valida\n");
            else if (pin<=limite) {
                if (matrix[pin-1][1]!=-1); 
                 //   entradaosalida(pin, 1);
                else
                    printf("Para registrar una salida debio registrarse una entrada\n");
            } else
                printf("En este momento hay %d trabajadores no puedes poner ese pin\n", limite);
        } 
        else if (opcion == 4) {
            for (i = 0; i < MAX; i++){
                if(matrix[i][0]*matrix[i][1]*matrix[i][2]>0&&matrix[i][3]*matrix[i][4]*matrix[i][5]<0){
                    printf("Error: El usuario con el pin <%d> registro una entrada pero no una salida\n\n", i+1);
                }
            }
        }
        else 
            printf("Opcion no disponible\n\n");
    }
 
    return;
}

int count() {
    FILE* sistema = fopen("sistema.txt", "r");
    char c;
    int count=0;
    while ((c = fgetc(sistema)) != EOF) {
        if (c == '\n')
            count++; 
    }
    
    return count;
}

void header(){
    time_t tiempoahora;
    time(&tiempoahora);
    struct tm *mitiempo = localtime(&tiempoahora);
    
    switch(mitiempo->tm_wday) {
        case 0: printf("Hoy es Domingo\n"); break;
        case 1: printf("Hoy es Lunes\n"); break;
        case 2: printf("Hoy es Martes\n"); break;
        case 3: printf("Hoy es Miercoles\n"); break;
        case 4: printf("Hoy es Jueves\n"); break;
        case 5: printf("Hoy es Viernes\n"); break;
        case 6: printf ("Hoy es Sabado\n"); break;
    }
    printf("Dia: %d/%d/%d\n", mitiempo->tm_mday, mitiempo->tm_mon+1, mitiempo->tm_year+1900); //tm year desde 1900 en mes 0 es enero)
    printf("Hora: %d:%d\n", mitiempo->tm_hour, mitiempo->tm_min);
    printf("El numero maximo de usuarios que pueden estar en el sistema son %d\n", USUARIOS);
}
