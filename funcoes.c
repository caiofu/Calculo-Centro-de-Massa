
#include "stdio.h"
#include "corpo.h"
#include "mapa.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"


void ImprimiMenu()
{
  printf(" \n \n \n");
  printf("          ################## MENU ###################            \n");
  printf("          ###                                     ###            \n");
  printf("          ###     1- ADICIONAR UM NOVO CORPO      ###            \n");
  printf("          ###                                     ###            \n");
  printf("          ###     2- REMOVER UM CORPO             ###            \n");
  printf("          ###                                     ###            \n");
  printf("          ###     3- MODIFICAR UM CORPO           ###            \n");
  printf("          ###                                     ###            \n");
  printf("          ###     4- SAIR                         ###            \n");
  printf("          ###                                     ###            \n");
  printf("          ###########################################            \n");
  printf("\n                ESCOLHA UMA OPCAO: ");
}



float CalculaMediaMassa(struct corpos *corp, int qtdCorpos)
{
  float mediaMassa;

  for (int i = 1; i < qtdCorpos; i++)
  {
     mediaMassa += corp[i].massa;
  }
  mediaMassa = mediaMassa / (qtdCorpos - 1);

  return mediaMassa;
}



void MostraListaCorpos(struct corpos *corp, int qtdCorpos)
{
   for(int i = 1; i < qtdCorpos; i++)
      {
        printf("%d - %s \n \n", i, corp[i].nome);
      }
}
   
int MaiorPosicaoX(int posicaoX[], int qtdCorpos, int indice)
{
   if(qtdCorpos == 1)
   {
     return posicaoX[indice];
   }
   else 
   {
     if(posicaoX[qtdCorpos - 1] > posicaoX[indice])
     {
       return MaiorPosicaoX(posicaoX, qtdCorpos -1,  qtdCorpos -1);
     }
     else
     {
       return MaiorPosicaoX(posicaoX,  qtdCorpos -1, indice);
     }
   }
}


int MaiorPosicaoY(int posicaoY[], int qtdCorpos, int indice)
{
   if(qtdCorpos == 1)
   {
     return posicaoY[indice];
   }
   else
   { 
     if(posicaoY[qtdCorpos - 1] > posicaoY[indice])
     {
       return MaiorPosicaoY(posicaoY, qtdCorpos - 1, qtdCorpos - 1);
     }
     else
     {
       return MaiorPosicaoY(posicaoY,  qtdCorpos -1, indice);
     }
   }
}


int AgrupaImprimiCorpos(Corpos *corp, int qtdCorpos,int maiorPosicaoX, int maiorPosicaoY, int calculoLinhaX, int calculoColunaY, int posicaoX, int posicaoY)
{
  int  retorno;
  int  contAgrupamento;

    //(FAZ O CALCULO DE AJUSTE DE PROPORÇAO SE FOR MAIOR QUE  A ALTURA OU LARGURA DO MAPA E MAIOR QUE O PASSO)
    int cordenadaX, cordenadaY, arrobaX, arrobaY, contaArroba = 0;
    for(int i = 0; i < qtdCorpos; i++)
    {
      
      //PEGANDO A CORDENADA EM X
       if(maiorPosicaoX > LARGURA)
        {
            if(calculoLinhaX > 0 && corp[i].posicaoX > calculoLinhaX)
            {
              cordenadaX = (corp[i].posicaoX / calculoLinhaX); 
              arrobaX = (corp[0].posicaoX / calculoLinhaX);
            }
        }
        else
        {
            cordenadaX = corp[i].posicaoX;
            arrobaX = corp[0].posicaoX;
        }
        
      
        //PEGANDO A CORDENADA EM Y
        if(maiorPosicaoY > ALTURA)
        {
          if(calculoColunaY > 0 && corp[i].posicaoY > calculoColunaY)
          {
            cordenadaY = (corp[i].posicaoY / calculoColunaY);
            arrobaY = (corp[0].posicaoY / calculoColunaY);
          }
        }
        
        else
        {
          cordenadaY = corp[i].posicaoY;
          arrobaY = corp[0].posicaoY;
         
        }
        
        //ARROBA
        if(posicaoX == cordenadaX && posicaoY == cordenadaY)
        {
          if(arrobaX == posicaoX && arrobaY == posicaoY && strcmp(corp[i].nome, "@") == 0)
          {
              printf("@(%d,%d) ", corp[i].posicaoX, corp[i].posicaoY);
          }

        //DEMAIS POSIÇÕES
          if(posicaoX != arrobaX && posicaoX == cordenadaX && posicaoY == cordenadaY)
          {
           printf("%c(",corp[i].charMedia);

            if(contAgrupamento != 1)
            {
                for(int v=0; v < qtdCorpos; v++)
                {
                  if(corp[i].posicaoX == corp[v].posicaoX && corp[i].posicaoY == corp[v].posicaoY)
                  {                  
                      printf("%s,", corp[v].nome); 
                  }

                  //TESTE PARA QUANDO A POSIÇÃO FOR MENOR QUE O PASSO (CALCULO DE LINHA OU COLUNA)
                  if(corp[i].posicaoX < calculoLinhaX && corp[v].posicaoX < calculoLinhaX && corp[i].posicaoY < calculoColunaY &&corp[v].posicaoY < calculoColunaY )
                  {                  
                      printf("%s,", corp[v].nome); 
                  }
               
                }
                contAgrupamento = 1;
              
            }
            else
            {
                printf("%s,", corp[i].nome);             
            }
              printf(")");             
          }
        }
        else
        {
          retorno = 2;
        }
    }
    return retorno;
}


