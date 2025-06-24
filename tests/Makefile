all:
	@echo running all tests
	$(MAKE) vector
	$(MAKE) matrix

vector:
	g++ vector.cpp -o vector.out -I../smath -O2
	./vector.out

matrix:
	g++ matrix.cpp -o matrix.out -I../smath -O2
	./matrix.out

clean:
	rm matrix.out
	rm vector.out