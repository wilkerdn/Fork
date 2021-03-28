#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
 
int main(int argc, char *argv[]) {	
	pid_t fork(void);
	
	pid_t iPid;

        printf("\nDuplicando o processo\n");
 
	iPid = fork();

	if(iPid < 0){//código executado em caso de erro
		perror(argv[0]);
		exit(errno);
	}
	if(iPid != 0){//código executado no pai
		printf("\nCodigo executado no processo pai\n");
		printf("(PAI) Processo pai   PID:|%d|\n", getpid());
		printf("(PAI) Processo filho PID:|%d|\n", iPid);
	}else{
		printf("\nCódigo executado pelo filho");
	}

	if(iPid == 0){//código executado no filho, mas disponível também no pai
		printf("\nCodigo executado no processo filho\n");
		printf("(FILHO) Processo pai   PID:|%d|\n",getppid());
		printf("(FILHO) Processo filho PID:|%d|\n",getpid());
	}else{
		printf("Código executado pelo pai\n");
	}

	printf("\nEste mensagem será impressa 2 vezes\n");//disponivel para o pai e filho
	return 0;
}

