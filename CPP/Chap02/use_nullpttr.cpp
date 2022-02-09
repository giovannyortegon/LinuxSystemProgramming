#include<iostream>

bool speedUp(int speed);
bool speedUp(char * speed);

int main() {
	bool ok = speedUp(NULL);

	//bool ok = speedUp(nullptr);
}
bool speedUp(int speed) {
	return speed;
}
bool speedUp(char * speed) {
	return speed;
}
