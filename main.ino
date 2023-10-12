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

// --> Option {
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
		Serial.print("Option: %p\nLabel: %s\nIs_Active: %d\n", option, option->label, option->is_active);
	#endif
}
// } Option;

// --> Page {
typedef struct _Page
{
	Option **options;
	int amount_of_option;
} Page;

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
// } Page;

void setup()
{
	Page *page = new_page(2);

	page->options[0] = new_option("Scan Wi-Fi");
	page->options[1] = new_option("Clone RFID");

	free_page(page);
	
	#if !EMULATE
		Serial.begin(9600);
	#endif
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

