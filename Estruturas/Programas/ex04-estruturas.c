#include <stdio.h>
#include <string.h>

/* estrutura para representar um processador: frequência e fabricante. */

struct processador {
	float frequencia;
	char fabricante[21];
};

/* estrutura para representar um monitor: tamanho, tipo (LCD, CRT, Plasma, Led)
 * e fabricante. */

struct monitor {
	int tamanho;
	char tipo[11];
	char fabricante[21];
};  
 
/* estrutura para representar um computador: processador, monitor, capacidade de
 * disco rígido e memória RAM. */
 
 struct computador {
 	struct processador proc;
 	struct monitor tela;
 	int capacidade_hd;
 	int ram;
 };
 
/* O programa deve cadastrar n computadores e depois listar os dados daqueles
 * computadores com processador com frequência superior 2 GHz, com monitor maior 
 * que 17” e capacidade de memória RAM maior ou igual a 4 GB. */
 
 int main()
 {
 	const char * nome_tipo[] = { "LCD", "CRT", "Plasma", "Led" };
 	int n, i, tipo_monitor;
 	printf("Informe a quantidade de computadores: ");
 	scanf("%d", &n);
 	struct computador c[n];
 	printf("Informe os dados dos %d computadores\n", n);
 	for (i = 0; i < n; i++) {
 		printf("\n%do. computator\n", i + 1);
		printf("Frequencia do processador: ");
		scanf("%f", &c[i].proc.frequencia);
		printf("Fabricante do processador: ");		
		scanf(" %20[^\n]", c[i].proc.fabricante);
		printf("Tamanho do monitor: ");
		scanf("%d", &c[i].tela.tamanho);
		printf("Tipo do monitor (0-LCD, 1-CRT, 2-Plasma, 3-Led): ");
		scanf("%d", &tipo_monitor);
		while (tipo_monitor < 0 || tipo_monitor > 3) {
			printf("Erro: tipo invalido!\n");
			printf("Tipo do monitor (0-LCD, 1-CRT, 2-Plasma, 3-Led): ");
			scanf("%d", &tipo_monitor);		
		}
		strcpy(c[i].tela.tipo, nome_tipo[tipo_monitor]);
		printf("Fabricante do monitor: ");
		scanf(" %20[^\n]", c[i].tela.fabricante);
		printf("Capacidade de disco rigido (GB): ");
		scanf("%d", &c[i].capacidade_hd);
		printf("Memoria RAM (GB): ");
		scanf("%d", &c[i].ram);
 	}
 	printf("\nComputadores com frequencia maior que 2GHz, monitor maior que 17\" e RAM maior ou igual a 4 GB\n");
 	printf("-------------------------------------------------------------------------------\n");
 	printf("         Processador        |             Monitor              |   HD   |  RAM\n");
 	printf("Frequencia | Fabricante     | Tamanho| Tipo | Fabricante       |        |\n");
 	printf("-------------------------------------------------------------------------------\n");
 	for (i = 0; i < n; i++) {
 		if (c[i].proc.frequencia > 2 && c[i].tela.tamanho > 17 && c[i].ram >= 4) {
 			printf("%5.2f GHz  | %-15.15s|  %2d\"   |%-6.6s| %-17.17s|%4d GB | %2d GB\n",
 			      c[i].proc.frequencia, c[i].proc.fabricante, c[i].tela.tamanho, 
 			      c[i].tela.tipo, c[i].tela.fabricante, 
 			      c[i].capacidade_hd, c[i].ram);
 		}
 	}
  	printf("-------------------------------------------------------------------------------\n");
	return 0;
}
