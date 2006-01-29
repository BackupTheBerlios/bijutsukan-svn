all: clean backendtest

backendtest:
	g++ backendtest.cpp -o backendtest -L.. -lbackend `wx-config-2.6 --cflags --libs`

clean:
	rm -f backendtest
