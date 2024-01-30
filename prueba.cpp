//Incluye las bibliotecas que son necesarias para el programa
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <cmath>

//Incluye el archivo .h el cual contiene los 5 algoritmos 
//que serán necesarios para este programa
#include "ordenamiento_f.h"

using namespace std;
using namespace std::chrono;

//De la linea 22 a la 75
//son las mismas funciones, la única diferencia es que se crea una para cada 
//algoritmo para que pueda ejecutarse el programa de forma correcta.

//Recibe un apuntador a un arreglo de enteros, el tamaño del arreglo y el rango máximo
duration<double> crear_arreglo(int *A, int TAM_ARREGLO, int RANGO_MAX) {
    //La función genera números de 0 al rango máximo y los asigna al arreglo A
    //y mide el tiempo que tarda en realizar la operación.
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    for (int i = 0; i < TAM_ARREGLO; i++) {
        int x = rand() % RANGO_MAX;
        A[i] = x;
    }
    //Esta función nos ayuda a obtener el tiempo de principio a fin la operación
    //calcula la duración del tiempo que ha transcurrido y regresa el tiempo en segundos.
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_insertion_sort(int *A, int TAM_ARREGLO){
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    insertion_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_selection_sort(int *A, int TAM_ARREGLO){
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    selection_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_bubblesort(int *A, int TAM_ARREGLO){
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    bubblesort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_merge_sort(int *A, int TAM_ARREGLO){
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    merge_sort(A, 0, TAM_ARREGLO - 1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

duration<double> ordenar_quicksort(int *A, int TAM_ARREGLO){
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    quicksort(A, 0, TAM_ARREGLO - 1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    return tiempo;
}

//Esta función recibe un arreglo A con tamaño n.
int *copiar_arreglo(const int A[], int n) {
    //Crea un nuevo arreglo B del mismo tamaño que A
    int* B = new int[n];
    //Copia los elementos del arreglo A por medio de un ciclo for.
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
    }
    //Regresa un apuntador al arreglo B ya con la copia de los elementos.
    return B;
}

//La función recibe el número de repetición y el tiempo de ejecución de los 5 algoritmos
void imprimirTabla(int repeticion, double t_is, double t_ss, double t_bs, double t_ms, double t_qs){
    //Si es la primera repetición, la función imprime los encabezados de tabla.
    if (repeticion == 1) {
        std::cout << std::setw(6) << "#ejec" << std::setw(12) << "is_t" << std::setw(12) << "ss_t" << std::setw(12) << "bs_t" << std::setw(12) << "ms_t" << std::setw(12) << "qs_t" << std::endl;
    }

    //Define una función que se encarga de imprimir los tiempos 
    auto imprimirTiempo = [](double tiempo) {
        //Imprime los tiempos en notación científica
        if (tiempo < 0.00009) {
            std::cout << std::setw(12) << std::scientific << std::setprecision(5) << tiempo;
        } 
        //Imprime los tiempos en notación fija
        else {
            std::cout << std::setw(12) << std::fixed << std::setprecision(5) << tiempo;
        }
    };

    //Imprime los resultados de la repetición actual, muestra el
    //número de repetición y los tiempos de ejecución de cada algoritmo.
    std::cout << std::setw(6) << repeticion << "\t";
    imprimirTiempo(t_is);
    imprimirTiempo(t_ss);
    imprimirTiempo(t_bs);
    imprimirTiempo(t_ms);
    imprimirTiempo(t_qs);
    std::cout << std::endl;
}

//Recibe un arreglo de los tiempos y el número de repeticiones
//calcula la desviación estándar de los tiempos.
double calcularDesviacionEstandar(double tiempos[], int numRepeticiones) {
    double sumatoria = 0.0;
    double t_promedio = 0.0;

    //Calcula el promedio de los tiempos
    for (int i = 0; i < numRepeticiones; ++i){
        //Suma todos los tiempos
        sumatoria += tiempos[i];
    }

    //El resultado de la suma lo divide entre el número de repeticiones
    t_promedio = sumatoria / numRepeticiones;

    //Calcula la diferencia al cuadrado entre cada tiempo y el promedio
    //sumando las diferencias al cuadrado.
    double sumatoriaDifCuadratica = 0.0;
    for (int i = 0; i < numRepeticiones; ++i){
        double dif = tiempos[i] - t_promedio;
        sumatoriaDifCuadratica += dif * dif;
    }

    //Divide la suma entre el número de repeticiones para obtener la varianza.
    double varianza = sumatoriaDifCuadratica / numRepeticiones;
    //Calcula la raíz cuadrada de la varianza para obtener la desviación estándar.
    double desviacionEstandar = sqrt(varianza);

    //Regresa el resultado de la desviación estándar.
    return desviacionEstandar;
}

//Esta función experimenta para poder medir
//los tiempos de ejecución de los algoritmos.
void experimentos(int tam) {

    //Se usa el tamaño del arreglo para utilizar en los experimentos.
    int TAM_ARREGLO = tam;
    int RANGO_MAX = 10 * TAM_ARREGLO;
    //Se ponen las repeticiones que se desean realizar para cada arreglo.
    int REPETICIONES = 30;

    //Inicializa constantes, variables y arreglos para 
    // almacenar los tiempos promedio de cada algoritmo.
    double t_prom_is = 0.0;
    double t_prom_ss = 0.0;
    double t_prom_bs = 0.0;
    double t_prom_ms = 0.0;
    double t_prom_qs = 0.0;

    double tiempos_is[REPETICIONES];
    double tiempos_ss[REPETICIONES];
    double tiempos_bs[REPETICIONES];
    double tiempos_ms[REPETICIONES];
    double tiempos_qs[REPETICIONES];

    srand((unsigned) time(0));

    //El ciclo for ejecuta un número determinado de repeticiones
    for (int i = 0; i < REPETICIONES; i++) {

        double t_is = 0.0;
        double t_ss = 0.0;
        double t_bs = 0.0;
        double t_ms = 0.0;
        double t_qs = 0.0;

        //Se crea un nuevo arreglo
        int *A = new int[TAM_ARREGLO];
        //Se declara la variable para almacenar el tiempo de ejecución.
        duration<double> tiempo;

        //Se manda a llamar a la funciín para llenar el arreglo A.
        crear_arreglo(A, TAM_ARREGLO, RANGO_MAX);

        //se crea un nuevo arreglo auxiliar para hacer una copia del arreglo A.
        int *aux;

        //De la linea 200 a la 238 realizan lo mismo, solo que se crean
        //para cada algoritmo para que el programa pueda ejecutarse de 
        //la forma correcta.
        aux = copiar_arreglo(A, TAM_ARREGLO);
        //el tiempo se almacena en la variable tiempo
        tiempo = ordenar_insertion_sort(aux, TAM_ARREGLO);
        //se actualiza la suma acumulada del tiempo promedio con el tiempo medido
        t_prom_is += tiempo.count();
        //se asigna el tiempo medido a la variable t_is
        t_is = tiempo.count();
        //se almacena el tiempo en la posición del arreglo
        tiempos_is[i] = tiempo.count();
        //se libera la memoria asignada al arreglo auxiliar.
        delete[] aux;

        aux = copiar_arreglo(A, TAM_ARREGLO);
        tiempo = ordenar_selection_sort(A, TAM_ARREGLO);
        t_prom_ss += tiempo.count();
        t_ss = tiempo.count();
        tiempos_ss[i] = tiempo.count();
        delete[] aux;

        aux = copiar_arreglo(A, TAM_ARREGLO);
        tiempo = ordenar_bubblesort(aux, TAM_ARREGLO);
        t_prom_bs += tiempo.count();
        t_bs = tiempo.count();
        tiempos_bs[i] = tiempo.count();
        delete[] aux;

        aux = copiar_arreglo(A, TAM_ARREGLO);
        tiempo = ordenar_merge_sort(A, TAM_ARREGLO);
        t_prom_ms += tiempo.count();
        t_ms = tiempo.count();
        tiempos_ms[i] = tiempo.count();
        delete[] aux;

        aux = copiar_arreglo(A, TAM_ARREGLO);
        tiempo = ordenar_quicksort(A, TAM_ARREGLO);
        t_prom_qs += tiempo.count();
        t_qs = tiempo.count();
        tiempos_qs[i] = tiempo.count();
        delete[] aux;

        //manda a imprimir la tabla 
        imprimirTabla(i+1, t_is, t_ss, t_bs, t_ms, t_qs);

        //se libera la memoria asignada para los arreglos.
        delete [] A;
    }
    
    //Calcula los tiempos promedio de las ejecuciones de cada algoritmo
    //divide la suma acumulada de los tiempos entre el número de repeticiones.
    t_prom_is = t_prom_is / REPETICIONES;
    t_prom_ss = t_prom_ss / REPETICIONES;
    t_prom_bs = t_prom_bs / REPETICIONES;
    t_prom_ms = t_prom_ms / REPETICIONES;
    t_prom_qs = t_prom_qs / REPETICIONES;

    //Imprime los resultados de los experimentos del tiempo de ejecución
    cout << "*** RESULTADOS: ***" << endl;

    cout << "*** Insertion sort: ***" << endl;
    cout << "Tiempo promedio:\t" << t_prom_is << endl;
    cout << "Desviación Estandar:\t" << calcularDesviacionEstandar(tiempos_is, REPETICIONES) << endl;

    cout << "*** Selection sort: ***" << endl;
    cout << "Tiempo promedio:\t" << t_prom_ss << endl;
    cout << "Desviación Estandar:\t" << calcularDesviacionEstandar(tiempos_ss, REPETICIONES) << endl;

    cout << "*** Bubble sort: ***" << endl;
    cout << "Tiempo promedio:\t" << t_prom_bs << endl;
    cout << "Desviación Estandar:\t" << calcularDesviacionEstandar(tiempos_bs, REPETICIONES) << endl;

    cout << "*** Merge sort: ***" << endl;
    cout << "Tiempo promedio:\t" << t_prom_ms << endl;
    cout << "Desviación Estandar:\t" << calcularDesviacionEstandar(tiempos_ms, REPETICIONES) << endl;

    cout << "*** Quicksort: ***" << endl;
    cout << "Tiempo promedio:\t" << t_prom_qs << endl;
    cout << "Desviación Estandar:\t" << calcularDesviacionEstandar(tiempos_qs, REPETICIONES) << endl;
}

//Toma los argumentos, realiza una prueba de los algoritmos con el tamaño que se especifíca.
int main(int argc, char *argv[]) {
    //Si el número de argumentos es diferente que 2, imprime el mensaje indicado
    if (argc != 2) {
        cout << "Sintaxis: ordenamiento <tamaño arreglo>" << endl;
    } 
    //Si se proporciona el tamaño del arreglo como argumento inicia la prueba
    //mostrando el tamaño del arreglo y manda a llamar a la función experimentos
    //con el tamaño del arreglo como argumento y realiza la prueba.
    else {
        cout << "Inicia prueba con: " << endl;
        cout << "Tamaño del arreglo: " << argv[1] << endl;
        experimentos(atoi(argv[1]));
    }
    //indica que el programa se ejecutó de manera correcta.
    return EXIT_SUCCESS;
}
