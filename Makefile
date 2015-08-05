CXX=c++
CXX_ARGS=-std=c++1y -g -I/usr/local/include -Wno-deprecated-register
SRC_DIR=src
SOURCES=$(shell find "${SRC_DIR}" -name "*.cpp")

all: flex bison
	@echo $(CXX) $(CXX_ARGS) ${SOURCES} -o ys420i
	@$(CXX) $(CXX_ARGS) ${SOURCES} -o ys420i
bison:
	@(cd $(SRC_DIR) && bison parser.y)
flex:
	@(cd $(SRC_DIR) && flex lexer.l)
clean:
	rm -f ys420i
	rm -f $(SRC_DIR)/{parser,lexer}.{hpp,cpp}
