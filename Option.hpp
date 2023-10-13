#ifndef OPTION_H
#define OPTION_H

#include <stdbool.h>

typedef struct _Option
{
	char *label;
	bool is_active;
	void (*execute)(void);
} Option;

Option *new_option(const char*, void (*)(void));
void free_option(Option*);
void dump_option(Option*);

#endif
