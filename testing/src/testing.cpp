#include <iostream>
#include <logging.h>
#include <window.h>
#include <testing.h>
#include <fileManipulationTest.h>
#include <vector>
#include <logging.h>
#include <stringManipulationTest.h>

using namespace LLGE::Logging;

int main()
{
	//don't forge to use LLGE_TESTS_FOLDER_PATH
	std::vector<TestRezult(*)()> tests;

	///here you can add tests
	tests.push_back(fileManipulationTest);
	tests.push_back(stringManipulationTest);



	///

#pragma region testing

	//todo change to a logger maybe
	printColoured("----LLGE TEST SUITE----\n", LogSeverity::LOG_INFO);

	printColoured("\n\n");

	for (int i = 0; i < tests.size(); i++)
	{
		printColoured("----Started Test----\n", LogSeverity::LOG_INFO);
		auto rez = tests[i]();

		printColoured("----Ended " + rez.testName +"----\n", LogSeverity::LOG_INFO);


		if (rez.testPassed > rez.totalTests) 
		{
			printColoured("Error: rez.testPassed > rez.totalTests\n", LogSeverity::LOG_ERROR);
		}
		else if (rez.testPassed == rez.totalTests)
		{
			//todo use the formatting library later
			printColoured("Result: All tests passed (" + std::to_string(rez.testPassed) + "/" + std::to_string(rez.totalTests) + ")\n", LogSeverity::LOG_INFO); //todo change to log_ok

		}
		else
		{
			printColoured("Result: Not all tests passed (" + std::to_string(rez.testPassed) + "/" + std::to_string(rez.totalTests) + ")\n", LogSeverity::LOG_ERROR);
		}

		printColoured("\n\n");

	}
#pragma endregion

	std::cin.get();
	return 0;


}