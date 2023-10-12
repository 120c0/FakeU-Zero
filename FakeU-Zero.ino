#define EMULATE 0

#if EMULATE
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdbool.h>
	#include <string.h>
	#include <stdint.h>
#else
	#include <Arduino.h>
	#include <Tiny4kOLED.h>
#endif

#include "Option.hpp"
#include "Page.hpp"

void setup()
{
	Page *page = new_page(2);

	page->options[0] = new_option("Scan Wi-Fi");
	page->options[1] = new_option("Clone RFID");

	dump_option(page->options[0]);

	free_page(page);
}
void loop()
{
}

#if EMULATE
	int main(void)
	{
		setup();
		while(EMULATE)
			loop();
		return EXIT_SUCCESS;
	}
#endif

