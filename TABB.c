#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TABB.h"


TABB* inicializa_arv() {
    return NULL;
}

TABB* cria(struct Reserva r, TABB* esq, TABB* dir) {
    TABB* a = (TABB*)malloc(sizeof(TABB));
    a->reserva = r;
    a->esq = esq;
    a->dir = dir;
    return a;
}

TABB* inserir_arv(TABB* t, struct Reserva r) {
    if (!t) return cria(r, NULL, NULL);
    
    int cmp = strcmp(r.cpf, t->reserva.cpf);
    if (cmp < 0)
        t->esq = inserir_arv(t->esq, r);
    else if (cmp > 0)
        t->dir = inserir_arv(t->dir, r);
    return t;
}

TABB* menor_it(TABB* t){

	TABB* resp = t;
	while(resp->esq)
		resp = resp->esq;
	return resp;
}

TABB* cadastro_reserva(TABB* t) {
    struct Reserva r;
    printf("Nome: ");
    scanf("%s", r.nome);
    printf("CPF: ");
    scanf("%s", r.cpf);
    printf("Numero de telefone: ");
    scanf("%s", r.num);
    printf("Numero do quarto: ");
    scanf("%d", &r.num_quarto);
    printf("Valor: ");
    scanf("%lf", &r.valor);
    t = inserir_arv(t, r);
    return t;
}

void mostrar_reservas(TABB* t) {
	if (t == NULL) {
        return; 
    } 
    mostrar_reservas(t->esq);
    printf("Nome: %s, CPF: %s, Numero de telefone: %s, Quarto: %d, Valor: %.2lf\n",
    t->reserva.nome, t->reserva.cpf, t->reserva.num, t->reserva.num_quarto, t->reserva.valor);
    mostrar_reservas(t->dir);
    
}

TABB* deletar_reserva(TABB* t, char cpf[16]) {
    if (t == NULL) {
    	printf("Nao existe uma reserva nesse CPF!\n");
        return t;
    }
	int cmp = strcmp(cpf, t->reserva.cpf);
    if (cmp<0) {
        t->esq = deletar_reserva(t->esq, cpf);
    } else if (cmp>0) {
        t->dir = deletar_reserva(t->dir, cpf);
    } else {
        if (t->esq == NULL) {
            TABB* temp = t->dir;
            free(t);
            return temp;
        } else if (t->dir == NULL) {
            TABB* temp = t->esq;
            free(t);
            return temp;
        }

        TABB* temp = menor_it(t->dir);
        t->reserva = temp->reserva;
        t->dir = deletar_reserva(t->dir, temp->reserva.cpf);
    }
    return t;
}

TABB* buscar_reserva(TABB* t, char cpf[16]) {
	if (t == NULL) {
        
        return NULL;
    }
    int cmp = strcmp(cpf, t->reserva.cpf);
    if (cmp < 0) {
        return buscar_reserva(t->esq, cpf);
    } else if (cmp>0) {
        return buscar_reserva(t->dir, cpf);
    } else {
        return t;
    }
}


TABB* modificar_reserva(TABB* t,char cpf[16], struct Reserva nova_reserva) {
    if (t == NULL) {
        return t;
    }

    int cmp = strcmp(cpf, t->reserva.cpf);
    if (cmp < 0) {
        t->esq = modificar_reserva(t->esq, cpf, nova_reserva);
    } else if (cmp > 0) {
        t->dir = modificar_reserva(t->dir, cpf, nova_reserva);
    } else {
        strcpy(t->reserva.nome, nova_reserva.nome);
        strcpy(t->reserva.num, nova_reserva.num);
        t->reserva.num_quarto = nova_reserva.num_quarto;
        t->reserva.valor = nova_reserva.valor;
    }
    
    return t;
}







