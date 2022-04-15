#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<fcntl.h>
#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

void sigHandler(int sig);

/* moved these variables to the global scope
 * since they need to be access/deleted/closed
 * from the signal handler
 */
FILE *fp;
const char pidfile[] = "/var/run/my-daemon.pid";

int main() {
	pid_t pid;
	time_t now;		/* for the current time */
	struct sigaction action;
	const char daemonfile[] = "/tmp/my-daemon-is-alive.txt";

	if ((pid = fork()) == -1){
		perror("can't fork");
		return (1);
	} else if ((pid != 0)) {
		exit(0);
	}

	/* the parent process has exited, which makes
	 * the rest of the child process
	 */
	setsid();	/* create a new session to lose the controlling
				 * terminal
				 */
	/* fork again, creating a grandchild, the
	 * actual daemon.
	 */
	if ((pid = fork()) == -1){
		perror("cant't fork");
		return (1);
	} else if ( pid > 0) { /* the child process which will exit */
		/* open pid-file for writing and chack it */
		if ((fp = fopen(pidfile, "w")) == NULL) {
			perror("can't open file for writing");
			return (1);
		}
		/* write pid to file */
		fprintf(fp, "%d\n", pid);
		fclose(fp);			/* close the file pointer */
		exit(0);
	}

	umask(022);				/* set the umask to something ok */
	chdir("/");				/* change working directory to / */

	/* open the "daemonfile" for writing */
	if ((fp = fopen(daemonfile, "w")) == NULL) {
		perror("can't open daemonfile");
		return (1);
	}

	/* from here, we don't need stdin, stdout or,
	 * stderr anymore, so let's close them all,
	 * then re-open them to /dev/null */
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	open("/dev/null", O_RDONLY);		/* 0 = stdin */
	open("/dev/null", O_WRONLY);		/* 1 = stdout */
	open("/dev/null", O_RDWR);			/* 2 = stderr */

	/* prepare for sigaction */
	action.sa_handler = sigHandler;
	sigfillset(&action.sa_mask);
	action.sa_flags = SA_RESTART;

	/* register the signals we want to handle */
	sigaction(SIGTERM, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGQUIT, &action, NULL);
	sigaction(SIGABRT, &action, NULL);

	/* here we start the daemons "work" */
	for(;;) {
		/* get the current time and write it to the
		 * "daemonfile" that we opened above
		 */
		time(&now);
		fprintf(fp, "Daemon alive at %s", ctime(&now));
		fflush(fp);						/* flush the strem */
		sleep(30);
	}
	return (0);
}

void sigHandler(int sig) {
	int status = 0;

	if (sig == SIGTERM || sig == SIGINT
		|| sig == SIGQUIT
		|| sig == SIGABRT)
	{
		/* remove the pid-file */
		if ((unlink(pidfile)) == -1)
			status = 1;
		if ((fclose(fp)) == EOF)
			status = 1;

		exit(status);				/* exit with the status set */
	} else {
		exit(1);
	}
}
