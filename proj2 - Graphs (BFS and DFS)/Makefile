#
# Makefile for Six Degrees
#
# Project 2 (fall 2020)
#
# Edited by Kirin Godhwani, 12/1/21
# 

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11 
INCLUDES = $(shell echo *.h)

SixDegrees: main.o SixDegrees.o CollabGraph.o Artist.o
	${CXX} -o $@ $^

unit_test: unit_test_driver.o SixDegrees.o CollabGraph.o Artist.o
	$(CXX) $(CXXFLAGS) $^

clean:
	rm -rf SixDegrees *.o *.dSYM

provide:
	provide comp15 proj2phase2 SixDegrees.cpp SixDegrees.h CollabGraph.cpp \
	        CollabGraph.h Artist.cpp Artist.h main.cpp unit_tests.h \
			demooutput.txt output.txt empty.txt artists.txt printquit.txt \
			print.txt nodisc.txt oneartist.txt README Makefile \
			run_tests.txt cmdbfssmallartist.txt cmddfssmallartist.txt \
			cmdnotsmallartist.txt cmdbfsempty.txt cmddfsempty.txt \
			cmdnotempty.txt cmdbfsnodisc.txt cmddfsnodisc.txt \
			cmdnotnodisc.txt cmdbfsoneartist.txt cmddfsoneartist.txt \
			cmdnotoneartist.txt commands.txt
