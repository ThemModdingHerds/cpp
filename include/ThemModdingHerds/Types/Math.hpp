#ifndef __TMH_TYPES_MATH_HPP
#define __TMH_TYPES_MATH_HPP

#include <ostream>

namespace ThemModdingHerds::Types::Math
{
    struct Vector2
    {
        union {
            struct
            {
                float x;
                float y;
            };
            float data[2];
        };
    };
    inline std::ostream& operator<<(std::ostream& os,const Vector2 &vec)
    {
        os << '(' << vec.x << ',' << vec.y << ')';
        return os;
    }
    struct Vector3
    {
        union {
            struct
            {
                float x;
                float y;
                float z;
            };
            float data[3];
        };
    };
    inline std::ostream& operator<<(std::ostream& os,const Vector3 &vec)
    {
        os << '(' << vec.x << ',' << vec.y << ',' << vec.z << ')';
        return os;
    }
    struct Vector4
    {
        union {
            struct
            {
                float x;
                float y;
                float z;
                float w;
            };
            float data[4];
        };
    };
    inline std::ostream& operator<<(std::ostream& os,const Vector4 &vec)
    {
        os << '(' << vec.x << ',' << vec.y << ',' << vec.z << ',' << vec.w << ')';
        return os;
    }
    struct Matrix4x4
    {
        union {
            struct
            {
                float m11;
                float m12;
                float m13;
                float m14;

                float m21;
                float m22;
                float m23;
                float m24;

                float m31;
                float m32;
                float m33;
                float m34;

                float m41;
                float m42;
                float m43;
                float m44;
            };
            float data[16];
        };
    };
    inline std::ostream& operator<<(std::ostream& os,const Matrix4x4 &mat)
    {
        os << "[[" << mat.m11 << ',' << mat.m12 << ',' << mat.m13 << mat.m14 << "],[" << mat.m21 << ',' << mat.m22 << ',' << mat.m23 << mat.m24 << "],[" << mat.m31 << ',' << mat.m32 << ',' << mat.m33 << mat.m34 << "],[" << mat.m41 << ',' << mat.m42 << ',' << mat.m43 << mat.m44 << "]]";
        return os;
    }
}

#endif