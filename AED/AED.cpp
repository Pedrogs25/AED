#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void AddTarefa(char tarefa[30][2][50], char titulo[20], char descricao[50], int cadastrados, int escolha) {
	for (int i = cadastrados; i < cadastrados + escolha; i++) {

		printf("Escreva o nome da tarefa [%i]: ", i + 1);
		scanf("%s", titulo);
		printf("Escreva a descricao da tarefa [%i]: ", i + 1);
		scanf("%s", descricao);

		strcpy(tarefa[i][0], titulo);
		strcpy(tarefa[i][1], descricao);
	}
}

void EditTarefa(char tarefa[30][2][50], int indice) {
	printf("Tarefa escolhida: %s", tarefa[indice][0]);

	printf("\nNovo titulo: ");
	scanf("%s", tarefa[indice][0]);
	printf("Nova descricao: ");
	scanf("%s", tarefa[indice][1]);
}

void DeleteTarefa(char tarefa[30][2][50], int indice, int cadastrados) {
	int confirma;
	printf("Tem certeza? (0/1) ");
	scanf("%i", &confirma);

	if (confirma == 0) {

		for (int i = indice+1; i < cadastrados+1; i++) {

			strcpy(tarefa[i-1][1], tarefa[i][1]);
			strcpy(tarefa[i-1][0], tarefa[i][0]);

		}

		cadastrados = cadastrados - 1;
		printf("Tarefa deletada.\n");

	}

}

void VerTarefas(char tarefa[30][2][50], int cadastrados) {
	for (int i = 0; i < cadastrados; i++) {
		printf("[%i] %s", i + 1, tarefa[i][0]);
		printf("\n - Descricao -\n%s\n", tarefa[i][1]);
	}
}

int main() {

	char tarefa[30][2][50];
	char titulo[20], descricao[50];
	int escolha = 0, cadastrados = 0, indice = 0;

	// --------------------------------- //


	while (escolha != -1) {

		printf("- - - COMANDOS - - -\n1 - Adicionar Tarefa\n2 - Editar Tarefa\n3 - Deletar Tarefa\n4 - Ver Tarefas\n5 - Salvar\n-1 - Parar\n\n");

		scanf("%i", &escolha);

		switch (escolha) {

		case 1:
			printf("Quantidade: ");
			scanf("%i", &escolha);

			if ((30 - cadastrados) < escolha) {
				printf("Limite de apenas 30 tarefas!\n");
			}
			else {

				AddTarefa(tarefa, titulo, descricao, cadastrados, escolha);
				cadastrados += escolha;

			}
			break;

		case 2:
			printf("Posicao: ");
			scanf("%i", &indice);

			EditTarefa(tarefa, indice-1);
			break;

		case 3:
			printf("Posicao: ");
			scanf("%i", &indice);

			DeleteTarefa(tarefa, indice-1, cadastrados-1);
			break;

		case 4:
			VerTarefas(tarefa, cadastrados-1);
			break;
		}

	}
}