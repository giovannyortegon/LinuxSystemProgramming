#include<iostream>

int main()
{
	// const qualified strings; the data pointed to will be const
	const char * constData = "constant";
	const char * moreConstData;

	// regular strings, defined. One is loaded using strcpy()
	char * regularString;
	char * anotherRegularString = new charp[8];
	strcpy(anotherRegularString, "regular");

	// Trying to modify data marked as const will not work
	// strcpy(constData, "Can I do this? "); // NO!
	// Trying to circumvent by having a char * point to
	// a const char * also will not work
	// regularString = constData; // NO!

	// But we can treat a char * more strictly by assigning it to
	// a const char *. It will be const from that viewpoint only
	moreConstData = anotherRegularString; // Yes, I can do this!

	// Define, allocate, load two regular strings using strcpy()
	char *regularString = new char[36];
	strcpy(regularString, "I am a string which can be modified");
	char *anotherRegularString = new char[21];
	strcpy(anotherRegularString, "I am also modifiable");

	// Define a const pointer to a string. It must be initialized
	char *const constPtrString = regularString; // Ok
	// You may not modify a const pointer to point elsewhere
	// constPtrString = anotherRegularString; //No!
	// But you may change the data which you point to
	strcpy(constPtrString, "I can change the value"); // Yes

	// Define two regular strings and load using strcpy()
	char *regularString = new char[36];
	strcpy(regularString, "I am a string which can be modified");
	char *anotherRegularString = new char[21];
	strcpy(anotherRegularString, "I am also modifiable");
	// Define a const ptr to a const object. Must be initialized
	const char *const constStringandPtr = regularString; // Ok
	// Trying to change the pointer or the data is illegal
	constStringandPtr = anotherRegularString; //No! Can't mod addr
	strcpy(constStringandPtr, "Nope"); // No! Can't mod data

	return (0);
}
