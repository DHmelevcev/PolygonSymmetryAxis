#pragma once

#include "Vector2D.h"

//---------------------------------------------------------------------------------------

/*
* Line in 2 dimensional space.
*
* Defined by two points.
*
* Methods allows to get direction of line.
*/
class TLine2D
{
public:
    TVector2D First;

    TVector2D Second;

public:
    /*
    * Constructor from two TPoint2D.
    */
    TLine2D(const TPoint2D& FirstPoint, const TPoint2D& SecondPoint);

public:
    /*
    * Get direction of line.
    *
    * @return Vector of direction.
    */
    TVector2D GetDirection() const;

    /*
    * Get direction of line.
    *
    * @return Vector of direction.
    */
    TVector2D ToVector() const;
};

//---------------------------------------------------------------------------------------

/*
* Writes First and Second points to std::ostream with hyphen separator.
*/
std::ostream& operator<<(std::ostream& OStream, const TLine2D& Polygon);
