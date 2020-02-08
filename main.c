#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char letter)
{
    write(1, &letter, 1);
}

int     length_itr(int n)
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

void    ft_put_positive(int nb)
{
    if (nb != 0)
    {
        ft_put_positive(nb / 10);
        ft_putchar(nb % 10 + '0');
    }
}

void    ft_putnbr(int nb)
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

void    printf_d(int n, int space)
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

void    show(int *x)
{
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++)
        {
            if (j == 0)
            {
                printf_d(*x++, 1);
            }
            else
            {
                printf_d(*x++, 2);
            }
        }
        ft_putchar('\n');
    }
}

int     trycell(int *x, int pos)
{
    int row = pos / 9;
    int col = pos % 9;
    int i, j, used = 0;

    if (pos == 81)
    {
        return 1;
    }
    if (x[pos])
    {
        return trycell(x, pos + 1);
    }

    for (i = 0; i < 9; i++)
    {
        used |= 1 << (x[i * 9 + col] - 1);
    }

    for (j = 0; j < 9; j++)
    {
        used |= 1 << (x[row * 9 + j] - 1);
    }

    row = row / 3 * 3;
    col = col / 3 * 3;
    for (i = row; i < row + 3; i++)
    {
        for (j = col; j < col + 3; j++)
        {
            used |= 1 << (x[i * 9 + j] - 1);
        }
    }

    for (x[pos] = 1; x[pos] <= 9; x[pos]++, used >>= 1)
    {
        if (!(used & 1) && trycell(x, pos + 1)) return 1;
    }

    x[pos] = 0;
    return 0;
}
 
void    solve(const char *s)
{
    int i, x[81];
    for (i = 0; i < 81; i++)
    {
        // x[i] = s[i] >= '1' && s[i] <= '9' ? s[i] - '0' : 0;
        if (s[i] >= '1' && s[i] <= '9')
        {
            x[i] = s[i] - '0';
        }
        else
        {
            x[i] = 0;
        }
    }

    if (trycell(x, 0))
    {
        show(x);
    }
    else
    {
        puts("no solution");
    }
}
 
int     main(void)
{
  solve(  "........."
        "........."
        ".98....6."
        "8...6...3"
        "4..8.3..1"
        "7...2...6"
        ".6....28."
        "...419..5"
        "....8..79" );
 
  return 0;
}