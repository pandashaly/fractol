/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:10:40 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/30 13:50:12 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*strjoin allocates some memory and makes a new str
 * from the concatenation of s1 and s2*/

#include "libft.h"

static size_t	ft_getslen(const char *str)
{
	if (str)
		return (ft_strlen(str));
	else
		return (0);
}

char	*ft_strjoin(const char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	s1_len = ft_getslen(s1);
	s2_len = ft_getslen(s2);
	new_str = (char *)malloc(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

/*int	main(void)
{
	char	*s1 = "tripouille";
	char	*s2 = "42";
	char	*result = ft_strjoin(s1, s2);
	printf("Test1: Expected: 
	tripouille42, Actual: %s\n", result);
	free(result);

	char	*s3 = "42";
	char	*s4 = "";
	char	*result2 = ft_strjoin(s3, s4);
	printf("Test2: Expected: 42, Actual: %s\n", result2);
	free(result2);

	return (0);
}

int main(void) 
{
    // Test Case 1
    char *s1 = "tripouille";
    char *s2 = "42";
    char *result1 = ft_strjoin(s1, s2);
    printf("Test Case 1: %s\n", 
	(strcmp(result1, "tripouille42") == 0) ? "Pass" : "Fail");
    free(result1);

    // Test Case 5
    char *s3 = "42";
    char *s4 = "";
    char *result2 = ft_strjoin(s3, s4);
    printf("Test Case 5: %s\n", 
	(strcmp(result2, "42") == 0) ? "Pass" : "Fail");
    free(result2);

    return 0;
}*/
