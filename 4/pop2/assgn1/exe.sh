#!/bin/bash
flex lex*.l
if [ $? -eq 0 ]; then
	gcc -o out lex.yy.c -lfl
else
    echo flex error
fi
if [ $? -eq 0 ]; then
    ./out
else
    echo gcc error
fi
