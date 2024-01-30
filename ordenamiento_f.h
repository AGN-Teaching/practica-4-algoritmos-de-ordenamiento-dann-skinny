void intercambiar(int A[], int x, int y) {
    int aux = A[x];
    A[x] = A[y];
    A[y] = aux;
}

void insertion_sort(int A[], int n) {
    for (int j = 1; j < n; j++) {
        int k = A[j];
        int i = j - 1;
 
        while (i >= 0 && A[i] > k) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = k;
    }
}

void selection_sort(int A[], int n) {
    for (int j = 0; j < n-1; j++) {
        int menor = j;
 
        for (int i = j+1; i < n; i++) {
            if (A[i] < A[menor]) {
                menor = i;
            }
        }
        intercambiar (A, j, menor);
    }
}


void bubblesort(int A[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = n-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                intercambiar(A, j, j-1);
            }
        }
    }
} 

void merge(int A[], int inicio, int medio, int fin) {
    int *aux = new int[fin - inicio + 1];
    int i = inicio;    
    int j = medio + 1;  
    int h = 0;

    while ((i <= medio) && (j <= fin)) {
        if (A[i] <= A[j]) {
            aux[h] = A[i];
            i += 1;
        } else {
            aux[h] = A[j];
            j += 1;
        }
        h += 1;
    }

    if (i > medio) {
        while (j <= fin) {
            aux[h] = A[j];
            j += 1;
            h += 1;
        }
    } 
    else {
        while (i <= medio) {
            aux[h] = A[i];
            i += 1;
            h += 1;
        }
    }
    
    h = 0;
    for (int k = inicio; k <= fin; k++) {
        A[k] = aux[h];
        h += 1;
    }
    delete [] aux;
}

void merge_sort(int A[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        merge_sort(A, inicio, medio);
        merge_sort(A, medio + 1, fin);
        merge(A, inicio, medio, fin);
    }
}

int partition(int A[], int p, int r) {
    int pivote = A[r];
    int ultimo = p - 1;

    for (int i = p; i < r; i++) {
        if (A[i] < pivote) {
            ultimo += 1;
            intercambiar(A, ultimo, i);
        }
    }

    intercambiar(A, ultimo + 1, r);
    return ultimo + 1;
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}
