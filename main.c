#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "funcoes.h"


int main(void) {

 //Corpo inicial "@"
 unsigned int qtdCorpos  = 1; //Primeira posição sempre sera o "@" (Centro da)

  corp = (Corpos*)malloc(qtdCorpos*sizeof(Corpos)); //Alocando o tamanho incial de memoria

   strcpy(corp[0].nome, "@");
          corp[0].massa = 0;
          corp[0].idCorpo = 1;
          
//VARIAVEIS DO MENU
int opcaoMenu;  
int menu = 1;

//LOOP DO MENU
while(menu == 1)
{
   printf("\n");
  //ADICIONANDO CORPOS
  if(opcaoMenu == 1)
  {
    system("clear"); //Limpa a tela
   
      qtdCorpos++;
      corp = (Corpos*)realloc(corp, qtdCorpos*sizeof(Corpos)); //Memoria sendo realocada para novo tamanho

        printf("##### ADICIONANDO UM NOVO CORPO ##### \n");
        printf("Nome: \n");
        scanf("%s", corp[qtdCorpos-1].nome );
        fflush(stdin);

        printf("Massa: \n");
        scanf("%f", &corp[qtdCorpos-1].massa );
        fflush(stdin);

        printf("Posicao X: \n");
        scanf("%d", &corp[qtdCorpos-1].posicaoX );
        fflush(stdin);

        printf("Posicao Y: \n");
        scanf("%d", &corp[qtdCorpos-1].posicaoY );
        fflush(stdin);

        //INCREMENTA O ID DO CORPO
        corp[qtdCorpos-1].idCorpo = qtdCorpos;
        
        system("clear"); //Limpa a tela
        MontaMapa(corp,qtdCorpos);
        opcaoMenu = 0;

  }

  //REMOVENDO CORPOS
  else if(opcaoMenu == 2)
  {
      int opcaoRemover;
      printf("#####  REMOVER UM CORPO ##### \n \n");

     //MOSTRANDO AS OPÇÕES PARA O USUARIO EXCLUIR
    if(qtdCorpos == 1)
    {
      printf("Não existe corpos para remover \n\n");
       printf("############################## \n \n");
      printf("Digite 0 para voltar ao menu: ");
    }
    else
    {
      MostraListaCorpos(corp, qtdCorpos);
      printf("############################## \n");
      printf("QUAL CORPO DESEJA REMOVER: ");
    }
     
    
    scanf("%d", &opcaoRemover);
    fflush(stdin);

    if(opcaoRemover != 0)
    {
      //STRUCT TEMPORARIA COM TAMANHO JA ATUALIZADO
      Corpos tempCorp[qtdCorpos - 1];

        //POPULA STRUCT TEMPORARIA
        int indiceAtual = 0;
        for(int c = 0; c < qtdCorpos; c++)
        {
          if(strcmp(corp[opcaoRemover].nome, corp[c].nome) != 0)
          {
              strcpy(tempCorp[indiceAtual].nome, corp[c].nome);
              tempCorp[indiceAtual].massa = corp[c].massa;
              tempCorp[indiceAtual].posicaoX = corp[c].posicaoX;
              tempCorp[indiceAtual].posicaoY = corp[c].posicaoY;
              indiceAtual++;
          }
        }

        //REMONTA A STRUCT ORIGINAL
        qtdCorpos--;
        corp = (Corpos*)realloc(corp, qtdCorpos*sizeof(Corpos)); //Memoria sendo realocada para novo tamanho 
        

        for(int c = 0; c < qtdCorpos; c++)
        {
          strcpy(corp[c].nome, tempCorp[c].nome);
          corp[c].massa = tempCorp[c].massa;
          corp[c].posicaoX = tempCorp[c].posicaoX;
          corp[c].posicaoY = tempCorp[c].posicaoY;
        }
    }
   

    MontaMapa(corp,qtdCorpos);
    opcaoMenu = 0; //Volta loop do menu
  }

  //MODIFICAR UM CORPO
  else if(opcaoMenu == 3)
  {
    int opcaoModificar;
     printf("##### MODIFICANDO UM CORPO ##### \n \n");
    if(qtdCorpos == 1)
    {
      printf("Não existe corpos para modificar \n\n");
       printf("############################## \n \n");
      printf("Digite 0 para voltar ao menu: ");
    }
    else
    {
      MostraListaCorpos(corp,qtdCorpos);
      printf("############################## \n");
      printf("QUAL CORPO DESEJA MODIFICAR: ");
    }
    
     scanf("%d", &opcaoModificar);
     fflush(stdin);

    if(opcaoModificar != 0)
    {
 
      system("clear"); //Limpa a tela

      //PERGUNTANDO QUAL ATRIBUTO DESEJA opcaoModificar
      int atributoSelecionado;
      printf("############################## \n");
      printf("1 - Nome: %s \n", corp[opcaoModificar].nome);
      printf("2 - Massa: %f \n", corp[opcaoModificar].massa);
      printf("3 - Posicao X: %d \n", corp[opcaoModificar].posicaoX);
      printf("4 - Posicao Y: %d \n", corp[opcaoModificar].posicaoY);
      printf("############################## \n");

      printf("QUAL ATRIBUTO DESEJA MODIFICAR ? \n \n");
      scanf("%d", &atributoSelecionado);
       fflush(stdin);

      //MODIFICA O ATRIBULO SELECIONADO 
      char novoNome[14];
      float novaMassa;
      int novaPosicaoX;
      int novaPosicaoY;

      switch(atributoSelecionado)
      {
        case 1:
          printf("NOVO NOME: \n");
          scanf("%s", novoNome);
          fflush(stdin);
          strcpy(corp[opcaoModificar].nome, novoNome);
        break;
        
        case 2:
          printf("NOVA MASSA: \n");
          scanf("%f", &novaMassa);
           fflush(stdin);
          corp[opcaoModificar].massa = novaMassa;
        break;

        case 3:
          printf("NOVA POSICAO X: \n");
          scanf("%d", &novaPosicaoX);
           fflush(stdin);
          corp[opcaoModificar].posicaoX = novaPosicaoX;
        break;

        case 4:
          printf("NOVA POSICAO Y: \n");
          scanf("%d", &novaPosicaoY);
           fflush(stdin);
          corp[opcaoModificar].posicaoY = novaPosicaoY;
        break;
      }
      MontaMapa(corp,qtdCorpos);
   }
    opcaoMenu = 0;
  }

  //SAIR
  else if(opcaoMenu == 4)
  {
    menu = 0;
  }
  else
  {  
      ImprimiMenu(); //Mostra o menu
      scanf("%i", &opcaoMenu);
      fflush(stdin);
  }
 
}
  free(corp); //LIBERANDO A MEMORIA
  
  return 0;
}