all:
	@echo running all tests
	$(MAKE) vector
	$(MAKE) matrix

vector:
	g++ vector.cpp -o out/vector.out -I../smath -O2
	./out/vector.out

matrix:
	g++ matrix.cpp -o out/matrix.out -I../smath -O2
	./out/matrix.out

preformance:
	g++ preformance.cpp -o out/preformance.out -I../smath -O2
	./out/preformance.out

clean:
	rm out/matrix.out
	rm out/vector.out
	rm out/preformance.out