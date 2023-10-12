#include "Option.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Option *new_option(const char *label)
{
	Option *option = (Option*) malloc(sizeof(Option));
	option->label = (char*) malloc(sizeof(char) * strlen(label));

	strcpy(option->label, label);
	option->is_active = false;

	return option;
}

void free_option(Option *option)
{
	free(option->label);
	free(option);
}

void dump_option(Option *option)
{
	#if EMULATE
		printf("Option: %p\nLabel: %s\nIs_Active: %d\n", option, option->label, option->is_active);
	#endif
}
