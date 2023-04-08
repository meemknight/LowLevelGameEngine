#include <stringManipulation.h>

namespace LLGE
{
	namespace stringManipulation
	{
		
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
				return NPOS;
			}
			return index;
		}
		void stringManipulation::toLower(std::string_view source, std::string &dest)
		{
			size_t index = 0;
			while (index <= source.size())
			{

				if ((int)source[index] >= 65 && (int)source[index] <= 90)
				{
					dest += (char)(((int)source[index]) + 32);

				}
				else
				{
					dest += source[index];
				}
				index++;
			}
		}

		void stringManipulation::toUpper(std::string_view source, std::string &dest)
		{
			size_t index = 0;

			while (index <= source.size())
			{
				if ((int)source[index] >= 97 && (int)source[index] <= 122)
				{
					dest += (char)(((int)source[index]) - 32);
				}
				else
				{
					dest += source[index];
				}
				index++;
			}

		}

		//todo 'A' instead of 65 etc
		void stringManipulation::toLower(std::string_view source, char *dest, size_t destSize)
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
		void stringManipulation::toUpper(std::string_view source, char *dest, size_t destSize)
		{
			size_t index = 0;

			while (index < destSize && index <= source.size())
			{
				if ((int)source[index] >= 97 && (int)source[index] <= 122)
					*(dest + index) = (char)(((int)source[index]) - 32);
				else
					*(dest + index) = source[index];

				index++;
			}
		}

		//todo refactor
		void stringManipulation::removeCharacters(std::string_view source, char *dest, std::string_view charsToRemove, size_t destSize)
		{
			size_t i = 0, dIndex = 0;
			std::string temp{source};
			struct chars
			{
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
		std::vector<std::string> stringManipulation::split(std::string_view source, char c)
		{
		std::vector<std::string> spString;
		int64_t indexLeft=0,indexRight = -1;	//if indexRight will be initialised as 0 and if source[0] == ch then length will be -1.
		uint32_t length;
		for (uint32_t i = 0; i < source.size(); i++)
		{
			if (source[i] == c)
			{
				indexLeft = indexRight;
				indexRight =i;
				length = indexRight- (indexLeft + 1);
		
				if (length != 0)
				{
					std::string subString(source.data() + (indexLeft + 1), length);
					spString.push_back(subString);
				}
			}
		}
		std::string lastSubString(source.data() + indexRight + 1, source.size() - indexRight - 1);
		spString.push_back(lastSubString);

		return spString;
		}

		size_t stringManipulation::strlcpy(std::string_view source, char* dst, size_t size)
		{
			for (size_t i = 0; i <= source.size(); i++)
			{
				if (*dst == source[i])
				{
					return i;
				}
			}
			return source.max_size(); // return -1;
		}
		void stringManipulation::removeWords(std::string_view source, char *dest ,std::vector<std::string> words, size_t destSize)
		{
			std::string finalString;
			std::string strLower;
			toLower(source, strLower);
			for(uint32_t i = 0;i<words.size();i++)
			{
				toLower(words[i], words[i]);
			}
			std::vector<std::string> stringWords = split(source,' ');
			for (uint32_t i = 0; i < stringWords.size(); i++)
			{
				for (uint32_t j = 0; j < words.size(); j++)
				{
					if (stringWords[i]==words[j])
					{

					}
				}
			}
			//return finalString;
		}
	};
};