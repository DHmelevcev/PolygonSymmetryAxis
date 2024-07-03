#include <cmath>

#include "Point2D.h"

//---------------------------------------------------------------------------------------

TPoint2D::TPoint2D() :
    X(0.),
    Y(0.)
{}

//---------------------------------------------------------------------------------------

TPoint2D::TPoint2D
(
    double Value
) :
    X(Value),
    Y(Value)
{}

//---------------------------------------------------------------------------------------

TPoint2D::TPoint2D
(
    double ValueX,
    double ValueY
) :
    X(ValueX),
    Y(ValueY)
{}

//---------------------------------------------------------------------------------------

bool TPoint2D::operator==
(
    const TPoint2D& Other
)
const
{
    return (
        std::abs(X - Other.X) < eps &&
        std::abs(Y - Other.Y) < eps
    );
}

//---------------------------------------------------------------------------------------

bool TPoint2D::operator!=
(
    const TPoint2D& Other
)
const
{
    return (
        std::abs(X - Other.X) >= eps ||
        std::abs(Y - Other.Y) >= eps
    );
}

//---------------------------------------------------------------------------------------

bool TPoint2D::IsValid() const
{
    return (
        !isnan(X) &&
        !isnan(Y) &&
        !isinf(X) &&
        !isinf(Y)
    );
}

//---------------------------------------------------------------------------------------

std::istream& operator>>(std::istream& IStream, TPoint2D& Point)
{
    if (IStream >> Point.X)
        IStream >> Point.Y;

    return IStream;
}

//---------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& OStream, const TPoint2D& Point)
{
    OStream << Point.X << " " << Point.Y;

    return OStream;
}
