#include "main.h"
/**
 *_strcpy - copy the string pointed to by src to dest
 *@dest: char to check
 *@src: char to check
 *Return: 0 is success
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}


/**
  *_strlen - checks the length of string
  *@s: character to check
  *Return: integer
  */
int _strlen(char *s)
{
	int count = 0;

	for (; *s++; )
		count++;
	return (count);
}


/**
 *_strcat - concats 2 strings
 *@dest: destination string
 *@src: source string
 *Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i, n;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (n = 0; (dest[i + n] = *src++) != '\0'; n++)
	{
	}
	return (dest);
}


/**
 * _strcmp - a function that compares two strings
 * @s1: input one
 * @s2: input two
 * Return: Always 0 (Success)
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
