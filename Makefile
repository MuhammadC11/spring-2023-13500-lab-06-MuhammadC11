main: main.o caesar.o vigenere.o decrypt.o
	g++ -o main main.o caesar.o vigenere.o decrypt.o

tests: tests.o caesar.o vigenere.o decrypt.o
	g++ -o tests tests.o caesar.o vigenere.o decrypt.o



caesar.o: caesar.cpp caesar.h
	g++ -std=c++11 -c caesar.cpp
vigenere.o: vigenere.cpp vigenere.h

decrypt.o: decrypt.cpp decrypt.h

main.o: main.cpp caesar.h vigenere.h decrypt.h
	g++ -c -std=c++11 main.cpp
	
tests.o: tests.cpp doctest.h caesar.h vigenere.h decrypt.h
	g++ -c -std=c++11 tests.cpp

test-ascii: test-ascii.o 
	g++ -o test-ascii test-ascii.o 

test-ascii.o: test-ascii.cpp
	g++ -c -std=c++11 test-ascii.cpp

clean:
	rm -f main.o tests.o main tests caesar.o vigenere.o test-ascii.o test-ascii decrypt.o test-ascii test-ascii.o