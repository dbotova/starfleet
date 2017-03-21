#include "header.h"

void strip_str(char *str)
{
    char *p, *q;
    for (q = p = str; *p; p++)
    {
    	if (*p == '\r' || *p == '\t' || *p == '\f' || *p == '\v')
    		*p = ' ';
        if (*p != '.' && *p != ',' && *p != '!' && *p != '?'
        	&& *p != ':' && *p != ';' && *p != '\n')
            *q++ = *p;
    }
    *q = '\0';
}

static int	isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}

static int	isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == ' '
			|| c == '\f')
		return (1);
	else
		return (0);
}

static int get_size(char *book, int *map)
{
	int size = 0;
	int m_idx = 0;
	int w_size = 0;
	while(*book)
	{
		if(isprint(*book) && !isspace(*book))
			w_size++;
		else
		{
			if (w_size)
			{
				map[m_idx++] = w_size;
				w_size = 0;
				size++;
			}
		}
		book++;
	}
	return (size);
}

static void get_words(char *book, int *map, struct s_list *list)
{

}

char **mostUsedWords(char *book)
{
	char **result;
	int *map = (int*)malloc(sizeof(int) * MAP_SIZE);
	memset(map, -1, MAP_SIZE);
	int size = get_size(book, map);

	struct s_list *list = malloc(sizeof(struct s_list));
	list->len = size;
	list->elems = malloc(sizeof(struct s_elem) * size);
	for (int i = 0; i < size; i++)
	{
		list->elems[i] = malloc(sizeof(struct s_elem));
		list->occurence = 0;
	}
}
