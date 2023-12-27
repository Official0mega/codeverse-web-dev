#include "../include/shell.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 *
 * @ptr: Pointer to the memory block.
 * @old_size: Previous size of the pointer.
 * @new_size: New size of the pointer.
 * Return: Pointer to reallocated memory.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	/*  If the new size is the same as the old size, return the original pointer */
	if (new_size == old_size)
		return (ptr);
	
	/*  If the new size is 0 and the pointer is not NULL, free the pointer and return NULL */
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	/*  Allocate memory for the result with the new size */
	result = malloc(new_size);
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}

	/*  If the original pointer is NULL, fill the result with null bytes */
	if (ptr == NULL)
	{
		fill_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		/*  Copy the data from the original pointer to the result */
		_memcpy(result, ptr, old_size);
		free(ptr);
	}

	return (result); /*  Return the pointer to the reallocated memory */
}

/**
 * free_mem - Free memory allocated for command and line.
 *
 * @cmd: Array pointer to free.
 * @line: String pointer to free.
 * Return: Void.
 */
void free_mem(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL; /*  Set the command pointer to NULL after freeing */
	line = NULL; /*  Set the line pointer to NULL after freeing */
}

/**
 * _memcpy - Copy bytes of memory from source to destination.
 *
 * @dest: Destination pointer.
 * @src: Source pointer.
 * @n: Number of bytes to copy.
 * Return: Pointer to destination.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	/*  Iterate through each byte and copy from source to destination */
	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * fill_array - Fill an array with a constant byte.
 *
 * @a: Void pointer to the array.
 * @el: Integer representing the constant byte.
 * @len: Length of the array.
 * Return: Void pointer to the filled array.
 */
void *fill_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	/*  Fill the array with the constant byte */
	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * _calloc - Allocates memory for an array using malloc and initializes it to zero.
 *
 * @size: Size of the array.
 * Return: Void pointer to the allocated and initialized memory.
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	/*  Check if the size is 0, return NULL if true */
	if (size == 0)
		return (NULL);

	/*  Allocate memory for the array */
	a = malloc(size);
	if (a == NULL)
		return (NULL);

	/*  Initialize the allocated memory to zero */
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a); /*  Return the pointer to the allocated and initialized memory */
}
