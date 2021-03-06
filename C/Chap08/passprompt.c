#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<termios.h>

int main() {
	char mypass[] = "super-secret";
	char buffer[80];
	struct  termios term;

	/* get the current setting */
	tcgetattr(STDIN_FILENO, &term);
	/* disamble echoing */
	term.c_lflag = term.c_lflag & ~ECHO;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

	printf("Enter password: ");
	scanf("%s", buffer);

	if ((strcmp(mypass, buffer)) == 0) {
		printf("\nCorrect password,  Welcome!\n");
	} else {
		printf("\nIncorrect password, go away!\n");
	}

	/* re-enable echoing */
	term.c_lflag = term.c_lflag | ECHO;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

	return (0);
}
