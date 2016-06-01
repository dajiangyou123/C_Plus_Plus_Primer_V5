Programs = folder_message
CXXFLAGS = '-std=c++11'

all: $(Programs)

folder_message: message.o folder.o 
	g++ $(CXXFLAGS) -o $@ $^ 

.PHONY: clean

clean:
	rm *.o
