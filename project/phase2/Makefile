CC=gcc
FLEX=flex
BISON=bison
ip:
		$(BISON) -d syntax.y
		$(FLEX) lex.l
		$(CC) lex.yy.c syntax.tab.c structure.c symbol_table.c -lfl -o ./bin/splc
clean:
		@rm -f lex.yy.c syntax.tab.c syntax.tab.h *.out *.exe
.PHONY: splc