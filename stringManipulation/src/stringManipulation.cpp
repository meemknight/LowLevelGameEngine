#include <stringManipulation.h>

namespace LLGE
{
	namespace stringManipulation
	{
		//when implementing this functions try to not repeat yourself
		size_t stringManipulation::findChar(std::string_view source, char character)
		{

			size_t index = 0;
			for (; index <= source.size(); index++)
			{
				if (source[index] == character)
				{
					break;
				}
			}
			if (index > source.size())
			{
				return -1;
			}
			return index;
		}
		void stringManipulation::toLower(std::string_view source, std::string& dest)
		{
			size_t index=0;
			while(index<=source.size())
			{

				if ((int)source[index] >= 65 && (int)source[index] <= 90)
				{
					dest+= (char)(((int)source[index]) + 32);

				}
				else {
					dest += source[index];
				}
				index++;
			}
		}

		void stringManipulation::toUpper(std::string_view source, std::string& dest)
		{
			size_t index = 0;

			while (index <= source.size())
			{
				if ((int)source[index] >= 97 && (int)source[index] <= 122)
				{
					dest += (char)(((int)source[index]) - 32);
				}
				else {
					dest += source[index];
				}
				index++;
			}

		}

		void stringManipulation::toLower(std::string_view source, char* dest, size_t destSize)
		{
			size_t index = 0;
			while (index < destSize && index <= source.size())
			{
				if ((int)source[index] >= 65 && (int)source[index] <= 90)
					*(dest + index) = (char)(((int)source[index]) + 32);
				else
					*(dest + index) = source[index];

				index++;
			}
		}
		void stringManipulation::toUpper(std::string_view source, char* dest, size_t destSize) 
		{
			size_t index = 0;

			while (index < destSize && index <= source.size())
			{
				if ((int)source[index] >= 97 && (int)source[index] <= 122)
					*(dest+index)=(char)(((int)source[index]) - 32);
				else
					*(dest+index)= source[index];

				index++;
			}
		}

		void stringManipulation::removeCharacters(std::string_view source, char* dest, std::string_view charsToRemove, size_t destSize)
		{
			size_t i=0, dIndex=0;
			std::string temp{ source };
			struct chars {
				bool occurance = 1;

			}characters[256]; //here -128 = 0

			i = 0;
			while (i < charsToRemove.size())
			{
				characters[(int)charsToRemove[i] + 128].occurance = 0;
				i++;
			}
			i = 0;
			while (i <= destSize && i <= source.size())
			{
				if (characters[(int)source[i] + 128].occurance == 1)
				{
					*(dest + dIndex) = source[i];
					dIndex++;
				}
				i++;
			}

		}

	};
};