// #################################
void MontaMapa(struct corpos *corp, int qtdCorpos)
{
  int matrizMapa[LARGURA][ALTURA];
  int calculoLinhaX = 0, calculoColunaY = 0;
  int maiorPosicaoX, maiorPosicaoY;
  int vetorPosicoesX[qtdCorpos-1], vetorPosicoesY[qtdCorpos-1];
  float mediaMassas;
  system("clear");
  

    //CENTRO DA MASSA
    	int calculoPosicaoX = 0;
	    int calculoPosicaoY = 0;
      float somaMassa = 0;
      int posicaoX = 0;
      int posicaoY = 0;


    //CALCULA O CENTRO DE MASSA
     for (int i = 1; i < qtdCorpos; i++)
    {
      //MULTIPLICAÇÃO E SOMA DAS MASSAS E POSIÇÕES
      calculoPosicaoX += corp[i].massa * corp[i].posicaoX;
      
      calculoPosicaoY += corp[i].massa * corp[i].posicaoY;
      
      //SOMA DAS MASSAS
      somaMassa += corp[i].massa;
    }
    
      posicaoX = calculoPosicaoX / somaMassa;
      posicaoY = calculoPosicaoY / somaMassa; 

      corp[0].massa = 0;
      corp[0].posicaoX = posicaoX;
      corp[0].posicaoY = posicaoY;
  

    //MEDIA DAS MASSAS
    mediaMassas = CalculaMediaMassa(corp, qtdCorpos);

       //VERIFICANDO E ATRIBUINO O CARACTER X NOS CORPOS 
        //(x - para abaixo da media) e (X para acima da media)

        for(int i = 1; i < qtdCorpos; i++)
        {
            if(corp[i].massa <= mediaMassas)
            {
              
              corp[i].charMedia = 'x';
            }
            else
            {
              corp[i].charMedia = 'X';
            }
        }

    //POPULANDO A MATRIZ PARA NAO SER PREENCHIDA COM LIXO DE MEMORIA
    for(int i = 0; i < LARGURA; i++)
    {
      for(int o = 0; o < ALTURA; o++)
      {
        matrizMapa[i][o] = 0;
      }
    }
//---------------------------------------------------------------------------
    //ALIMENTANDO O VETOR COM AS POSIÇÕES X PRESENTE NA STRUTURA Corpos
     for(int i = 1; i < qtdCorpos; i++)
     {
       vetorPosicoesX[i] = corp[i].posicaoX;
     }
     
    //ALIMENTANDO O VETOR COM AS POSIÇÕES Y PRESENTE NA STRUTURA Corpos
    for(int i = 1; i < qtdCorpos; i++)
     {
       vetorPosicoesY[i] = corp[i].posicaoY;
     }
    
    //PEGANDO A MAIOR POSIÇÃO EM X E Y
     maiorPosicaoX = MaiorPosicaoX(vetorPosicoesX, qtdCorpos, 1);
     maiorPosicaoY =  MaiorPosicaoY(vetorPosicoesY, qtdCorpos, 1);


    //VERIFICA SE POSIÇÕES SAO MAIORES QUE O PADRAO
    //ceil - usamos para arrendondar para cima o calculo
    //e a LARGURAPARACALCULO usamos um valor float para da certo o arredondamento

    if(maiorPosicaoX > LARGURA)
    {
      calculoLinhaX = ceil(maiorPosicaoX / LARGURAPARACALCULO);  
    }
    
    if(maiorPosicaoY > ALTURA)
    {
      calculoColunaY = ceil(maiorPosicaoY / ALTURAPARACALCULO);
    }
 



  //IMPRESSAO DO MAPA
  int retorno;
  for(int i = ALTURA; i >= 0; i--)
      {
      for(int o = 0; o < LARGURA; o++)
        {
        
        retorno = AgrupaImprimiCorpos(corp, qtdCorpos,maiorPosicaoX, maiorPosicaoY, calculoLinhaX, calculoColunaY, o, i);
          if(retorno == 2)
          {
           printf(" ");
          }
        }
        printf("\n");
      }
}