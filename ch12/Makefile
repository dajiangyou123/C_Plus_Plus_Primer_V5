Programs = query_test
CXXFLAGS = '-std=c++11'

all: $(Programs)

query_test: query_test.o queryresult.o textquery.o
	g++ $(CXXFLAGS) -o $@ $^ 

.PHONY: clean

clean:
	rm *.o
