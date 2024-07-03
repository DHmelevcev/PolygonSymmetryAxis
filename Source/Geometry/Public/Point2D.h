#pragma once

#include <iostream>

//---------------------------------------------------------------------------------------

/*
* Point in 2 dimensional space.
*
* Contains two values representing X and Y coordinates.
*
* Methods allows to compare points for a match with tolerance = eps.
*/
class TPoint2D
{
public:
    struct {
        double X;
        double Y;
    };

public:
    // Tolerance
    inline static constexpr double eps = 1e-12;

public:
    /*
    * Default constructor initialises X and Y with zeroes.
    */
    TPoint2D();

    /*
    * Ñonstructor initialises X and Y with Value.
    *
    * @param Value for X and Y.
    */
    TPoint2D(double Value);

    /*
    * Ñonstructor initialises X with ValueX and Y with ValueY.
    *
    * @param ValueX for X.
    * @param ValueY for Y.
    */
    TPoint2D(double ValueX, double ValueY);

public:
    /*
    * Compare points for a match with tolerance = eps.
    *
    * @param Other point.
    */
    bool operator==(const TPoint2D& Other) const;

    /*
    * Compare points for a mismatch with tolerance = eps.
    * 
    * @param Other point.
    */
    bool operator!=(const TPoint2D& Other) const;

    /*
    * Checks X and Y for nan and inf values.
    */
    bool IsValid() const;
};

//---------------------------------------------------------------------------------------

/*
* Reads X and Y values from std::istream.
*/
std::istream& operator>>(std::istream& IStream, TPoint2D& Point);

//---------------------------------------------------------------------------------------

/*
* Writes X and Y values to std::ostream with whitespace separator.
*/
std::ostream& operator<<(std::ostream& OStream, const TPoint2D& Point);
