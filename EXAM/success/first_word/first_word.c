#include <unistd.h>

void	first_word(char	*str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		write (1, &str[i++], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		first_word(argv[1]);
	}
	write (1, "\n", 1);
}
