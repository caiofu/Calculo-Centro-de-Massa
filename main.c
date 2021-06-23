#include "stdio.h"
#include "stdlib.h"

//FUNÇÕES
void ImprimiMenu()
{
  printf("\n \n \n");
  printf("          ################## MENU ###################            \n");
  printf("          ###                                     ###            \n");
  printf("          ###     1- ADICIONAR UM NOVO CORPO      ###            \n");
  printf("          ###                                     ###            \n");
  printf("          ###     2- REMOVER UM CORPO             ###            \n");
  printf("          ###                                     ###            \n");
  printf("          ###     3- MOSTRAR MAPA                 ###            \n");
  printf("          ###                                     ###            \n");
  printf("          ###     4- SAIR                         ###            \n");
  printf("          ###                                     ###            \n");
  printf("          ###########################################            \n");
  printf("\n                ESCOLHA UMA OPCAO: ");
  
}

int main(void) {

  //Variaveis
  int opcaoMenu;
  
  system("clear"); //Para limpar a tela
  ImprimiMenu();

  scanf("%i", &opcaoMenu);

  //OPÇÕES DO MENU
    switch (opcaoMenu)
     {
       case 1:
        system("clear"); //Para limpar a tela
        printf("ADICIONANDO UM CORPO");
        scanf("%i", &opcaoMenu);
       break;

       case 2:
        system("clear"); //Para limpar a tela
         printf("REMOVENDO UM CORPO");
         scanf("%i", &opcaoMenu);
       break;

       case 3:
        system("clear"); //Para limpar a tela
        printf("MOSTRANDO O MAPA");
        scanf("%i", &opcaoMenu);

        case 4:
        system("clear"); //Para limpar a tela
         printf("SAINDO.... \n");
       break;
     }
    
  return 0;
}