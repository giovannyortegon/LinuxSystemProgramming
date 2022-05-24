#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <getopt.h>
#include <string.h>
#include <linux/limits.h>

void printUsage(char progname[], FILE *fp);

int main(int argc, char * argv[]) {
	FILE * fp;
	FILE * procfp;
	int pid, opt;
	int killit = 0;
	char procpath[PATH_MAX] = {0};
	char cmdline[PATH_MAX] = {0};
	const char pidfile[] = "/var/run/my-daemon.pid";
	const char daemonPath[] = "/usr/local/sbin/my-daemon-v2";

	/* Parse command-line options */
	while ((opt = getopt(argc, argv, "kh")) != -1) {
		switch (opt) {
			case 'k':	/* kill the daemon */
				killit = 1;
				break;
			case 'h':	/* help */
				printUsage(argv[0], stdout);
				return 0;
			default:	/* in case of invalid options */
				printUsage(argv[0], stderr);
				return 1;
		}
	}

	if ((fp = fopen(pidfile, "r")) == NULL) {
		perror("Can't open PID-file (daemon isn't running?)");
	}

	/* read the pid (and check if we could read an integer) */
	if ((fscanf(fp, "%d", &pid)) != 1) {
		fprintf(stderr, "Can't read PID from %s\n", pidfile);
		return (1);
	}

	/* build the /proc/ path */
	sprintf(procpath, "/proc/%d/cmdline", pid);

	/* open the /proc/ path */
	if ((procfp = fopen(procpath, "r")) == NULL) {
		perror("Can't open /proc path (no /proc or wrong PID?)");
		return (1);
	}

	/* read the cmd line path from proc */
	fscanf(procfp, "%s", cmdline);

	/* check that the PID matches the cmdline */
	if ((strncmp(cmdline, daemonPath, PATH_MAX)) != 0) {
		fprintf(stderr, "PID %d doesn't belong to %s\n",
				pid, daemonPath);
		return (1);
	}

	if (killit == 1) {
		if ((kill(pid, SIGTERM)) == 0){
			printf("Successfully terminated my-daemon-v2\n");
		} else {
			perror("Couldn't terminate my-daemon-v2");
			return 1;
		}
	} else {
		printf("The daemon is running with PID %d\n", pid);
	}

	return (0);
}

void printUsage(char progname[], FILE *fp) {
	fprintf(fp, "Usage: %s [-k] [-h]\n", progname);
	fprintf(fp, "If no options are given, a status message is "
				"displayed.\n"
				"\t-k will terminate the daemon.\n"
				"\t-h will display this usage help.\n");
}
