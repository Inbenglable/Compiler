CC=gcc
FLEX=flex
BISON=bison
ip:
		$(BISON) -d syntax.y
		$(FLEX) my_lex.l
		$(CC) lex.yy.c syntax.tab.c structure.c symbol_table.c -lfl -o splc
clean:
		@rm -f lex.yy.c syntax.tab.c syntax.tab.h *.out
.PHONY: splc