src = src/
objects = $(src)mytest.o $(src)utils.o $(src)gjlib_arrays.o  
mytest : $(objects)
	gcc -o mytest.exe $(objects) -lm
utils.o : $(src)primes.h $(src)gjlib_arrays.h
gjlib_arrays.o : 
.PHONY : clean
clean :
	rm mytest.exe $(objects)
