#include "Line2D.h"

//---------------------------------------------------------------------------------------

TLine2D::TLine2D
(
    const TPoint2D& FirstPoint,
    const TPoint2D& SecondPoint
) :
    First(FirstPoint),
    Second(SecondPoint)
{}

TVector2D TLine2D::GetDirection() const
{
    return ToVector();
}

TVector2D TLine2D::ToVector() const
{
    return Second - First;
}

std::ostream& operator<<(std::ostream& OStream, const TLine2D& Line)
{
    OStream << Line.First << " - " << Line.Second;

    return OStream;
}
