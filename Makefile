
GXX49_VERSION := $(shell g++-4.9 --version 2>/dev/null)

ifdef GXX49_VERSION
	CXX_COMMAND := g++-4.9
else
	CXX_COMMAND := g++
endif

CXX = ${CXX_COMMAND} -std=c++11 -Wall

run_test: disks_test
	./disks_test

headers: rubrictest.hpp disks.hpp

disks_test: headers disks_test.cpp
	${CXX} disks_test.cpp -o disks_test

clean:
	rm -f disks_test
