#pragma once
#include <core.h>

//use namespaces
namespace LLGE
{
	namespace LLM
	{
		struct vec2
		{
			float x, y;
		};

		inline
			vec2 operator+(LLM::vec2 a, LLM::vec2 b)
		{
			return vec2{ a.x + b.x, a.y + b.y };
		}

		inline
			vec2 operator-(LLM::vec2 a, LLM::vec2 b)
		{
			return vec2{ a.x - b.x, a.y - b.y };
		}

		inline
			vec2 operator*(LLM::vec2 a, LLM::vec2 b)
		{
			return vec2{ a.x * b.x, a.y * b.y };
		}

		inline
			vec2 operator/(LLM::vec2 a, LLM::vec2 b)
		{
			return vec2{ a.x / b.x, a.y / b.y };
		}

		inline
			vec2 operator+=(LLM::vec2& a, LLM::vec2 b)
		{
			a = a + b;
			return a;
		}

		inline
			vec2 operator-=(LLM::vec2& a, LLM::vec2 b)
		{
			a = a - b;
			return a;
		}

		inline
			vec2 operator/=(LLM::vec2& a, LLM::vec2 b)
		{
			a = a / b;
			return a;
		}

		inline
			vec2 operator*=(LLM::vec2& a, LLM::vec2 b)
		{
			a = a * b;
			return a;
		}

		inline
			vec2 operator+(float a, LLM::vec2 b)
		{
			return vec2{ a + b.x, a + b.y };
		}

		inline
			vec2 operator+(LLM::vec2 a, float b)
		{
			return vec2{ a.x + b, a.y + b };
		}

		inline
			vec2 operator-(float a, LLM::vec2 b)
		{
			return vec2{ a - b.x, a - b.y };
		}

		inline
			vec2 operator-(LLM::vec2 a, float b)
		{
			return vec2{ a.x - b, a.y - b };
		}

		inline
			vec2 operator*(float a, LLM::vec2 b)
		{
			return vec2{ a * b.x, a * b.y };
		}

		inline
			vec2 operator*(LLM::vec2 a, float b)
		{
			return vec2{ a.x * b, a.y * b };
		}

		inline
			vec2 operator/(float a, LLM::vec2 b)
		{
			return vec2{ a / b.x, a / b.y };
		}

		inline
			vec2 operator/(LLM::vec2 a, float b)
		{
			return vec2{ a.x / b, a.y / b };
		}
	}; 
};