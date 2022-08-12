#include<iostream>
#include<ctime>

using namespace std;

int main()
{
// Finding elapsed seconds and current second
	long elapsedSeconds = time(0);
	int currentSeconds = elapsedSeconds % 60;
// Finding elapsed minutes and current minute
	long elapsedMinutes = elapsedSeconds / 60;
	int currentMinutes = elapsedMinutes % 60;
// Finding elapsed hours and current hour
	long elapsedHours = elapsedMinutes / 60;
	int currentHour = elapsedHours % 24;
// Print current time
	cout <<"Current time: ";
	cout <<currentHour <<":" <<currentMinutes <<":" <<currentSeconds;

	return (0);
}
