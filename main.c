#include <stdio.h>
#include "TABB.h"

int main(int argc, char const *argv[])
{
    TABB* t = inicializa_arv(); 
    
    int opcao;
    char cpf[16];
    struct Reserva nova_reserva;

    do{
    	printf("---------SISTEMA DO HOTEL---------");
        printf("\n1 - Cadastrar reserva.\n");
        printf("2 - Mostrar reservas.\n");
        printf("3 - Deletar reserva.\n");
        printf("4 - Modificar reserva.\n");
        printf("5 - Pesquisar reserva.\n");
        printf("9 - Finalizar.\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: 
                t=cadastro_reserva(t);
                
            break;
        
            case 2: 
                mostrar_reservas(t);
                printf("\n");
            break;

            case 3:
                printf("CPF do titular: ");
			    scanf("%s", cpf);
			    
			    t=deletar_reserva(t,cpf);

            break;
            
            case 4:
            	
			    
			    printf("CPF do titular: ");
			    scanf("%s", cpf);
			

			    printf("Novo Nome: ");
			    scanf("%s", nova_reserva.nome);
			    printf("Novo Numero de telefone: ");
			    scanf("%s", nova_reserva.num);
			    printf("Novo Numero do quarto: ");
			    scanf("%d", &nova_reserva.num_quarto);
			    printf("Novo Valor: ");
			    scanf("%lf", &nova_reserva.valor);
			
			    t = modificar_reserva(t, cpf, nova_reserva); 
            break;
            
            case 5:
                printf("CPF do titular: ");
			    scanf("%s", cpf);
			    
			    TABB* res;
				res=buscar_reserva(t, cpf);
				
				if(res){
				
					printf("Nome: %s, CPF: %s, Numero de telefone: %s, Quarto: %d, Valor: %.2lf\n",
					res->reserva.nome, res->reserva.cpf, res->reserva.num, res->reserva.num_quarto, res->reserva.valor);
				}else{
					printf("Nao existe reserva nesse CPF!\n");
				}
            break;

            default:
                
            break;
        }

    }while(opcao!=9);

    return 0;
}


