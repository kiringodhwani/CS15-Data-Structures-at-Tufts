###
### Makefile for CalcYouLater Project
### CalcYouLater is an RPN calculator
###
### Author:  Kirin Godhwani, 10/17/21



##
##  --- Delete these comments and put appropriate comments in ---
##
## Put your variables and rules here.  You can use previous Makefiles
## as examples, and you can refer to the "make" documentation on the
## course Reference page.
##
## CAUTION:  DO NOT JUST USE THE OLD RULES FOR 'clean'!!!
##           You do NOT want to remove Datum.o!!
##
##  --- Delete these comments and put appropriate comments in ---

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

CalcYouLater: main.o RPNCalc.o DatumStack.o Datum.o
	$(CXX) $(LDFlagS) -o CalcYouLater main.o RPNCalc.o DatumStack.o Datum.o

main.o: main.cpp RPNCalc.o
	$(CXX) $(CXXFLAGS) -c main.cpp

RPNCalc.o: RPNCalc.cpp RPNCalc.h DatumStack.o
	$(CXX) $(CXXFLAGS) -c RPNCalc.cpp

DatumStack.o: DatumStack.cpp DatumStack.h Datum.o
	$(CXX) $(CXXFLAGS) -c DatumStack.cpp


#testing parseRString
testParser: testParser.o parser.o
	$(CXX) $(LDFlagS) -o testParser testParser.o parser.o

parser.o: parser.cpp parser.h
	$(CXX) $(CXXFLAGS) -c parser.cpp

testParser.o: testParser.cpp parser.o
	$(CXX) $(CXXFLAGS) -c testParser.cpp

## unit test
unit_test: unit_test_driver.o DatumStack.o Datum.o
	$(CXX) $(CXXFLAGS) $^
	
clean: 
	rm *~ a.out

provide:
	provide comp15 proj1_calcyoulater DatumStack.h DatumStack.cpp \
				    README parser.cpp parser.h testParser.cpp \
				    unit_tests.h Makefile \
						RPNCalc.h RPNCalc.cpp main.cpp \
						demostdout.txt stdout.txt \
						testAll.cyl testcommands.txt \
						fact.cyl fib.cyl fib_debug.cyl

##
## Here is a rule for compiling .cyl files for use in your testing
##
%.cylc:  %.cyl
	./cylc $^
