#include <libc.h>
int main(int ac, char **av, char **env)
{
		char *en[] = {"ls", "-la", NULL};
		execve("/bin/ls", en, NULL);
	return 0;
}
