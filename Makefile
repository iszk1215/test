CFLAGS = `python3.9-config --cflags` -Ipybind11/include

all: test01.so

test01.so: test01.cc
	g++ -o $@ -shared -fPIC $(CFLAGS) $<

run: test01.so
	python3.9 test01.py



