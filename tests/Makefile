.SILENT:

MAKEFLAGS += --no-print-directory

all: 
	@echo running all tests
	$(MAKE) vector
	$(MAKE) quaternion
	$(MAKE) matrix

vector:
	g++ vector.cpp -o out/vector.out -I../smath -O2
	./out/vector.out

quaternion:
	g++ quaternion.cpp -o out/quaternion.out -I../smath -O2
	./out/quaternion.out

matrix:
	g++ matrix.cpp -o out/matrix.out -I../smath -O2
	./out/matrix.out

preformance:
	g++ preformance.cpp -o out/preformance.out -I../smath -O2
	./out/preformance.out

clean:
	rm out/matrix.out
	rm out/quaternion.out
	rm out/vector.out
	rm out/preformance.out