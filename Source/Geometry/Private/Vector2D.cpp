#include "Vector2D.h"

//---------------------------------------------------------------------------------------

TVector2D::TVector2D
(
    const TPoint2D& Point
) :
    TPoint2D(Point)
{}

//---------------------------------------------------------------------------------------

TVector2D& TVector2D::operator+=
(
    const TVector2D& Other
)
{
    X += Other.X;
    Y += Other.Y;

    return *this;
}

//---------------------------------------------------------------------------------------

TVector2D& TVector2D::operator-=
(
    const TVector2D& Other
)
{
    X -= Other.X;
    Y -= Other.Y;

    return *this;
}

//---------------------------------------------------------------------------------------

TVector2D& TVector2D::Normalize()
{
    return *this /= Size();
}

//---------------------------------------------------------------------------------------

TVector2D TVector2D::operator+
(
    const TVector2D& Other
)
const
{
    return {
        X + Other.X,
        Y + Other.Y
    };
}

//---------------------------------------------------------------------------------------

TVector2D TVector2D::operator-
(
    const TVector2D& Other
)
const
{
    return {
        X - Other.X,
        Y - Other.Y
    };
}

//---------------------------------------------------------------------------------------

double TVector2D::Size() const
{
    return sqrt(SizeSquared());
}

//---------------------------------------------------------------------------------------

double TVector2D::SizeSquared() const
{
    return (
        X * X +
        Y * Y
    );
}

//---------------------------------------------------------------------------------------

double TVector2D::operator|
(
    const TVector2D& Other
)
const
{
    return (
        X * Other.X +
        Y * Other.Y
    );
}

//---------------------------------------------------------------------------------------

double TVector2D::operator^
(
    const TVector2D& Other
)
const
{
    return (
        X * Other.Y -
        Y * Other.X
    );
}

//---------------------------------------------------------------------------------------

double TVector2D::Dot
(
    const TVector2D& Other
)
const
{
    return *this | Other;
}

//---------------------------------------------------------------------------------------

double TVector2D::Skew
(
    const TVector2D& Other
)
const
{
    return *this ^ Other;
}

//---------------------------------------------------------------------------------------

double TVector2D::DotProduct
(
    const TVector2D& First,
    const TVector2D& Second
)
{
    return First | Second;
}

//---------------------------------------------------------------------------------------

double TVector2D::SkewProduct
(
    const TVector2D& First,
    const TVector2D& Second
)
{
    return First ^ Second;
}
