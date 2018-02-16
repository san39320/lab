bison -y -d yaccc.y
flex yaccc.l
gcc -c y.tab.c lex.yy.c
gcc y.tab.o lex.yy.o yaccc.c -o out
