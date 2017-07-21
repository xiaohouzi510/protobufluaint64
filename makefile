includePath = -Ilua/include/ -Igoogle/include/ -I./proto_cpp
libPath 	= -Llua/lib -Lgoogle/lib64/
cpp_file    = main.cpp ./proto_cpp/test.pb.cc

all : main pb.so

main : $(cpp_file)
	g++ -g -Wl,-E -o $@ $^ -llua -ldl -lprotobuf $(includePath) $(libPath)
	
pb.so : pb.cpp
	gcc -g -fPIC --shared -o $@ $^ $(includePath) $(libPath)

clean :
	rm -rf main pb.so