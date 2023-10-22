#include "monty.h"

global_t programContext;
/**
* free_programContext - frees the global variables
*
* Return: void
*/
void free_programContext(void)
{
	free_dlistint(programContext.head);
	free(programContext.buffer);
	fclose(programContext.fd);
}

/**
* start_programContext - initializes the global variables
*
* @fd: file descriptor
* Return: void
*/
void start_programContext(FILE *fd)
{
	programContext.lifo = 1;
	programContext.cont = 1;
	programContext.arg = NULL;
	programContext.head = NULL;
	programContext.fd = fd;
	programContext.buffer = NULL;
}

/**
* check_input - checks if the file exists and if the file can be opened
* @argc: argument count
* @argv: argument vector
* Return: file struct
*/
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
* main - Entry point
* @argc: argument count
* @argv: argument vector
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_programContext(fd);
	nlines = getline(&programContext.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = _strtoky(programContext.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", programContext.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_programContext();
				exit(EXIT_FAILURE);
			}
			programContext.arg = _strtoky(NULL, " \t\n");
			f(&programContext.head, programContext.cont);
		}
		nlines = getline(&programContext.buffer, &size, fd);
		programContext.cont++;
	}
	free_programContext();

	return (0);
}
