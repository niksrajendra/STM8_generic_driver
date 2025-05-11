CC =	sdcc
#SRCS=	./main.c
CONFIG=Debug
SRCS= $(wildcard ./src/*.c)
OBJS=$(SRCS:.c=.rel)
OBJWIN=$(patsubst %/%,%\\%,$(OBJS))
LIBS=	-lstm8 -mstm8
IDIR=	./inc
ODIR=	./bin/$(CONFIG)
CFLAGS=	$(IDIR)
OFLAGS=--out-fmt-ihx
EXEC=demo1.ihx

Debug: $(OBJS)
#	mkdir -p $(ODIR)
#	$(CC) $(SRCS) -I$(CFLAGS) $(LIBS) --out-fmt-ihx -o$(ODIR)/
	@echo $(SRCS) $(OBJS)
	$(CC) --debug $(OBJS) -I$(CFLAGS) $(LIBS) --out-fmt-ihx -o $(EXEC)

%.rel: %.c
	@echo compiling file $<
	$(CC) $(OFLAGS) --debug -c $< -I$(CFLAGS) $(LIBS) -o $@


.PHONY: clean flash cleanDebug

clean:
	rm -rf $(ODIR)/*

cleanDebug:
	rm -rf $(OBJS)
	rm -rf src/*.lst src/*.rst src/*.sym src/*.asm

flash:
	stm8flash -cstlinkv2 -pstm8s003f3 -w$(ODIR)/main.ihx
