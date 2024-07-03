#pragma once

#include <type_traits>

#include "Point2D.h"

//---------------------------------------------------------------------------------------

/*
* Vector in 2 dimensional space.
*
* Methods allows to do linear operations and vector products.
*/
class TVector2D : public TPoint2D
{
public:
    /*
    * TPoint2D constructors.
    */
    using TPoint2D::TPoint2D;

    /*
    * Constructor from TPoint2D.
    */
    TVector2D(const TPoint2D& Point);

    /*
    * Adds Other vector components to this vector components.
    *
    * @param Other vector to add to this.
    * @return reference to this vector
    */
    TVector2D& operator+=(const TVector2D& Other);

    /*
    * Subtracts Other vector components from this vector components.
    *
    * @param Other vector to subtract from this.
    * @return reference to this vector
    */
    TVector2D& operator-=(const TVector2D& Other);

    /*
    * Scales the vector.
    *
    * @param Scale to multiply vector components.
    * @return reference to this vector
    */
    template<typename TArg>
    TVector2D& operator*=(TArg Scale);

    /*
    * Scales the vector.
    *
    * @param Scale to divide vector components.
    * @return reference to this vector
    */
    template<typename TArg>
    TVector2D& operator/=(TArg Scale);

    /*
    * Normalizes the vector (Size == 1.).
    *
    * @return reference to this vector
    */
    TVector2D& Normalize();

public:
    /*
    * Adds Other vector and this vector components.
    *
    * @param Other vector to add with this.
    * @return Vector of summ.
    */
    TVector2D operator+(const TVector2D& Other) const;

    /*
    * Subtracts Other vector from this vector components.
    *
    * @param Other vector to subtract from this.
    * @return Vector of difference.
    */
    TVector2D operator-(const TVector2D& Other) const;

    /*
    * Scales the vector.
    *
    * @param Scale to multiply vector components.
    * @return Scaled vector
    */
    template<typename TArg>
    TVector2D operator*(TArg Scale) const;

    /*
    * Scales the vector.
    *
    * @param Scale to divide vector components.
    * @return Scaled vector
    */
    template<typename TArg>
    TVector2D operator/(TArg Scale) const;

    /*
    * Gets size (length) of the vector.
    *
    * @return Vector size.
    */
    double Size() const;

    /*
    * Gets squared size (length) of the vector.
    * Faster than TVector2D::Size.
    *
    * @return Vector squared size.
    */
    double SizeSquared() const;

    /*
    * Gets the Dot product with Other vector.
    *
    * @param Other Vector.
    * @return Dot product.
    */
    double operator|(const TVector2D& Other) const;

    /*
    * Gets the Skew product with Other vector.
    *
    * @param Other Vector.
    * @return Skew product.
    */
    double operator^(const TVector2D& Other) const;

    /*
    * Gets the Dot product with Other vector.
    *
    * @param Other Vector.
    * @return Dot product.
    */
    double Dot(const TVector2D& Other) const;

    /*
    * Gets the Skew product with Other vector.
    *
    * @param Other Vector.
    * @return Skew product.
    */
    double Skew(const TVector2D& Other) const;

public:
    /*
    * Gets the Dot product of two vectors.
    *
    * @param First vector.
    * @param Second vector.
    * @return Dot product.
    */
    static double DotProduct(const TVector2D& First, const TVector2D& Second);

    /*
    * Gets the Skew product of two vectors.
    *
    * @param First vector.
    * @param Second vector.
    * @return Skew product.
    */
    static double SkewProduct(const TVector2D& First, const TVector2D& Second);
};

//---------------------------------------------------------------------------------------

template<typename TArg>
inline TVector2D& TVector2D::operator*=
(
    TArg Scale
)
{
    static_assert(
        std::is_arithmetic_v<TArg>,
        "Vector2D scaling requires arithmetic type"
    );

    X *= Scale;
    Y *= Scale;

    return *this;
}

//---------------------------------------------------------------------------------------

template<typename TArg>
inline TVector2D& TVector2D::operator/=
(
    TArg Scale
)
{
    static_assert(
        std::is_arithmetic_v<TArg>,
        "Vector2D scaling requires arithmetic type"
    );

    X /= Scale;
    Y /= Scale;

    return *this;
}

//---------------------------------------------------------------------------------------

template<typename TArg>
inline TVector2D TVector2D::operator*
(
    TArg Scale
)
const
{
    static_assert(
        std::is_arithmetic_v<TArg>,
        "Vector3 scaling requires arithmetic type"
    );

    return {
        X * Scale,
        Y * Scale
    };
}

//---------------------------------------------------------------------------------------

template<typename TArg>
inline TVector2D TVector2D::operator/
(
    TArg Scale
)
const
{
    static_assert(
        std::is_arithmetic_v<TArg>,
        "Vector3 scaling requires arithmetic type"
    );

    return {
        X / Scale,
        Y / Scale
    };
}
