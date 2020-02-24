#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic>
using namespace std;

int valor = 0;
atomic<int> globalv(0);

void disminuye() {
    for (int i = 0; i < 10000; i++) {
        globalv -= 1;
        //cout << "Hilo: " << this_thread::get_id() << " ejecutando disminucion() el valor es= " << globalv << endl;
        //sleep(1);
    }
}

void aumenta() {
    for (int i = 0; i < 10000; i++) {
        globalv += 1;
        //cout << "Hilo: " << this_thread::get_id() << " ejecutando aumento() el valor es= " << globalv << endl;
        //sleep(1);
    }
}

int main() {
    thread th1(disminuye), th2(aumenta);
    printf("Proceso principal espera que los hilos terminen\n");
    th1.join();
    th2.join();
    cout << "El hilo principal termina\n";
    cout << "el valor es" << globalv.load() << endl;
    exit(0);
}
