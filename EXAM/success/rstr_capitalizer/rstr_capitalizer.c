#include <unistd.h>
int	ftlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return(i);
}

void	rstr_capitalizer(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			str[i] -= 32;
		else if ((str[i] >= 'A' && str[i] <= 'Z') && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			str[i] += 32;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	if (argc > 1)
	{
		while (i < argc)
		{
			rstr_capitalizer(argv[i]);
			write (1, "\n", 1);
			i++;
		}
	}
	else
		write (1, "\n", 1);
}
