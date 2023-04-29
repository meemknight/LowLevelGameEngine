#pragma once
#include <string>

struct TestRezult
{
	std::string testName;
	unsigned int testPassed = 0;
	unsigned int totalTests = 0;
};


TestRezult testFunctionExample()
{
	return {};
}