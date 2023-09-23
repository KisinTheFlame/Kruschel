DIR_INC=./include
DIR_LIB=./lib
DIR_BUILD=./build
DIR_TEST=./test
DIR_APP=./application

INC=$(shell find $(DIR_INC) -name "*.hpp")
SRC=$(shell find $(DIR_LIB) -name "*.cpp")
OBJ=$(patsubst %.cpp, %.o, $(SRC))
TEST=$(shell find $(DIR_TEST) -name "*.cpp")
TEST_OBJ=$(patsubst %.cpp, %.o, $(TEST))

TARGET=main
BUILD_TARGET=$(DIR_BUILD)/$(TARGET)

CC=g++
CFLAGS=-Wall -I$(DIR_INC) -std=c++23 -c -g

all: $(BUILD_TARGET)

run: $(BUILD_TARGET)
	$(BUILD_TARGET)

$(BUILD_TARGET): $(DIR_APP)/$(TARGET).o $(OBJ)
	if [ ! -d $(DIR_BUILD) ]; then mkdir $(DIR_BUILD); fi
	$(CC) $(DIR_APP)/$(TARGET).o $(OBJ) -o $(BUILD_TARGET)

test: $(if $(case), $(DIR_TEST)/test-$(case).o, $(TEST_OBJ)) $(OBJ)
	@if [ ! -d $(DIR_BUILD) ]; then mkdir $(DIR_BUILD); fi
ifeq ($(origin case), undefined)
	@for test_object in $(TEST_OBJ); do \
		target=$$(echo $$test_object | sed "s/\.o$$//g" | sed "s/.*\///g"); \
		echo testing $$target \
		&& $(CC) $$test_object $(OBJ) -o $(DIR_BUILD)/$$target \
		&& $(DIR_BUILD)/$$target \
		&& echo $$target passed \
		|| echo $$target failed $$?; \
	done
	@echo all tests passed
else
	@$(CC) $(DIR_TEST)/test-$(case).o $(OBJ) -o $(DIR_BUILD)/test-$(case) \
	&& $(DIR_BUILD)/test-$(case) \
	&& echo test $(case) passed \
	|| echo test $(case) faild $$?
endif

%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(DIR_BUILD)
	find . -name "*.o" | xargs rm -f

.PHONY: clean test
