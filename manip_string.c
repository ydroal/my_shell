#include "shell.h"
/**
  * _strcmp - compares two strings.
  *
  * @s1: string to be compared with @s2
  * @s2: string to be compared with @s1
  * Return: positive number - string s1 is greater than s2
  *         0 - string s1 equal to s2
  *	    negative number - string s1 less than s2
  */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int n = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			n = (s1[i] - s2[i]);
			return (n);
		}
		i++;
	}
	return (0);
}

/**
  * _strcat - concatenates two strings.
  *
  * @dest: string to be append the @src string.
  * @src: string append the @dest string.
  * Return: the pointer to dest
  */
char *_strcat(char *dest, char *src)
{
	int y = 0, z = 0, len = 0;

	while (src[len] != '\0')
		len++;

	while (dest[z] != '\0')
		z++;

	len += z;

	while (z <= len)
	{
		dest[z] = src[y];
		y++;
		z++;
	}
	return (dest);
}

/**
  * _strcpy - copies the string pointed to by src, including the terminating
  * null byte (\0), to the buffer pointed to by dest.
  *
  * @dest: destination
  * @src: string to be copied
  * Return: the pointer to dest
  */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		(dest[i]) = (src[i]);
		i++;
	}
	(dest[i]) = '\0';
	return (dest);

}
/**
 * _strdup - returns a pointer to a new string which is
 *           a duplicate of the string str.
 * @str: string to be copiedr
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{

	char *ar;
	int i, j;

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
		;

	i++;

	ar = malloc(i * sizeof(char));

	if (ar == NULL)
	{
		return (NULL);
	}

	for (j = 0; j < i; j++)
	{
		ar[j] = str[j];
	}

	return (ar);
}
