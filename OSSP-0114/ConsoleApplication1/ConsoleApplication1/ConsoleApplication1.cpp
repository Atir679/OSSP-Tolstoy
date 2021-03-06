// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <tchar.h>

int main()
{
	setlocale(0, "");
	SYSTEM_INFO SysInfo;
	GetSystemInfo(&SysInfo);
	_tprintf(TEXT("Information from GetSystemInfo: \n"));
	_tprintf(TEXT("OEM ID: %u\n"), SysInfo.dwOemId);
	_tprintf(TEXT("CPU system architecture: %u\n"), SysInfo.wProcessorArchitecture);
	_tprintf(TEXT("wReserved: %u\n"), SysInfo.wReserved);
	_tprintf(TEXT("Number of processors: %u\n"), SysInfo.dwNumberOfProcessors);
	_tprintf(TEXT("Page size: %u\n"), SysInfo.dwPageSize);
	_tprintf(TEXT("Minimum application address: %lx\n"), SysInfo.lpMinimumApplicationAddress);
	_tprintf(TEXT("Maximum application address: %lx\n"), SysInfo.lpMaximumApplicationAddress);
	_tprintf(TEXT("Active processor mask: %u\n"), SysInfo.dwActiveProcessorMask);
	_tprintf(TEXT("Processor type: %u\n"), SysInfo.dwProcessorType);
	_tprintf(TEXT("Granularity: %u\n"), SysInfo.dwAllocationGranularity);
	_tprintf(TEXT("The level of the architecturally dependent processor of the system: %u\n"), SysInfo.wProcessorLevel);
	_tprintf(TEXT("Revision of the architecturally dependent processor: %u\n"), SysInfo.wProcessorRevision);
	system("pause");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
