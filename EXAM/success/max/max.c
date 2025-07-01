int	max(int *tab, unsigned int len)
{
	int	number;
	int	i;

	i = 0;
	number = tab[i];
	while (i < len)
	{
		if(number < tab[i])
			number = tab[i];
		i++;
	}
	return (number);
}

/*#include <stdio.h>
int	main()
{
	int n[] = {1, 2, 3, 4, 20, 5, 6, 7, 8, 9};
	printf("%d", max(n, 8));

}*/
