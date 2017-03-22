#include "header.h"

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

static int	ispunct(int c)
{
	if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96)
			|| (c >= 123 && c <= 126))
		return (1);
	else
		return (0);
}

static int get_size(char *book, int *map)
{
	int size = 0;
	int m_idx = 0;
	int w_size = 0;
	for(int i = 0; ; i++)
	{
		if(isprint(book[i]) && !isspace(book[i]) && !ispunct(book[i]))
			w_size++;
		else if (isspace(book[i]) || ispunct(book[i]) || book[i] == 0)
		{
			if (w_size)
			{
				map[m_idx++] = w_size;
				w_size = 0;
				size++;
			}
		}
		if (book[i] == 0)
			break ;
	}
	return (size);
}

static int	get_hash(char *string, int size)
{
	unsigned int result = 0;
	int power = size - 1;

	for (int i = 0; i < size; i++)
	{
		if (string[i] == 0)
			break ;
		result += string[i] * pow(B, power);
		power--;
	}
	return (result % M);
}

static int	isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

static void get_words(char *book, int *map, struct s_list *list)
{
	int i = 0;
	int m_idx = 0;

	for (int i = 0; ; i++)
	{
		if (book[i] == 0)
			break ;

		if(isspace(book[i]) || ispunct(book[i]) || !isascii(book[i]))
			continue ;
		else
		{
			char *cur = (char*)malloc(sizeof(char) * (map[m_idx] + 1));
			cur[map[m_idx]] = 0;
			cur = strncpy(cur, book + i, map[m_idx]);
			
			int hash = get_hash(cur, map[m_idx]);
			while (list->elems[hash]->word != NULL && strcmp(cur, list->elems[hash]->word) != 0)
				hash++;
			if (list->elems[hash]->word != NULL)
				list->elems[hash]->occurence += 1;
			else
			{
				list->elems[hash]->word = strdup(cur);
				list->elems[hash]->occurence = 1;
				list->len += 1;
			}
			i += map[m_idx];
			m_idx++;

			free(cur);
			cur = NULL;
		}
		if (map[m_idx] == -1)
			break ;
	}

}

static void sort(struct s_elem **elems, int size)
{
	if (size < 2)
		return ;
	int i;
	int j;
	int pivot = elems[size / 2]->occurence;

	for (i = 0, j = size - 1; ; i++, j--)
	{
		while (elems[i]->occurence > pivot) i++;
		while (elems[j]->occurence < pivot) j--;

		if (i >= j)
			break ;

		struct s_elem *tmp = elems[i];
		elems[i] = elems[j];
		elems[j] = tmp;
	}

	sort(elems, i);
	sort(elems + i, size - i);
}

char **mostUsedWords(char *book)
{
	char **result;
	result = (char**)malloc(sizeof(char*) * 255);
	for (int i = 0; i < 255; i++)
		result[i] = NULL;

	int *map = (int*)malloc(sizeof(int) * MAP_SIZE);
	memset(map, -1, MAP_SIZE);

	int size = get_size(book, map);
	if (size < 10000)
		size *= 10;


	struct s_list *list = malloc(sizeof(struct s_list));
	
	list->len = 0;
	list->elems = malloc(sizeof(struct s_elem) * size);
	for (int i = 0; i < size; i++)
	{
		list->elems[i] = malloc(sizeof(struct s_elem));
		list->elems[i]->word = NULL;
		list->elems[i]->occurence = 0;
	}

	get_words(book, map, list);
	sort(list->elems, size);

	int j = 0;
	for (int i = 0; i < 255; i++)
	{
		if (i > list->len)
			break ;
		if (strlen(list->elems[i]->word) >= MIN_LENGTH)
			result[j++] = strdup(list->elems[i]->word);
	}

	free(map);
	map = NULL;

	return (result);
}
