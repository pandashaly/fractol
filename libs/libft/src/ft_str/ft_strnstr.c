/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:40:13 by ssottori          #+#    #+#             */
/*   Updated: 2023/11/22 16:07:48 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Needle in a haystack but only for len amount of chars.
 * Output will be NULL if needle string is not in the haystack and 
 * return haystack string if needle is empty. Otherwise we'll return
 * needle from frist occurance.*/

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *chonky, const char *smol, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*smol)
		return ((char *)chonky);
	if (!chonky || len <= 0)
		return (NULL);
	while (chonky[i] && i < len)
	{
		j = 0;
		while (chonky[i + j] && smol[j] == chonky[i + j] && (i + j) < len)
		{
			if (smol[j + 1] == '\0')
				return ((char *)&chonky[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    // Test 1: Normal case - substring found
    //const char *test1_chonky = "Hello, world!";
    //const char *test1_smol = "world";
    //size_t test1_len = strlen(test1_chonky);
    char *result1 = ft_strnstr("wee wee with the 9", "with", 6);
    printf("Test1: %s\n", result1);
}
    // Test 2: Substring not found within given length
    const char *test2_chonky = "This is a test";
    const char *test2_smol = "notfound";
    size_t test2_len = 5;
    char *result2 = ft_strnstr(test2_chonky, test2_smol, test2_len);
    printf("Test2: %s\n", result2);

    // Test 3: Substring is an empty string
    const char *test3_chonky = "Testing empty string";
    const char *test3_smol = "";
    size_t test3_len = strlen(test3_chonky);
    char *result3 = ft_strnstr(test3_chonky, test3_smol, test3_len);
    printf("Test3: %s\n", result3);

    // Test 4: NULL string input
    const char *test4_chonky = NULL;
    const char *test4_smol = "test";
    size_t test4_len = 5;
    char *result4 = ft_strnstr(test4_chonky, test4_smol, test4_len);
    if (result4 == NULL)
        printf("Test4: Result is NULL (expected for NULL input)\n");
    else
        printf("Test4: %s\n", result4);
	return (0);
}*/
