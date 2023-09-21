DIR_INC=./include
DIR_LIB=./lib
DIR_BUILD=./build
DIR_TEST=./test
DIR_APP=./application

INC=$(shell find $(DIR_INC) -name "*.h")
SRC=$(shell find $(DIR_LIB) -name "*.c")
OBJ=$(patsubst %.c, %.o, $(SRC))
TEST=$(shell find $(DIR_TEST) -name "*.c")
TEST_OBJ=$(patsubst %.c, %.o, $(TEST))

TARGET=main
BUILD_TARGET=$(DIR_BUILD)/$(TARGET)

CC=gcc
CFLAGS=-Wall -I$(DIR_INC) -std=c99 -c -g

all: target

run: target
	$(BUILD_TARGET)

target: $(DIR_APP)/$(TARGET).o $(OBJ)
	if [ ! -d $(DIR_BUILD) ]; then mkdir $(DIR_BUILD); fi
	$(CC) $(DIR_APP)/$(TARGET).o $(OBJ) -o $(BUILD_TARGET)

test: $(if $(case), $(DIR_TEST)/test-$(case).o, $(TEST_OBJ)) $(OBJ)
	@if [ ! -d $(DIR_BUILD) ]; then mkdir $(DIR_BUILD); fi
ifeq ($(origin case), undefined)
	@for test_object in $(TEST_OBJ); do \
		target=$$(echo $$test_object | sed "s/\.o$$//g" | sed "s/.*\///g"); \
		echo testing $$target; \
		$(CC) $$test_object $(OBJ) -o $(DIR_BUILD)/$$target; \
		$(DIR_BUILD)/$$target || (echo $$target failed; exit 1); \
	done
else
	$(CC) $(DIR_TEST)/test-$(case).o $(OBJ) -o $(DIR_BUILD)/test-$(case)
	$(DIR_BUILD)/test-$(case)
endif
	@echo test completed

%.o: %.c $(INC)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(DIR_BUILD)
	find . -name "*.o" | xargs rm -f

.PHONY: clean test