#ifndef __TMH_TYPES_MATH_HPP
#define __TMH_TYPES_MATH_HPP

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
}

#endif