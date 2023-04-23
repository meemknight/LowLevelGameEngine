#pragma once
#include <core.h>

//use namespaces
namespace LLGE
{
    namespace LLM
    {
        template<class T>
        struct Impl // defining operations for the Vectors.
        {
            T operator-()
            {
                auto ret = *(T*)this;
                for (int i = 0; i < T::Size; i++)
                {
                    ret.data[i] = -ret.data[i];
                }
                return ret;
            }

            T operator-(T other)
            {
                auto ret = *(T*)this;
                for (int i = 0; i < T::Size; i++)
                {
                    ret.data[i] -= other.data[i];
                }
                return ret;
            }

            T operator+(T other)
            {
                auto ret = *(T*)this;
                for (int i = 0; i < T::Size; i++)
                {
                    ret.data[i] += other.data[i];
                }
                return ret;
            }

            T operator/(T other)
            {
                auto ret = *(T*)this;
                for (int i = 0; i < T::Size; i++)
                {
                    ret.data[i] /= other.data[i];
                }
                return ret;
            }

            T operator*(T other)
            {
                auto ret = *(T*)this;
                for (int i = 0; i < T::Size; i++)
                {
                    ret.data[i] *= other.data[i];
                }
                return ret;
            }

            T operator&(T other)
            {
                auto ret = *(T*)this;
                for (int i = 0; i < T::Size; i++)
                {
                    ret.data[i] &= other.data[i];
                }
                return ret;
            }

            T operator|(T other)
            {
                auto ret = *(T*)this;
                for (int i = 0; i < T::Size; i++)
                {
                    ret.data[i] |= other.data[i];
                }
                return ret;
            }

            T operator^(T other)
            {
                auto ret = *(T*)this;
                for (int i = 0; i < T::Size; i++)
                {
                    ret.data[i] ^= other.data[i];
                }
                return ret;
            }

            T operator+=(T other)
            {
                *(T*)this = *(T*)this + other;

                return *(T*)this;
            }

            T operator-=(T other)
            {
                *(T*)this = *(T*)this - other;

                return *(T*)this;
            }

            T operator/=(T other)
            {
                *(T*)this = *(T*)this / other;

                return *(T*)this;
            }

            T operator*=(T other)
            {
                *(T*)this = *(T*)this * other;

                return *(T*)this;
            }

            T operator&=(T other)
            {
                *(T*)this = *(T*)this & other;

                return *(T*)this;
            }

            T operator|=(T other)
            {
                *(T*)this = *(T*)this | other;

                return *(T*)this;
            }

            T operator^=(T other)
            {
                *(T*)this = *(T*)this ^ other;

                return *(T*)this;
            }

        };


        template<class T>
        struct Vector2 : public Impl<Vector2<T>>
        {
            using Type = T;
            constexpr static auto Size = 2;

            union
            {
                struct
                {
                    T x, y;
                };
                T data[Size];
            };

            Vector2(T _x, T _y)
            {
                x = _x;
                y = _y;
            };

        };

        // Vector2 aliases
        typedef Vector2<float> vec2;
        typedef Vector2<float> vec2f;
        typedef Vector2<float> Vector2f;
        typedef Vector2<int> vec2i;
        typedef Vector2<int> Vector2i;
        typedef Vector2<unsigned int> vec2u;
        typedef Vector2<unsigned int> Vector2u;

        template<class T>
        struct Vector3 : public Impl<Vector3<T>>
        {
            using Type = T;
            constexpr static auto Size = 3;
            union
            {
                struct
                {
                    T x, y, z;
                };
                T data[Size];
            };

            Vector3(T _x, T _y, T _z)
            {
                x = _x;
                y = _y;
                z = _z;
            };
        };

        // Vector3 aliases
        typedef Vector3<float> vec3;
        typedef Vector3<float> vec3f;
        typedef Vector3<float> Vector3f;
        typedef Vector3<int> vec3i;
        typedef Vector3<int> Vector3i;
        typedef Vector3<unsigned int> vec3u;
        typedef Vector3<unsigned int> Vector3u;
    };
};