CXX=
CXX_ARGS=-std=c++11 -g
SRC_DIR=src

make:
	bison $(SRC_DIR)/parser.y
	flex $(SIR_DIR)/lexer.l
	$(CXX) $(CXX_ARGS) $(SRC_DIR)/*.cpp -o ys420i
clean:
	rm -f ys420i
