#define EMULATE 1


#if EMULATE
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdbool.h>
	#include <string.h>
	#include <stdint.h>
#else
	#include <Arduino.h>
#endif

typedef struct _Option
{
	char *label;
	bool is_active;
} Option;

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
	#else 

	#endif
}

void setup()
{
	Option *option = new_option("Scan Wi-Fi");

	dump_option(option);

	free_option(option);
}
void loop()
{
}

#if EMULATE
	int main(void)
	{
		setup();
		// while(EMULATE)
			loop();
		return EXIT_SUCCESS;
	}
#endif

