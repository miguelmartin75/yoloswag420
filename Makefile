make:
	bison parser.y
	flex lexer.l
	c++ src/*.cpp -o intrptr -std=c++11
clean:
	rm -f intrptr
