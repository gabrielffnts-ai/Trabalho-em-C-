#ifndef CONTATOS_H
#define CONTATOS_H

#define MAX_CONTATOS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    char telefone[20];
    char email[50];
} Contato;


void cadastrar(Contato *lista, int *total);
void listar(Contato *lista, int total);
void buscar(Contato *lista, int total);
void editar(Contato *lista, int total);
void excluir(Contato *lista, int *total);


int contarNomesLongos(Contato *lista, int total, int limite);

#endif

#include <stdio.h>
#include <string.h>



void limparBuffer(char *str) {
    str[strcspn(str, "\n")] = 0;
}

void cadastrar(Contato *lista, int *total) {
    if (*total >= MAX_CONTATOS) {
        printf("Erro: Agenda lotada!\n");
        return;
    }
    
    printf("Nome: ");
    getchar(); 
    fgets(lista[*total].nome, MAX_NOME, stdin);
    limparBuffer(lista[*total].nome);
    
    printf("Telefone: ");
    fgets(lista[*total].telefone, 20, stdin);
    limparBuffer(lista[*total].telefone);
    
    printf("E-mail: ");
    fgets(lista[*total].email, 50, stdin);
    limparBuffer(lista[*total].email);
    
    (*total)++; 
    printf("Sucesso!\n");
}

void listar(Contato *lista, int total) {
    for (int i = 0; i < total; i++) {
        printf("[%d] %s | %s | %s\n", i, lista[i].nome, lista[i].telefone, lista[i].email);
    }
}

int contarNomesLongos(Contato *lista, int total, int limite) {
    if (total == 0) return 0; // Caso Base
    
    int atual = (strlen(lista[total - 1].nome) > limite) ? 1 : 0;
    return atual + contarNomesLongos(lista, total - 1, limite); 
}



int main() {
    Contato agenda[MAX_CONTATOS];
    int totalContatos = 0;
    int opcao;

    do {
        printf("\n--- GERENCIADOR DE CONTATOS ---\n");
        printf("1. Cadastrar\n2. Listar\n3. Estatisticas\n4. Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadastrar(agenda, &totalContatos); break;
            case 2: listar(agenda, totalContatos); break;
            case 3: 
                printf("Nomes com mais de 5 letras: %d\n", 
                        contarNomesLongos(agenda, totalContatos, 5)); 
                break;
        }
    } while (opcao != 7);

    return 0;
}
