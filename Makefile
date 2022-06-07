# Make for netc
## Pysogge

.PHONY: build run clean

build:
	gcc ./src/nclist.c -o ./exe/nclist
	gcc ./src/nclistinet.c -o ./exe/nclistinet

run:
	./exe/nclist
	./exe/nclistinet

clean:
	rm ./exe/*