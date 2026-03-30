/*-- --- --- --- ---- --- --- --- --- --- --- ---- --- --- --- --- --- --- ---- --- --- --- --- --- --- -*/
/* FATEC - Ipiranga                                                                                      */
/* ADS - Estrutura de Dados                                                                              */
/* Id da Atividade : N1-3                                                                                */
/* Objetivo : Desenvolver uma aplicação que simule o funcionamento lógico da calculadora                 */
/* financeira HP12c, utilizando os conceitos de Estrutura de Dados de Pilha (Stack)                      */
/* para o processamento de expressões em Notação Polonesa Reversa (RPN).                                 */
/*                                                                                                       */
/* Autor : Luiz Cruz                                                                                     */
/* Data : 30/03/2026                                                                                     */
/*-- --- --- --- ---- --- --- --- --- --- --- ---- --- --- --- --- --- --- ---- --- --- --- --- --- --- -*/

// Inclusão das Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura da memoria
typedef struct {
    float t;
    float z;
    float y;
    float x;
} Memoria;

// Incialização das memorias
void inicializar(Memoria *m) {
    m->t = 0.0;
    m->z = 0.0;
    m->y = 0.0;
    m->x = 0.0;
}

// Exibe os estado da memoria
void exibir_estado_de_memoria(Memoria *m) {
    printf("--- Estado de Memoria ---\n");
    printf("X: %.3f | Display\n", m->x);
    printf("Y: %.3f\n", m->y);
    printf("Z: %.3f\n", m->z);
    printf("T: %.3f\n", m->t);
    printf("---------------------\n");
}

// Função push
void push(Memoria *m, float valor) {
    m->t = m->z;
    m->z = m->y;
    m->y = m->x;
    m->x = valor;
}

// Função para executar as operações
void calc(Memoria *m, char operacao) {

    float result = 0.0;

    switch(operacao) {
        case '+':
            result = m->y + m->x;
            break;
        case '-':
            result = m->y - m->x;
            break;
        case '*':
            result = m->y * m->x;
            break;
        case '/':
            // Testa a divisão por 0
            if (m->x == 0) {
                printf("Erro: Divisao por zero!\n");
                return;
            }
            result = m->y / m->x;
            break;
        default:
            printf("Erro: Operador invalido!\n");
            return;
    }

    // Adiciona o Resultado ao display (Memoria X)
    m->x = result;
    // Movimenta as proximas posições de memoria
    m->y = m->z;
    m->z = m->t;
}

int main() {

    Memoria hp12c;

    inicializar(&hp12c);

    char expressao[] = "5 1 2 + 4 * + 3 -";

    printf("Expressao RPN de Teste: %s\n", expressao);

    // Separando a espressao em partes pelo delimitador de espaco
    char *expressao_em_partes = strtok(expressao, " ");

    // While para percorres todas as entradas simulando o imput do usuario
    while (expressao_em_partes != NULL) {
        printf("\nEntrada: '%s'\n", expressao_em_partes);

        // Validacao se a posição atual é um digito ou caractere
        if (isdigit(expressao_em_partes[0])) {
            // Cast da String para float
            float n = atof(expressao_em_partes);
            // Empilha o valor na memoria
            push(&hp12c, n);
        } else {
            // Caso seja um operado, realiza o calculo
            calc(&hp12c, expressao_em_partes[0]);
        }

        // Exibe o estado de memoria
        exibir_estado_de_memoria(&hp12c);

        // Pega o próxima parte da expressao
        expressao_em_partes = strtok(NULL, " ");
    }

    // Mensagem final formatada conforme exigência [cite: 29, 30]
    printf("O resultado da expressão algebrica é: %.3f\n", hp12c.x);

    return 0;
}