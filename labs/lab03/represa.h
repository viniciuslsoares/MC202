#define MAX1 1000

typedef struct{
    char nome[MAX1];
    float limite;
    int qnt_medidas;
    int medidas[MAX1];
    int nivel_medio;
    int alerta;
} Represa;

// --------- funções da struct represa --------

Represa le_represa();

void print_represa(Represa represa);

int aviso_capacidade(Represa represa);

void tratamento_dados(Represa lista[], int size);

// ----------- funções auxiliares ----------

float calculo_media(int vetor[], int size);

void letras_min(char nome[]);

void retira_pref(char nome[]);
