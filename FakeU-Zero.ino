#include "Config.hpp"

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

int option_index;
char button;
Page *page;

void setup()
{
	#if EMULATE

	#else
		oled.begin();
		oled.setFont(FONT8X16);
		oled.clear();
		oled.on();
		oled.switchRenderFrame();
	#endif

	page = new_page(3);

	page->options[0] = new_option("Scan Wi-Fi");
	page->options[1] = new_option("Clone RFID");
	page->options[2] = new_option("Exit");
	option_index = 0;
	button = 0;
}
void loop()
{
	#if EMULATE
		for(size_t i = 0; i < 3; i++)
		{
			printf("%s%s\n", i == option_index ? "> " : "", page->options[i]->label);
		}
	#else
		oled.clear();
		oled.setCursor(0, 1);
		oled.print(F("ms: "));
		oled.print(millis());
		oled.switchFrame();
		delay(50);
	#endif
}
#if EMULATE
	int main(void)
	{
		printf("Press Ctrl+C to exit...\n\n");
		setup();
		while(EMULATE)
			loop();
		return EXIT_SUCCESS;
	}
#endif

