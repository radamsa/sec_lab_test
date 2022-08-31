CC=gcc
SRC=src

LFLAGS=
DEBUG=-g
CFLAGS=-Wall -static -std=c99 -Isrc
SOURCE=$(shell find $(SRC) -type f -name '*.c')
OBJS=$(SOURCE:.c=.o)

.PHONY: docker build debug clean test test_prepare test1 test2 test3 test4 test5 test6 test7

docker:
	@docker build -q --no-cache -t radamsa/sec_lab_test .
	@docker run --rm radamsa/sec_lab_test | tee report.txt

test: build test_prepare test1 test2 test3 test4 test5 test6 test7

test_prepare:
	@cp Makefile ./test1
	@cp Dockerfile ./test2
	@cat /dev/random | head -c 4093 | base64 > test3
	@cat /dev/random | head -c 40930 | base64 > test4
	@cat /dev/random | head -c 4093 > test5
	@cat /dev/random | head -c 40930 > test6
	@cat /dev/random | head -c 409300 > test7
test1:
	@echo "=== Test 1 ==="
	@bin/app e ./test1 ./encoded
	@bin/app d ./encoded ./decoded
	@diff -q ./test1 ./decoded && echo "Files are equal" || true
test2:
	@echo "=== Test 2 ==="
	@bin/app e ./test2 ./encoded
	@bin/app d ./encoded ./decoded
	@diff -q ./test2 ./decoded && echo "Files are equal" || true
test3:
	@echo "=== Test 3 ==="
	@bin/app e ./test3 ./encoded
	@bin/app d ./encoded ./decoded
	@diff -q ./test3 ./decoded && echo "Files are equal" || true
test4:
	@echo "=== Test 4 ==="
	@bin/app e ./test4 ./encoded
	@bin/app d ./encoded ./decoded
	@diff -q ./test4 ./decoded && echo "Files are equal" || true
test5:
	@echo "=== Test 5 ==="
	@bin/app e ./test5 ./encoded
	@bin/app d ./encoded ./decoded
	@diff -q ./test5 ./decoded && echo "Files are equal" || true
test6:
	@echo "=== Test 6 ==="
	@bin/app e ./test6 ./encoded
	@bin/app d ./encoded ./decoded
	@diff -q ./test6 ./decoded && echo "Files are equal" || true
test7:
	@echo "=== Test 7 ==="
	@bin/app e ./test7 ./encoded
	@bin/app d ./encoded ./decoded
	@diff -q ./test7 ./decoded && echo "Files are equal" || true

build: app

debug: CFLAGS += $(DEBUG)
debug: clean build clean

app: $(OBJS)
	@$(CC) -o bin/app $^ $(LFLAGS) $(CFLAGS)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@find . -name '*.o' -delete
	@rm -f bin/app bin/test
	@docker container prune --force
	@docker image prune --force
