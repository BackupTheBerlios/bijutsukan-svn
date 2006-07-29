all: clean backendtest

backendtest:
	g++ backendtest.cpp fileIndex-test.cpp imageObject-test.cpp -o backendtest -L.. -lbackend `wx-config-2.6 --cflags --libs`

clean:
	rm -f backendtest
