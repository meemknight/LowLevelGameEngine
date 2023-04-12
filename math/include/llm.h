#pragma once
#include <core.h>

//use namespaces
namespace LLGE
{
	namespace LLM
	{
		template<typename T>
		struct vec2s
		{
			T x, y;
		};

		typedef vec2s<float> vec2;
		typedef vec2s<int> vec2i;
		typedef vec2s<unsigned int> vec2u;

		template<typename T>
		inline
			T operator+(T a, T b)
		{
			return T{ a.x + b.x, a.y + b.y };
		}

		template<typename T>
		inline
			T operator-(T a, T b)
		{
			return T{ a.x - b.x, a.y - b.y };
		}

		template<typename T>
		inline
			T operator*(T a, T b)
		{
			return T{ a.x * b.x, a.y * b.y };
		}

		template<typename T>
		inline
			T operator/(T a, T b)
		{
			return T{ a.x / b.x, a.y / b.y };
		}

		template<typename T>
		inline
			T operator+=(T& a, T b)
		{
			a = a + b;
			return a;
		}

		template<typename T>
		inline
			T operator-=(T& a, T b)
		{
			a = a - b;
			return a;
		}

		template<typename T>
		inline
			T operator/=(T& a, T b)
		{
			a = a / b;
			return a;
		}

		template<typename T>
		inline
			T operator*=(T& a, T b)
		{
			a = a * b;
			return a;
		}

		template<typename T>
		inline
			T operator+(float a, T b)
		{
			return T{ a + b.x, a + b.y };
		}

		template<typename T>
		inline
			T operator+(T a, float b)
		{
			return T{ a.x + b, a.y + b };
		}

		template<typename T>
		inline
			T operator-(float a, T b)
		{
			return T{ a - b.x, a - b.y };
		}

		template<typename T>
		inline
			T operator-(T a, float b)
		{
			return T{ a.x - b, a.y - b };
		}

		template<typename T>
		inline
			T operator*(float a, T b)
		{
			return T{ a * b.x, a * b.y };
		}

		template<typename T>
		inline
			T operator*(T a, float b)
		{
			return T{ a.x * b, a.y * b };
		}

		template<typename T>
		inline
			T operator/(float a, T b)
		{
			return T{ a / b.x, a / b.y };
		}

		template<typename T>
		inline
			T operator/(T a, float b)
		{
			return T{ a.x / b, a.y / b };
		}

	};
};