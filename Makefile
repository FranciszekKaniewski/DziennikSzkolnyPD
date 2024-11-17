#.PHONY: build run bar test


OUT_NAME := ./exe/main

H_FILES_DIR := headers
CPP_FILES := $(wildcard *.cpp)


build:
	if not exist exe mkdir exe
	g++ -I $(H_FILES_DIR) -o $(OUT_NAME) $(CPP_FILES)

run:
	./exe/main.exe

bar:
	@$(MAKE) build
	@$(MAKE) run