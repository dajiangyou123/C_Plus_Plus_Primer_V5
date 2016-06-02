Programs = folder_message strvec_test
CXXFLAGS = -g -std=c++11

all: $(Programs)

folder_message: message.o folder.o 
	g++ $(CXXFLAGS) -o $@ $^ 

#对StrVec类的测试
strvec_test: strvec_test.o strvec.o
	g++ $(CXXFLAGS) -o $@ $^ 

.PHONY: clean

clean:
	rm *.o
