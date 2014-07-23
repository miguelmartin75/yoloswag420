CXX=
CXX_ARGS=-std=c++11 -O3
SRC_DIR=src

make:
	bison parser.y
	flex lexer.l
	$(CXX) $(CXX_ARGS) $(SRC_DIR)/*.cpp -o ys420i
clean:
	rm -f ys420i