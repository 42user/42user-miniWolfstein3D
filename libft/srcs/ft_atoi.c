#include "libft.h"

int	is_sign(const char *str)
{
	int	res;

	res = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			res -= 2;
		str++;
		if (*str == '+' || *str == '-')
			return (0);
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	intmax;

	result = 0;
	intmax = 2147483647;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sign = is_sign(str);
	if (sign == 0)
		return (-1);
	if (sign == -1)
		str++;
	while (*str <= '9' && *str >= '0')
	{
		if (!((intmax - result * 10) < (*str - 48)))
			result = (result * 10) + (*str++ - 48);
		else
			return (-1);
	}
	return (result * sign);
}
