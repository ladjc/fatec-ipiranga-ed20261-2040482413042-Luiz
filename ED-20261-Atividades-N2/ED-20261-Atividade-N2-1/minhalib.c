/*----------------------------------------------------------------------------------*/
/*                                FATEC-Ipiranga                                    */
/*                            ADS - Estrutura de Dados                              */
/*                             Id da Atividade: N2-1                                */
/*             Objetivo: Explorando a Anatomia da Árvore Binária                    */
/*                                                                                  */
/*                    Autor: Luiz Antonio de Jesus Cruz                             */
/*                                                                   Data:28/04/2026*/
/*----------------------------------------------------------------------------------*/
#include <stdio.h>
#include "minhalib.h"

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

// ======== Função para Plotar arvore =======
void plotar_arvore(No *raiz, char *prefixo, int eh_ultimo) {
    if (raiz == NULL) return;

    printf("%s", prefixo);

    if (prefixo[0] != '\0') {
        printf(eh_ultimo ? "\\-- " : "|-- ");
    }

    printf("%d\n", raiz->valor);

    char novo_prefixo[1000];
    sprintf(novo_prefixo, "%s%s",
            prefixo,
            eh_ultimo ? "    " : "|   ");

    int tem_esq = (raiz->esq != NULL);
    int tem_dir = (raiz->dir != NULL);

    if (tem_esq) {
        plotar_arvore(raiz->esq, novo_prefixo, !tem_dir);
    }

    if (tem_dir) {
        plotar_arvore(raiz->dir, novo_prefixo, 1);
    }
}

// ================= Função para Calcular a altura de um nó =================
int calcular_altura(No *raiz) {
    if (raiz == NULL) return -1;

    int esq = calcular_altura(raiz->esq);
    int dir = calcular_altura(raiz->dir);

    return (esq > dir ? esq : dir) + 1;
}

// ================= Função para exibir uma raiz=================
void imprimir_no_raiz(No *raiz) {
    if (raiz == NULL) {
        printf("Raiz nula!");
    } else {
        printf("Raiz: %d\n", raiz->valor);
    }
}


// ================= Imprimir os nos internos =================
void imprimir_nos_internos_rec(No *raiz) {
    if (raiz != NULL) {
        if (raiz->esq != NULL || raiz->dir != NULL) {
            printf("%d ", raiz->valor);
        }
        imprimir_nos_internos_rec(raiz->esq);
        imprimir_nos_internos_rec(raiz->dir);
    }
};

void imprimir_nos_internos(No *raiz) {
    if (raiz == NULL) return;

    printf("Nos internos: ");
    // Passa os filhos da raiz
    imprimir_nos_internos_rec(raiz->esq);
    imprimir_nos_internos_rec(raiz->dir);

    printf("\n");
}

// ================= Imprimir as Folhas =================
void imprimir_folhas_rec(No *raiz) {
    if (raiz != NULL) {
        if (raiz->esq == NULL && raiz->dir == NULL) {
            printf("%d ", raiz->valor);
        }
        imprimir_folhas_rec(raiz->esq);
        imprimir_folhas_rec(raiz->dir);
    }
};

void imprimir_folhas(No *raiz) {
    if (raiz != NULL) {
        printf("Folhas: ");
        imprimir_folhas_rec(raiz->esq);
        imprimir_folhas_rec(raiz->dir);
        printf("\n");
    }
}

// ================= Imprimir os Níveis =================
void imprimir_nivel(No *raiz, int nivel) {
    if (raiz == NULL) return;

    if (nivel == 1) {
        printf("%d ", raiz->valor);
    } else {
        imprimir_nivel(raiz->esq, nivel - 1);
        imprimir_nivel(raiz->dir, nivel - 1);
    }
}

void imprimir_niveis(No *raiz, int nivel) {
    if (raiz == NULL) return;

    int h = calcular_altura(raiz);
    h++;

    printf("Niveis:\n");

    for (int i = 1; i <= h; i++) {
        printf("Nivel %d: ", i);
        imprimir_nivel(raiz, i);
        printf("\n");
    }
}


// ================= Calcular a profundidade de um Nó =================
int calcular_profundidade(No *raiz, int valor, int profundidade_atual) {
    if (raiz == NULL)
        return -1;

    if (raiz->valor == valor)
        return profundidade_atual;

    int esq = calcular_profundidade(raiz->esq, valor, profundidade_atual + 1);
    if (esq != -1)
        return esq;

    return calcular_profundidade(raiz->dir, valor, profundidade_atual + 1);
}


// ================= Função para buscar um nó =================
No *buscar(No *raiz, int p_valor) {
    if (raiz == NULL || raiz->valor == p_valor)
        return raiz;

    No *esq = buscar(raiz->esq, p_valor);
    if (esq != NULL)
        return esq;

    return buscar(raiz->dir, p_valor);
}

// ================= Função para exibir o grau de um nó =================
void imprimir_grau(No *raiz) {
    if (raiz == NULL) {
        printf("Erro imprimir_grau\n");
    } else {
        int grau = 0;

        if (raiz->esq != NULL) {
            grau++;
        }
        if (raiz->dir != NULL) {
            grau++;
        }
        printf("Grau do No %d: %d\n", raiz->valor, grau);
    }
}


// ================= Ancestrais =================
int imprimir_ancestrais_rec(No *raiz, int valor) {
    if (raiz == NULL) return 0;

    // Se encontrou o nó alvo
    if (raiz->valor == valor) {
        return 1;
    }

    // Busca nas subárvores
    if (imprimir_ancestrais_rec(raiz->esq, valor) ||
        imprimir_ancestrais_rec(raiz->dir, valor)) {

        printf("%d ", raiz->valor);
        return 1;
        }

    return 0;
}

void imprimir_ancestrais(No *raiz, int valor) {
    printf("Ancestrais do no %d: ", valor);
    if (!imprimir_ancestrais_rec(raiz, valor)) {
        printf("Valor nao encontrado.\n");
    } else {
        printf("\n");
    }
}


// ================= Descendentes =================
void listar_descendentes(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        listar_descendentes(raiz->esq);
        listar_descendentes(raiz->dir);
    }
}

void imprimir_descendentes(No *no) {
    if (no == NULL) {
        printf("Erro imprimir_descendentes, no nao encontrado\n");
    }else {
        printf("Descendentes do no %d: ", no->valor);
        if (no->esq != NULL) {
            listar_descendentes(no->esq);
        }
        if (no->dir != NULL) {
            listar_descendentes(no->dir);
        }

        printf("\n");
    }
}

// ================= Função principal de diagnóstico da atividade =================
void analisar_arvore(No *raiz, int valorBusca) {
    if (raiz == NULL) {
        printf("No raiz vazio!\n");
    } else {
        printf("Analisando arvore:\n");
        plotar_arvore(raiz, " ", 1);

        printf("======== Diagnostico Geral da Arvore ========\n");
        imprimir_no_raiz(raiz);
        imprimir_nos_internos(raiz);
        imprimir_folhas(raiz);
        imprimir_niveis(raiz, 0);

        printf("======== Diagnostico Especifico do No %d ========\n", valorBusca);
        No *especifico = buscar(raiz, valorBusca);
        imprimir_grau(especifico);
        imprimir_ancestrais(raiz, valorBusca);
        imprimir_descendentes(especifico);
        printf("Altura do No %d: %d\n", valorBusca, calcular_altura(especifico));
        printf("Profundidade do no %d: %d \n", valorBusca, calcular_profundidade(raiz, valorBusca, 0));
        printf("Sub-arvore do no %d:\n", valorBusca);
        plotar_arvore(especifico, " ", 1);
    }
}
