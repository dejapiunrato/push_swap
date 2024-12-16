#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{		
		if (!check_input(argv + 1))
			error();
	}
	return (0);
}
