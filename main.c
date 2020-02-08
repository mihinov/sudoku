#include <unistd.h>

void    ft_putchar(char letter)
{
    write(1, &letter, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
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
    int i;
    int j;

    i = 0;
    j = 0;
    while (i++ < 9) {
        j = 0;
        while (j < 9)
        {
            if (j == 0)
            {
                printf_d(*x++, 1);
            }
            else
            {
                printf_d(*x++, 2);
            }
            j++;
        }
        ft_putchar('\n');
    }
}

void     calc_used(int *x, int *row, int *col, int *used)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 9)
        *used |= 1 << (x[i++ * 9 + *col] - 1);
    while (j < 9)
        *used |= 1 << (x[*row * 9 + j++] - 1);
    *row = *row / 3 * 3;
    *col = *col / 3 * 3;
    i = *row;
    while (i < *row + 3)
    {
        j = *col;
        while (j < *col + 3)
            *used |= 1 << (x[i * 9 + j++] - 1);
        i++;
    }
}

int     trycell(int *x, int pos)
{
    int row;
    int col;
    int i;
    int j;
    int used;

    row = pos / 9;
    col = pos % 9;
    i = 0;
    j = 0;
    used = 0;

    if (pos == 81)
        return (1);
    if (x[pos])
        return (trycell(x, pos + 1));
    calc_used(x, &row, &col, &used);

    x[pos] = 1;
    while (x[pos] <= 9)
    {
        if (!(used & 1) && trycell(x, pos + 1)) return 1;
        used >>= 1;
        x[pos]++;
    }
    x[pos] = 0;
    return (0);
}
 
void    solve(const char *s)
{
    int i;
    int x[81];

    i = 0;
    while (i < 81)
    {
        if (s[i] >= '1' && s[i] <= '9')
            x[i] = s[i] - '0';
        else if (s[i] == '.')
            x[i] = 0;
        else
        {
            ft_putstr("no solution");
            return ;
        }
        i++;
    }

    if (trycell(x, 0))
        show(x);
    else
        ft_putstr("no solution");   
}
 
int     main(void)
{
  solve(  "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68."
".9..5.741" "47......." );
 
  return (0);
}