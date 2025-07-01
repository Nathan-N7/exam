#include <stdlib.h>

int	count(int	n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int	i;
	char	*str;

	i = count(nbr);
	str = (char *)malloc((i + 1) * sizeof(char));
	str[i] = '\0';
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			str[i - 1] = '8';
			nbr = -214748364;
			i--;
		}
		str[0] = '-';
		nbr *= -1;
		while (--i > 0)
		{
			str[i] = (nbr % 10) + '0';
			nbr /= 10;
		}
		return (str);
	}
	while (--i >= 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

/*#include <stdio.h>
int	main()
{
	printf("%s", ft_itoa(-2147483648));
}*/
