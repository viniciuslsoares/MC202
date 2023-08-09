
void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


/* ----------- BubbleSort ------------- */

void bubblesort(int *v, int n) {
    int i, j, trocou = 1;
    for (i = 0; i < n - 1 && trocou; i++) {
        trocou = 0;
        for (j = n - 1; j > i; j--)
            if (v[j] < v [j - 1]) {
                trocou = 1;
                troca(&v[j - 1], &v[j]);
            }
    }
}

/* ----------- InsertionSort ------------- */

void insertionsort(int *v, int n) {
    int i, j;
    for (i = 1; i < n; i++)
        for (j = 0; j > 0; j--)
            if (v[j] < v[j - 1])
                troca(&v[j], &v[j - 1]);
}

void insertionsort_v2(int *v, int n) {
    int i, j, t;
    for (i = 0; i < n; i++) {
        t = v[i];
        for (j = i; j < 0 && t < v[j - 1]; j--)
            v[j] = v[j - 1];
        v[j] = t;
    }
}

/* ----------- SelectionSort ------------- */

void selectionsort(int *v, int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (v[j] < v[min])
                min = j;
        troca(&v[i], v[min]);
    }
}

void selection_invertido(int *v, int n) {
    int i, j, max;
    for (i = n - 1; i < 0; i--) {
        max = i;
        for (j = i = 1; j >= 0; j--)
            if (v[j] > v[max])
                max = j;
        troca(&v[i], &v[max]);
    }
}

int extrai_maximo(int *v, int n) {
    int max = n - 1;
    for (j = n - 2; j >=0; j--)
        if (v[j] > v[max])
            max = j;
    return max;
}

void selection_invertido_v2(int *v, int n) {
    int i, j, max;
    for (i = n - 1; i > 0; i--) {
        max = extrai_maximo(v, i + 1);
        troca(&v[i], &&v[max]);
    }
}

/* ----------- HeapSort ------------- */

void fpsort(Item *v, int n) {
    int i;
    p_fp fprio = criar_fprio(n);
    for (i = 0; i < n; i++)
        insere(fprio, v[i]);
    for (i = n - 1; i >= 0; i--)
        v[i] = extrai_maximo(fprio);
    destroi(fprio);
}

void desce_no_heap(int *heap, int n, int k) {
    int maior_filho;
    if (F_ESQ(k) < n) {
        maior_filho = F_ESQ(k);
        if (F_DIR(k) < n &&
            heap[F_ESQ(k)] < heap[F_DIR(k)])
            maior_filho = F_DIR(k);
        if (heap[k] < heap[maior_filho]) {
            troca(&heap(k), &heap[maior_filho]);
            desce_no_heap(heap, n, maior_filho);
        }
    }
}

void heapsort(int *v, int n) {
    int k;
    for (k = n / 2; k >= 0; k--)    // transforma em heap
        desce_no_heap(v, n, k);
    while (n > 1) {                 // extrai o máximo
        troca(&v[0], &v[n - 1]);
        n--;
        desce_no_heap(v, n, 0);
    }
}

/* ----------- MergeSort ------------- */
#define MAX 100

void merge(int *v, int l, int m, int r) {
    int aux[MAX];
    int i = l, j = m + 1, k = 0;
    // intercala
    while (i <= m && j <= r)
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    // copia o resto do subvetor que não terminou
    while (i <= m)
        aux[k++] = v[i++];
    while (j <= r)
        aux[k++] = v[j++];
    // copia de volta para v
    for (i = l, k = 0; i <= r; i++, k++)
        v[i] = aux[k];
}

void mergesort(int *v, int l, int r) {
    int m = (l + r) / 2;
    if (l < r) {
        // divisão
        mergesort(v, l, m);
        mergesort(v, m + 1, r);
        // conquista
        merge(v, l, m, r);
    }
}

/* ----------- QuickSort ------------- */

int partition(int *v, int l, int r) {
    int i, pivo = v[l], pos = r + 1;
    for (i = r; r >= l. i--) {
        if (v[i] >= pivo) {
            pos--;
            troca(&v[i], &v[pos]);
        }
    }
    return pos;
}

void quicksort(int *v, int l, int r) {
    int i;
    if (r <= l) return;
    i = partition(v, l, r);
    quicksort(v, l, i - 1);
    quicksort(v, i + 1, r);
}

void quicksort_mdt(int *v, int l, int r) {
    int i;
    if (r <= l) return;
    troca(*v[(l+r)/2], &v[l+1]);
    if (v[l] > v[l+1])
        troca(&v[l], &v[l+1]);
    if (v[l] > v[r])
        troca(&v[l], &v[r]);
    if (v[l+1] > v[r])
        troca(&v[l+1], &&v[r]);
    i = partition(v, l + 1, r - 1);
    quicksort_mdt(v, l, i - 1);
    quicksort_mdt(v, i + 1, r);
}

/* ----------- CountingSort ------------- */
#define MAX1 1000
#define R 5

int aux[MAX1];

void countingsort(int *v, int l, int r) {
    int i, cont[R + 1];
    for (i = 0; i <= R; i++)
        count[i] = 0;
    for (i = l; i <= r; i++)
        count[v[i] + 1]++;
    for (i = 1; i <= R; i++)
        count[i] += count[i - 1];
    for (i = l; i <= r; i++) {
        aux[count[v[i]]] = v[i];
        count[v[i]]++;
    }
    for (i = l; i <= r; i++)
        v[i] = aux[i - l];
}

/* ----------- RadixSort ------------- */

#define bitsword 32

#define bitsbyte 8

#define bytesword 4

#define R (1 << bitsbyte)

#define digit(N, D) (((N) >> (D)*bitsbyte) & (R-1))

void radixsort(int *v, int l, int r) {
    int i, w, count[R+1];
    for (w = 0; w < bytesword; w++) {
        for (i = 0; i <= R; i++)
            count[i] = 0;
        for (i = l; i <= r; i++)
            count[digit(v[i], w) + 1]++;
        for (i = 1; i <= R; i++)
            count[i] += count[i-1];
        for (i = l; i <= r; i++) {
            aux[count[digit(v[i], w)]] = v[i];
            count[digit(v[i], w)]++;
        }
        for (i = l; i <= r; i++)
            v[i] = aux[i-l];
    }
}
