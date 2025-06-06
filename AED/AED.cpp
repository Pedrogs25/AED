#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void AddTarefa(char tarefa[30][2][50], char titulo[20], char descricao[50], int cadastrados = 0, int escolha = 0) {
	for (int i = cadastrados; i < cadastrados + escolha; i++) {

		printf("Escreva o nome da tarefa [%i]: ", i+1);
		scanf("%s", titulo);
		printf("Escreva a descricao da tarefa [%i]: ", i+1);
		scanf("%s", descricao);

		strcpy(tarefa[i][1], titulo);
		strcpy(tarefa[i][2], descricao);

	}
}


int main() {

	char tarefa[30][2][50];
	char prioridade[3][10]{ "Baixa", "Media", "Alta" };
	char titulo[20], descricao[50];
	int escolha = 0, cadastrados = 0;

	// --------------------------------- //

	printf("- - - COMANDOS - - -\n1 - Adicionar Tarefa\n2 - Editar Tarefa\n3 - Deletar Tarefa\n4 - Ver Tarefas\n5 - Salvar\n\n");

	scanf("%i", &escolha);

	switch (escolha) {

	case 1:

		printf("Quantidade: ");
		scanf("%i", &escolha);

		if ((30 - cadastrados) < escolha) {

		}
		else {
			AddTarefa(tarefa, titulo, descricao, cadastrados, escolha);

			cadastrados += escolha;
		}
		break;
	}
}