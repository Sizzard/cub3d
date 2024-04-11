#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	max;
	int	mid;
	int	nb;

	max = 2560;
	mid = 1280;
	nb = atoi(argv[1]);
	nb = max - nb;
	printf("%d\n", nb);
}
