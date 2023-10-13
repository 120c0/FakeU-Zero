emulate:
	ln -s -f FakeU-Zero.ino .main.cpp
	gcc .main.cpp Option.cpp Page.cpp -o main.elf

clear:
	rm -rf .main.cpp main.elf
