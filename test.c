#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char letter)
{
    write(1, &letter, 1);
}

int		length_itr(int n)
{
	int out;

	out = 0;
	while (n > 0)
	{
		n = n / 10;
		out++;
	}
	return (out);
}

void	ft_put_positive(int nb)
{
	if (nb != 0)
	{
		ft_put_positive(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		ft_putchar('0');
	}
	else if (nb > 0)
	{
		ft_put_positive(nb);
	}
}

void	printf_d(int n, int space)
{
	int i;
	int length;

	length = length_itr(n);

	i = length;
	while (i < space)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putnbr(n);
}

// 10101111011
// |
// 10111101011
// 10111111011


// 10101111011
// &
// 10111101011
// 10101101011



// 10101111011
// ||
// 10111101011
// 1


// 10101111011
// &&
// 00000000000
// 00000000000

int main()
{
	int n = 12345;
	int a1 = 5;
	int a2 = 11;
	int a = a1 | a2;
	int b = a1 + a2;
	printf("%d\n", a);
	printf("%d\n", b);
	// printf_d(n, 4);
	// printf("%5d", n);
	// n = length_itr(n, 1);
	// printf("%4d", n);
}