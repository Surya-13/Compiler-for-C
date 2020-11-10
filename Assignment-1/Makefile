a.out: y.tab.c lex.yy.c
	gcc -O3 lex.yy.c y.tab.c
	@echo "Run the program as ./a.out [input_file]"

y.tab.c: file.y 
	yacc -d file.y

lex.yy.c: file.l y.tab.h
	lex file.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c a.out

