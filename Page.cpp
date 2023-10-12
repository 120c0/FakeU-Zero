#include "Page.hpp"

#include <stdlib.h>

Page *new_page(int amount_of_option)
{
	Page *page = (Page*) malloc(sizeof(Page));

	page->options = (Option**) malloc(sizeof(Option*) * amount_of_option);
	page->amount_of_option = amount_of_option;

	return page;
}

void free_page(Page *page)
{
	for(int o = 0; o < page->amount_of_option; o++)
		if(page->options[o] != NULL)
			free_option(page->options[o]);
	free(page);
}

