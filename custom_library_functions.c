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
	return (Dest);
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
