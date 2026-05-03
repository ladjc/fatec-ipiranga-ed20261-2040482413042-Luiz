/*----------------------------------------------------------------------------------*/
/*                                FATEC-Ipiranga                                    */
/*                            ADS - Estrutura de Dados                              */
/*                             Id da Atividade: N2-1                                */
/*             Objetivo: Explorando a Anatomia da Árvore Binária                    */
/*                                                                                  */
/*                    Autor: Luiz Antonio de Jesus Cruz                             */
/*                                                                   Data:28/04/2026*/
/*----------------------------------------------------------------------------------*/

#ifndef ARVORE_BINARIA_MINHALIB_H
#define ARVORE_BINARIA_MINHALIB_H

// Forward declaration (oculta a estrutura no .c)
typedef struct No No;

// Função principal de diagnóstico da atividade
void analisar_arvore(No* raiz, int valorBusca);

// Funções auxiliares obrigatórias para organização
void imprimir_nos_internos(No* raiz);
void imprimir_folhas(No* raiz);
void imprimir_niveis(No* raiz, int nivel_atual);
int calcular_altura(No* no);
int calcular_profundidade(No* raiz, int valor, int profundidade_atual);

void imprimir_ancestrais(No* raiz, int valor);
void imprimir_descendentes(No* no);


#endif //ARVORE_BINARIA_MINHALIB_H
