#include "get_next_line.h"

int	ft_strlen(const	char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char	*src)
{
	int		i;
	char	*p;

	i = 0;
	while (src[i])
		i++;
	p = (char *)malloc(i + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		i;
	int		j;
	char	*out;

	size = ft_strlen(s1) + ft_strlen(s2);
	out = malloc (sizeof(char) * (size + 1));
	out[size] = '\0';
	if (out == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i < ft_strlen(s1))
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j] && j < ft_strlen(s2))
	{
		out[i] = s2[j];
		i++;
		j++;
	}
	return (out);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*p;
	size_t	i;
	size_t	end;

	if (len > (size_t)ft_strlen (s))
		len = (size_t)ft_strlen (s);
	if (start > (size_t)ft_strlen(s))
		return (ft_strdup(""));
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = start;
	end = 0;
	str = (char *)s;
	while (str[start] && (end < len))
		p[end++] = str[start++];
	p[end] = '\0';
	return (p);
}

