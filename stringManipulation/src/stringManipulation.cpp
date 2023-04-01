#include <stringManipulation.h>

namespace LLGE
{
	namespace stringManipulation
	{
		//when implementing this functions try to not repeat yourself
		size_t stringManipulation::findChar(std::string_view source, char character)
		{
			static size_t index=0;
			if(source.size() >= index)
			{

				if (source[index] != character)
				{
					index++;
					findChar(source, character);
				}
				else
				{
					return index;
				}
			}
			else
			{
				return (size_t)-1;
			}
		}
		void stringManipulation::toLower(std::string_view source, std::string& dest)
		{
			size_t index=0;
			while(index<=source.size())
			{

				if ((int)source[index] >= 65 && (int)source[index] <= 90)
				{
					dest+= char(((int)source[index]) + 32);

				}
				else {
					dest += source[index];
				}
				index++;
			}
		}

	};
};