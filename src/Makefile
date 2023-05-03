UNAME:=$(shell uname -s)
ifeq ($(UNAME),Linux)
	LFLAGS=-lgtest -lsubunit -lrt -lm -lpthread
	LEAK=valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file="leak.log"
endif
ifeq ($(UNAME),Darwin)
	LFLAGS=-lgtest
	LEAK=leaks -quiet -atExit --
endif
CFLAGS=-Wall -Wextra -Werror -std=c++17
GFLAGS=-fprofile-arcs -ftest-coverage
SOURCES=s21_matrix_oop.cpp operators.cpp help_functions.cpp

all: s21_matrix_oop.a test leaks gcov_report clean

style:
	clang-format -n -style=Google *.cpp *.h

style_force:
	clang-format -style=Google -dump-config > .clang-format
	clang-format -i -style=Google *.cpp *.h

s21_matrix_oop.a: clean
	g++ $(CFLAGS) -c $(SOURCES)
	ar rc s21_matrix_oop.a *.o
	ranlib s21_matrix_oop.a
	rm -f *.o

gcov_report: clean
	g++ $(GFLAGS) $(CFLAGS) $(SOURCES) test.cpp $(LFLAGS) -o test
	-./test > test.log
	bash test_log.sh
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html
	
test: s21_matrix_oop.a
	g++ $(CFLAGS) test.cpp s21_matrix_oop.a -L. $(LFLAGS) -o test
	-./test > test.log
	bash test_log.sh

leaks: s21_matrix_oop.a
	g++ $(CFLAGS) test.cpp s21_matrix_oop.a -L. $(LFLAGS) -o test
	CK_FORK=no $(LEAK) ./test > leak.log
	bash test_leak.sh

rebuild: clean gcov_report

clean:
	rm -f test s21_matrix_oop.a *.gc* test.info log.xml test.log leak.log
	rm -f -rf report
