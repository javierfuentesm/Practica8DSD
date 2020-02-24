#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
using namespace std;
int valor = 0;
mutex m;

void disminuye() {
    for (int i = 0; i < 100000; i++) {
        m.lock();

        valor -= 1;
        //printf("Hilo %ld ejecutando disminucion(). Valor: %d\n", this_thread::get_id(), valor);
        //sleep(1);

        m.unlock();
    }
}

void aumenta() {
    for (int i = 0; i < 100000; i++) {
        m.lock();

        valor += 1;
        //printf("Hilo %ld ejecutando aumento(). Valor: %d\n", this_thread::get_id(), valor);
        //sleep(1);
        m.unlock();

    }
}

int main() {
    thread th1(aumenta), th2(disminuye);
    printf("Proceso principal espera que los hilos terminen\n");
    th1.join();
    th2.join();
    printf("El hilo principal termina\n");
    printf("VALOR: %d\n", valor);
    exit(0);
}
