#include<stdio.h>
#include<unistd.h>
#include<termios.h>
#include<sys/ioctl.h>

int main() {
	struct winsize termsize;

	while (1) {
		printf("\033[1;1H\033[2J");
		ioctl(STDIN_FILENO, TIOCGWINSZ, &termsize);
		printf("Height: %d row\n",termsize.ws_row);
		printf("Width: %d columns\n", termsize.ws_col);
		printf("\033[35;5mHello!\033[0m\n");
		sleep(0.1);
	}

	return (0);
}
