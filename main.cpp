#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic>
using namespace std;

int valor = 0;
atomic<int> globalv(0);

void disminuye(atomic<int>& globalv) {
    for (int i = 0; i < 100000; i++) {
        globalv -= 1;
        //printf("Hilo %ld ejecutando aumento(). Valor: %d\n", this_thread::get_id(), globalv.load());
        //sleep(1);
    }
}

void aumenta(atomic<int>& globalv) {
    for (int i = 0; i < 100000; i++) {
        globalv += 1;

        //printf("Hilo %ld ejecutando aumento(). Valor: %d\n", this_thread::get_id(), globalv.load());
        //sleep(1);
    }
}

int main() {
    thread th1(disminuye, ref(globalv)), th2(aumenta, ref(globalv));
    printf("Proceso principal espera que los hilos terminen\n");
    th1.join();
    th2.join();
    cout << "El hilo principal termina\n";
    cout << "el valor es" << globalv.load() << endl;
    exit(0);
}
