#include <pthread.h>
#include <stdio.h>
int Saldo;

void *holaHilo(void *arg) {
    printf("Hola desde un hilo\n");
    pthread_exit(NULL);
}
void * incrementarSaldo(){
    printf("Saldo actual %d\n", Saldo);
    Saldo=Saldo+100;
    printf("Saldo agregado %d\n", Saldo);
}

int main(){
    pthread_t t;
    Saldo = 0;

    for (int i = 1; i <= 100; i++) {
        pthread_create(&t, NULL, incrementarSaldo, NULL);
    }
    pthread_exit(NULL);
    return 0;
}