#include "fractol.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
		write(fd, str++, 1);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	
	if (!s1 || !s2 || n <= 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
        if (s1[i] != s2[i])
        	return (s1[i] - s2[i]);
        i++;
    }
	return (0);
}

double	atod(char *str)
{
	long	first_part;
	double	second_part;
	double	power;
	int		sign;

	first_part = 0;
	second_part = 0;
	power = 1;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
		first_part = (first_part * 10) + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		power /= 10;
		second_part = second_part + (*str++ - '0') * power;
	}
	return ((first_part + second_part) * sign);
}
