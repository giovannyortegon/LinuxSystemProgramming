#include<iostream>
#include<filesystem>
#include<fstream>

int main() {
	std::filesystem::create_directories("test/src/config");
	stt::ofstream("test/src/file.txt") <<"This is an example!";

	return (0);
}
