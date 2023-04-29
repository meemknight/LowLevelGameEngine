#pragma once

#include <fileManipulation.h>
#include <testing.h>
#include <logging.h>

struct TestStruct
{
	int a = 234;
	float b = 0.124;
	char c = 'c';

	bool operator==(TestStruct &other)
	{
		return a == other.a && b == other.b && c == other.c;
	}
};

inline TestRezult fileManipulationTest()
{
	TestRezult rezult;

	rezult.testName = std::string("File manipulation ") + LLGE::fileManipulation::getBackendName();

	//one test
	{
		rezult.totalTests++;
		TestStruct t;

		if (LLGE::fileManipulation::writeEntireFileBinary(LLGE_TESTS_FOLDER_PATH "/fileManip.txt", &t, sizeof(t)))
		{
			TestStruct t2;
			t2.a = 0;
			t2.b = 0;
			t2.c = 0;

			if (LLGE::fileManipulation::readEntireFileBinary(LLGE_TESTS_FOLDER_PATH "/fileManip.txt", &t2, sizeof(t2)))
			{

				if (t2 == t)
				{
					rezult.testPassed++;
				}
				else
				{
					LLGE::Logging::printColoured("File read but data was incorect", LLGE::Logging::LogSeverity::LOG_ERROR);
				}

			}
			else
			{
				LLGE::Logging::printColoured("Error reading file in the first test", LLGE::Logging::LogSeverity::LOG_ERROR);
			}

		}
		else
		{
			LLGE::Logging::printColoured("Error writing file in the first test", LLGE::Logging::LogSeverity::LOG_ERROR);
		}
	}


	return rezult;
}