#include "corpo.h"

//UI
void ImprimiMenu();
void MostraListaCorpos(struct corpos *corp, int qtdCorpos);

//CALCULOS
void CalculoCentroMassa(struct corpos *corp, int qtdCorpos);
float CalculaMediaMassa(struct corpos *corp, int qtdCorpos);

int MaiorPosicaoX(int posicaoX[], int qtdCorpos, int indice);
int MaiorPosicaoY(int posicaoY[], int qtdCorpos, int indice);
void MontaMapa(struct corpos *corp, int qtdCorpos);
int AgrupaImprimiCorpos(struct corpos *corp, int qtdCorpos,int maiorPosicaoX, int maiorPosicaoY, int calculoLinhaX, int calculoColunaY, int posicaoX, int posicaoY);