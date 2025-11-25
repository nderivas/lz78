# 📦 LZ78 Based Compressor
👤 Author: Nicolás de Rivas Morillo
## ℹ️ Description
This project is a lossless compression program based on the LZ78 algorithm. It's in C++ and utilizes datastructures such as HashMaps and Tries.
## 🔨 Usage
To use the project you'll need to compile the source code, to this end a Makefile can be found in the root folder, by default it uses the `g++` compiler, this can be easily changed to `clang` or others by editing the value of the variable `CXX` of this Makefile. After the Makefile is configured to your liking just use the `make` command and a binary file will be created inside the bin folder. To invoke the program simply use the command:

`bin/lz78 [-c|-d]`

Where the `-c` option will compress the file and the `-d` option will decompress it. The binary will take input through stdin and will write to stdout.
