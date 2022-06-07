# Make for netc
## Pysogge

.PHONY: init build run help clean

help:
	@echo "Usage: make [init|build|run|clean|help]"

## Defines

SRCDIR:=src
EXEDIR:=exe

DIRS:={$(SRCDIR),$(EXEDIR)}

## Rules

init:
	mkdir -vp $(DIRS)
	chmod +x $(EXEDIR)
	echo "Directories created"

build:
	gcc ./src/nclist.c -o ./exe/nclist
	gcc ./src/nclistinet.c -o ./exe/nclistinet

run:
	./exe/nclist
	./exe/nclistinet

clean:
	rm ./exe/*