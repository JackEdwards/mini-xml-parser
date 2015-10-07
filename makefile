COMPILER = g++
FLAGS  = -g -Wall -std=c++11

default: xmlparser

xmlparser:  main.o Token.o XMLFile.o XMLTag.o XMLValue.o
	$(COMPILER) $(FLAGS) -o xmlparser main.o Token.o XMLFile.o XMLTag.o XMLValue.o

Token.o:  Token.cpp Token.hpp
	$(COMPILER) $(FLAGS) -c Token.cpp

XMLFile.o:  XMLFile.cpp XMLFile.hpp
	$(COMPILER) $(FLAGS) -c XMLFile.cpp

XMLTag.o:  XMLTag.cpp XMLTag.hpp
	$(COMPILER) $(FLAGS) -c XMLTag.cpp

XMLValue.o:  XMLValue.cpp XMLValue.hpp
	$(COMPILER) $(FLAGS) -c XMLValue.cpp

clean: 
	$(RM) xmlparser *.o *~