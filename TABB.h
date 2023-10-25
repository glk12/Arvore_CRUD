#define TABB_H

struct Reserva {
    char nome[50];
    char cpf[16];
    char num[16];
    int num_quarto;
    double valor;
};
struct arvore {
    struct Reserva reserva;
    struct arvore* dir;
    struct arvore* esq;
};

typedef struct Reserva Reserva;
typedef struct arvore TABB;

TABB* cadastro_reserva(TABB* t);

TABB* inicializa_arv(); 

TABB* cria(struct Reserva,TABB* esq,TABB* dir);

TABB* inserir_arv(TABB* t, struct Reserva);

void mostrar_reservas(TABB* t);

TABB* modificar_reserva(TABB* t,char cpf[16],struct Reserva); 

TABB* deletar_reserva(TABB* t, char cpf[16]);

TABB* buscar_reserva(TABB* t, char cpf[16]);


