CC = g++
CFLAGS = -c -Wall -Werror -Wextra -g -std=c++17
TEST_CFLAGS = -lgtest -lgmock -pthread
OBJ = $(CFILES:.cc=.o)
TESTS_OBJ = $(TESTS_CFILES:.cc=.o)
TESTS_CFILES = $(wildcard tests/*.cc)
CFILES = $(wildcard matrix_oop/*.cc)
EXECUTABLE = s21_matrix
LIB = s21_matrix_oop.a
GCOV_FLAGS=--coverage -Wall -Werror -Wextra -std=c++17

# $^ вызов всех подцелей
# $< вызов первой подцели
# $@ вызов цели

all: $(LIB) test

$(EXECUTABLE) : $(OBJ)
	$(CC) $^ -o $(EXECUTABLE)
	./$(EXECUTABLE)

%.o : %.cc
	$(CC) $(CFLAGS) $^ -o $@

$(LIB) : $(OBJ)
	ar -rc $(LIB) $(OBJ)
	ranlib $(LIB)

test : $(TESTS_OBJ) $(LIB)
	$(CC) $^ -o test $(TEST_CFLAGS)
	./test

checkstyle:
	clang-format -style=google -n tests/*.cc
	clang-format -style=google -n tests/*.h
	clang-format -style=google -n matrix_oop/*.cc
	clang-format -style=google -n *.h

gcov_report: $(TESTS_OBJ)
	$(CC) $(GCOV_FLAGS) $(TEST_CFLAGS) $(TESTS_OBJ) $(CFILES) -o test
	./test
	lcov -t "s21_matrix_oop" -o s21_matrix_oop.info -c -d .
	genhtml -o report s21_matrix_oop.info
	open report/index.html

clean:
	rm -rf $(OBJ) $(LIB) $(TESTS_OBJ) test $(EXECUTABLE) *.gcov *.gcno *.gcda *.info report