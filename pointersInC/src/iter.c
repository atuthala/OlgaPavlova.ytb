#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO Вынести объявления в отдельный .h-файл

typedef struct metastr{
	int length;
	char* data;
} metastr;

typedef void (*cb)(char); // тип функции для обратных вызовов при обработке метастрок

void run_callback(char);
void run_another_callback(char);

void iterator_char(metastr, cb); // итератор по метастроке

int main()
{
	// char c[] = "abcdefghi";
	char * c = malloc(sizeof(char) * 10);
	strcpy(c, "abcdefghi");

	metastr mts = {.length = 10, .data = c}; // не совсем верно

	iterator_char(mts, run_another_callback);

	// ??? MAGIC_RUN(@c@, !printf...!)

	// + size -- задаём длину
	// + '\0' -- это конец
	// *** как-то зашить размер в сами данные

	free(c);
	return 0;
}

void run_callback(char h) {
	printf("%c ", h);
}

void run_another_callback(char h) {
	printf("%d -- %c\n", h, h);
}

// Итератор по метастроке (точнее, по её символам)
void iterator_char(metastr mts, cb rcb)
{
	for (int i = 0; i < mts.length; i++)
		rcb(mts.data[i]);
}