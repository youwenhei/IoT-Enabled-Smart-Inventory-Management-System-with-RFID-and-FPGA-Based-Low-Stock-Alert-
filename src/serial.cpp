#include <iostream>
#include "Serial.h"

Serial::Serial(const char* port)
{
	hSerial = INVALID_HANDLE_VALUE;
	
	hSerial = CreateFileA(
		port,
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		0,
		NULL
	);

	if (hSerial != INVALID_HANDLE_VALUE)
	{
		DCB dcbSerialParams = { 0 };

		dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

		GetCommState(hSerial, &dcbSerialParams);

		dcbSerialParams.BaudRate = CBR_115200;
		dcbSerialParams.ByteSize = 8;
		dcbSerialParams.StopBits = ONESTOPBIT;
		dcbSerialParams.Parity = NOPARITY;

		SetCommState(hSerial, &dcbSerialParams);
	}
}

Serial::~Serial()
{
	if (hSerial != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hSerial);
	}
}

bool Serial::isConnected()
{
	return hSerial != INVALID_HANDLE_VALUE;
}

std::string Serial::readLine()
{
	char buffer[128];
	DWORD bytesRead;

	std::string result = "";

	while (true)
	{
		if (ReadFile(hSerial, buffer, 1, &bytesRead, NULL))
		{
			if (bytesRead > 0)
			{
				if (buffer[0] == '\n')
					break;

				result += buffer[0];
			}
		}
	}

	return result;
}
