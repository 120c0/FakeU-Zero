#ifndef PAGE_HPP
#define PAGE_HPP

#include "Option.hpp"

typedef struct _Page
{
	Option **options;
	int amount_of_option;
} Page;

Page *new_page(int);
void free_page(Page*);

#endif

