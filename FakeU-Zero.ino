#include "Config.hpp"

#if EMULATE
	#include <stdlib.h>
	#include <stdio.h>
	#include <stdbool.h>
	#include <string.h>
	#include <stdint.h>
	#include <unistd.h>
#else
	#include <Arduino.h>
	#include <Tiny4kOLED.h>
#endif

#include "Option.hpp"
#include "Page.hpp"

int option_index;
char button;
Page *page;

#if EMULATE
	size_t buffer_size;
	char *buffer;
#endif

void setup()
{
	#if EMULATE

	#else
		oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
		oled.setFont(FONT6X8);
		oled.clear();
		oled.on();
	#endif

	page = new_page(5);

	page->options[0] = new_option("Scan Wi-Fi", []()->void {
		#if EMULATE
			system("clear");
			puts("Scanning Wi-Fi...");
			sleep(3);
			puts("Name: Unknow\nPassword: sat214124\nChannel: 3\nDistance: 3m*");
			getc(stdin);
		#endif
	});
	page->options[1] = new_option("Apps", []()->void {});
	page->options[2] = new_option("AM Reader", []()->void {});
	page->options[3] = new_option("RFID", []()->void {});
	page->options[4] = new_option("Exit", []()->void {});

	option_index = 0;
	button = 0;
}

void loop()
{
	#if EMULATE
		system("clear");
		for(size_t i = 0; i < page->amount_of_option; i++)
		{
			printf("%s%s\n", i == option_index ? "> " : "", page->options[i]->label);
		}
		getline(&buffer, &buffer_size, stdin);
		if(*buffer == 's')
			option_index += 1;
		else if(*buffer == 'w')
			option_index -= 1;
		else if(*buffer == 'd')
			page->options[option_index]->execute();
	#else
		oled.setCursor(0, 2);
		for(size_t i = 0; i < page->amount_of_option; i++)
		{
			oled.print(option_index == i ? "|" : " ");
			oled.println(page->options[i]->label);
		}
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

