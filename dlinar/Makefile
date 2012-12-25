MAIN: main.c libdlinar.a dlinar.h
	gcc main.c -L. -ldlinar -o MAIN
libdlinar.a: tests.o simple.o modular.o test1.o test2.o test3.o test4.o test5.o test6.o test7.o test8.o test9.o
	ar rc libdlinar.a tests.o simple.o modular.o test1.o test2.o test3.o test4.o test5.o test6.o test7.o test8.o test9.o
tests.o: tests.c test1.o
	gcc -c tests.c
test8.o: test8.c simple.o
	gcc -c test8.c
test9.o: test9.c simple.o
	gcc -c test9.c
test7.o: test7.c simple.o
	gcc -c test7.c
test6.o: test6.c simple.o
	gcc -c test6.c
test5.o: test5.c simple.o
	gcc -c test5.c
test4.o: test4.c simple.o
	gcc -c test4.c
test3.o: test3.c simple.o
	gcc -c test3.c
test2.o: test2.c simple.o
	gcc -c test2.c
test1.o: test1.c simple.o
	gcc -c test1.c
modular.o: modular.c simple.o
	gcc -c modular.c
simple.o: simple.c
	gcc -c simple.c
