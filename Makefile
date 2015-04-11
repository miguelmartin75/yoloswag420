CXX=
CXX_ARGS=-std=c++11 -g
SRC_DIR=src

all: flex bison
	$(CXX) $(CXX_ARGS) $(SRC_DIR)/*.cpp -o ys420i
bison:
	@(cd $(SRC_DIR) && bison parser.y)
flex:
	@(cd $(SRC_DIR) && flex lexer.l)
clean:
	rm -f ys420i
	rm -f $(SRC_DIR)/{parser,lexer}.{hpp,cpp}
