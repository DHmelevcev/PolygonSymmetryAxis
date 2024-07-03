#pragma once

#include <vector>

#include "Line2D.h"

//---------------------------------------------------------------------------------------

/*
* Polygon in 2 dimensional space.
*
* Defined by array of points.
*
* Methods allows to get barycenter and all axis of symmetry.
*/
class TPolygon2D
{
public:
    std::vector<TPoint2D> Vertices;

public:
    /*
    * Default constructor initialises Vertices as empty array.
    */
    TPolygon2D() = default;

    /*
    * Constructor from std::istream.
    */
    TPolygon2D(std::istream& IStream);

    /*
    * Constructor from std::istream.
    */
    TPolygon2D(std::istream&& IStream);

    /*
    * Constructor from file.
    *
    * Vertices coordinates should be separated by whitespaces or newlines.
    */
    TPolygon2D(const char* Filename);

public:
    /*
    * Gets Barycenter (center of masses) of polygon.
    *
    * @return Barycenter.
    */
    TVector2D GetBarycenter() const;

    /*
    * Gets all axis of symmetry of polygon.
    *
    * Uses Knuth–Morris–Pratt algorithm from
    * Optimal Algorithms for Symmerty Detection in Two and Three Dimenssions by
    * Jay D. Wolter
    * Tony C. Woo
    * Richard A. Volz
    * Feb 1985.
    *
    * @return Array of symmetry Lines.
    */
    std::vector<TLine2D> GetAllAxisOfSymmetry() const;

private:
    /*
    * Encodes each edge of polygon into TPoint2D where
    * X = edge length.
    * Y = sine of angle between that and previous edge.
    *
    * @return Array of encoded edges.
    */
    std::vector<TPoint2D> GetCycle() const;
};

//---------------------------------------------------------------------------------------

/*
* Reads Vertices from std::istream.
*/
std::istream& operator>>(std::istream& IStream, TPolygon2D& Polygon);

//---------------------------------------------------------------------------------------

/*
* Writes Vertices to std::ostream with newline separator.
*/
std::ostream& operator<<(std::ostream& OStream, const TPolygon2D& Polygon);
