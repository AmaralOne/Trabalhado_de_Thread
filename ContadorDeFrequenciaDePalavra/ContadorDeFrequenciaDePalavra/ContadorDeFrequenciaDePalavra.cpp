// ContadorDeFrequenciaDePalavra.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
// REDES.cpp : define o ponto de entrada para o aplicativo do console.
//

//#include "stdafx.h"
#include <SDKDDKVer.h>
#include <Windows.h>
#include <list>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <math.h>

struct SThreadInfo
{
public:
	__int32 i_ThreadID;
	std::string buffer;
	std::list<char> chars;
	HANDLE h_Thread;
};


const DWORD WINAPI dwStartThread(SThreadInfo *pThreadInfo)
{
	for (int i = 0; i < pThreadInfo->buffer.size(); i++)
		for (int x = (i + 1); x < pThreadInfo->buffer.size(); x++)
			if (pThreadInfo->buffer[i] == pThreadInfo->buffer[x])
				pThreadInfo->chars.push_back(pThreadInfo->buffer[i]);

	return EXIT_SUCCESS;
}

int main(void)
{
	std::ifstream file("entrada.txt");
	std::string lineBuffer;
	std::list<SThreadInfo*> objThreadInfoList;
	__int32 i_ThreadID = 1;

	while (std::getline(file, lineBuffer))
	{
		SThreadInfo *pThreadInfo = new SThreadInfo();

		pThreadInfo->i_ThreadID = i_ThreadID;
		pThreadInfo->buffer = lineBuffer;
		pThreadInfo->h_Thread =
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)dwStartThread, pThreadInfo, 0, 0);

		WaitForSingleObject(pThreadInfo->h_Thread, INFINITE);

		i_ThreadID++;
		objThreadInfoList.push_back(pThreadInfo);
	}

	while (!objThreadInfoList.empty())
	{
		printf("Thread ( %i ) , Num. Repetencias: %i\n",
			objThreadInfoList.front()->i_ThreadID,
			objThreadInfoList.front()->chars.size());

		TerminateThread(objThreadInfoList.front()->h_Thread, EXIT_SUCCESS);
		CloseHandle(objThreadInfoList.front()->h_Thread);
		delete objThreadInfoList.front();
		objThreadInfoList.pop_front();
	}

	system("pause");
}