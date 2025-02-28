#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define FILE_NAME "frequencia.txt"

struct aluno {
	char nome [40], ra [11];
	int situacao;
};

struct aluno alunos [5];
int presenca [5];

int calculo (int i) {
	
	int cal;
	
	cal = 30 - presenca[i];
	
	if (cal <= 8) {
		alunos[i].situacao = 1; 	
	} else {
		alunos[i].situacao = 0;
	}
	
	return (cal);
}

void entrada () {
	
	int i, x;
	
	for (i = 0; i < 5; i++) {
		
		FILE *file = fopen (FILE_NAME, "a");
	
		if (file == NULL) {
			printf ("Erro ao abrir o arquivo.\n");
			return;
		}
		
		x = 0;
		printf ("Digite o nome do %iº aluno: ", i + 1);
		fflush (stdin);
		gets (alunos[i].nome);
		printf ("Digite o RA do %iº aluno: ", i + 1);
		fflush (stdin);
		scanf ("%s", &alunos[i].ra);
		printf ("Digite a quantidade de presenças do %iº aluno em relação aos 30 dias de aula.\n---> ", i + 1);
		scanf ("%i", &presenca[i]);
		
		x = calculo (i);
		
		if (alunos[i].situacao == 1) {
			fprintf (file, "Nome: %s RA: %s Presencas: %i Faltas: %i Status: 'APROVADO'\n", alunos[i].nome, alunos[i].ra, presenca[i], x);
			fclose (file);
		} else {
			fprintf (file, "Nome: %s RA: %s Presencas: %i Faltas: %i Status: 'REPROVADO'\n", alunos[i].nome, alunos[i].ra, presenca[i], x);
			fclose (file);
		}
	}
}


int main () {
	
	setlocale (LC_ALL, "portuguese");
	entrada ();
	//relatorio ();
	
	printf ("FIM. . .");
}
