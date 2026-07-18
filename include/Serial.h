#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <string>

class Serial
{
private:
	HANDLE hSerial;

public:
	Serial(const char* port);
	~Serial();

	bool isConnected();
	std::string readLine();
};

#endif
