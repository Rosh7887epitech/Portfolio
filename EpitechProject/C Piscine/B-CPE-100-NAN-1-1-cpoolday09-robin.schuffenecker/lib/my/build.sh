#/bin/sh
rm a.out
rm libmy.a
gcc -c *.c -I../../include
ar rc libmy.a *.o
rm *.o
