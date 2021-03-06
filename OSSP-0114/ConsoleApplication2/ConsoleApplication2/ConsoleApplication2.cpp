// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <xmmintrin.h>	
#include <math.h>	
#include <windows.h>
#include <intrin.h>
#include <bitset>
#include <vector>
#include <string>
#include <array>

bool SSECheck()
{
	std::vector<std::array<int, 4>> Dat;
	std::array<int, 4> InfoCp;
	__cpuid(InfoCp.data(), 0);
	int nIds = InfoCp[0];
	for (int i = 0; i <= nIds; i++)
	{
		__cpuidex(InfoCp.data(), i, 0);
		Dat.push_back(InfoCp);
	}
	std::string vendors;
	char vendor[0x20];
	memset(vendor, 0, sizeof(vendor));
	*reinterpret_cast<int*>(vendor) = Dat[0][1];
	*reinterpret_cast<int*>(vendor + 4) = Dat[0][3];
	*reinterpret_cast<int*>(vendor + 8) = Dat[0][2];
	vendors = vendor;
	std::bitset<32> f;
	f = Dat[1][3];
	if (f[25])
	{
		return true;
	}
	return false;
}

int main()
{
	printf("Starting calculation...\n");
	const int length = 64000;

	// We will be calculating Y = Sin(x) / x, for x = 1->64000

	// If you do not properly align your data for SSE instructions, you may take a huge performance hit.
	float *pResult = (float*)_aligned_malloc(length * sizeof(float), 16);	// align to 16-byte for SSE
	__m128 x;
	__m128 xDelta = _mm_set1_ps(4.0f);		// Set the xDelta to (4,4,4,4)
	__m128 *pResultSSE = (__m128*) pResult;

	const int SSELength = length / 4;
	for (int stress = 0; stress < 100; stress++)	// lots of stress loops so we can easily use a stopwatch
	{
		if (SSECheck())
		{
			x = _mm_set_ps(4.0f, 3.0f, 2.0f, 1.0f);	// Set the initial values of x to (4,3,2,1)
			for (int i = 0; i < SSELength; i++)
			{
				__m128 xSqrt = _mm_sqrt_ps(x);
				__m128 xRecip = _mm_rcp_ps(x);
				pResultSSE[i] = _mm_mul_ps(xRecip, xSqrt);
				x = _mm_add_ps(x, xDelta);	// Advance x to the next set of numbers
			}
		}
		else {
			float xFloat = 1.0f;
			for (int i = 0; i < length; i++)
			{
				pResult[i] = sqrt(xFloat) / xFloat;	// Even though division is slow, there are no intrinsic functions like there are in SSE
				xFloat += 1.0f;
			}
		}
	}

	// To prove that the program actually worked
	for (int i = 0; i < 20; i++)
	{
		printf("Result[%d] = %f\n", i, pResult[i]);
	}
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
