#include <unistd.h>
#include <stdarg.h>


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		count++;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	if (n < 10)
	{
		ft_putchar(n + 48);
		count++;
	}
	return (count);
}

int	puthex(unsigned int n)
{
	int	i;
	char *base;

	i = 0;
	base = "0123456789abcdef";
	if (n > 15)
	{
		i += puthex(n / 16);
		i += puthex(n % 16);
	}
	else
	{
		ft_putchar(base[n]);
		i++;
	}
	return (i);
}

int	ft_putstr(char *str)
{
	int i;
	int	count;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	count  = ft_strlen(str);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_printf(char *str, ...)
{
	va_list ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);

	while(str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'd')
		{
			count += ft_putnbr(va_arg(ap, int));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			count += ft_putstr(va_arg(ap, char *));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 'x')
		{
			count += puthex(va_arg(ap, unsigned int));
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

/*int	main()
{
	ft_printf("\n%d\n", ft_printf("%d", -2147483648));
}*/
