#/bin/sh
rm a.out
rm libmy.a
gcc -c *.c
ar rc libmy.a *.o
rm *.o
