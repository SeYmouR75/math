CC=gcc
CFLAGS=-std=c11 -D_POSIX_C_SOURCE=200809L -Wall -Werror -Wextra
GCOVFLAGS=--coverage 

TEST_DIR=Unit_tests
TEST_EXE=s21_test_math.exe
BUILD_DIR=build
REPORT_DIR=report

SRC=$(wildcard *.c)
OBJ=$(addprefix $(BUILD_DIR)/,$(SRC:%.c=%.o))
TARGET=s21_math.a

ifeq ($(wildcard $(BUILD_DIR)), )
  $(shell mkdir $(BUILD_DIR))
endif

ifeq ($(wildcard $(REPORT_DIR)), )
  $(shell mkdir $(REPORT_DIR))
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rcs $@ $(OBJ)

$(BUILD_DIR)/%.o: %.c   
	$(CC) $(CFLAGS) -c $< -o $@ 

test: clean $(TARGET)
	cd $(TEST_DIR) && make    
	cd $(TEST_DIR) && ./$(BUILD_DIR)/$(TEST_EXE)

gcov_report: clean gcov_flags $(TARGET)
	cd $(TEST_DIR) && make gcov
	cd $(TEST_DIR) && ./$(BUILD_DIR)/$(TEST_EXE)
	cd $(REPORT_DIR) && lcov -t "coverage_report" -o s21_math.info -c -d ../$(BUILD_DIR) -d ../$(TEST_DIR)/$(BUILD_DIR)
	cd $(REPORT_DIR) && genhtml s21_math.info
	cd $(REPORT_DIR) && open index.html

gcov_flags:
	$(eval CFLAGS +=-g3 --coverage)

clang_check:
	clang-format -style=Google -n *.c *.h
	cd $(TEST_DIR) && make clang_check

clang_format:
	clang-format -style=Google -i *.c *.h
	cd $(TEST_DIR) && make clang_format

clean_obj:
	cd $(BUILD_DIR) && rm -rf *.o *.exe *.so 
	rm -rf *.a 

clean_gcov:
	cd $(BUILD_DIR) && rm -rf *.gcno *.gcda
	rm -rf $(REPORT_DIR)/*

clean: clean_obj clean_gcov
	cd $(TEST_DIR) && make clean