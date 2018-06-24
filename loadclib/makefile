
hello:libexample.so
	g++ main.cpp -o hello -Lbuild -lexample 
libexample.so:
#	g++ -fPIC -shared build/example.c -o build/libexample.so
	gcc -fPIC -shared build/example.c -o build/libexample.so
clean:
	rm hello build/libexample.so

#readelf -d hello
#LD_LIBRARY_PATH