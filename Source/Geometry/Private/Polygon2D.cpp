#include <numeric>
#include <algorithm>

#include <fstream>

#include "Polygon2D.h"

#include "Prefix.h"

//---------------------------------------------------------------------------------------

TPolygon2D::TPolygon2D
(
    std::istream& IStream
)
{
    IStream >> *this;
}

//---------------------------------------------------------------------------------------

TPolygon2D::TPolygon2D
(
    std::istream&& IStream
)
{
    IStream >> *this;
}

//---------------------------------------------------------------------------------------

TPolygon2D::TPolygon2D(const char* Filename)
{
    std::ifstream IStream(Filename);

    IStream >> *this;
}

//---------------------------------------------------------------------------------------

TVector2D TPolygon2D::GetBarycenter() const
{
    return std::accumulate(
        Vertices.begin(),
        Vertices.end(),
        TVector2D()
    ) / Vertices.size();
}

//---------------------------------------------------------------------------------------

std::vector<TLine2D> TPolygon2D::GetAllAxisOfSymmetry() const
{
    std::vector<TPoint2D> cycle = GetCycle();
    size_t cycle_size = cycle.size();

    std::vector<size_t> prefixes = PrefixFunction(cycle);

    std::vector<TLine2D> axis;
    std::vector<size_t> symmetrtyNodes;

    size_t k = 0;

    for (size_t i = 0; i < 2 * cycle_size - 1; ++i)
    {
        size_t j = (2 * cycle_size - i - 2) % cycle_size;

        // Maybe imposible?
        /*while (k > 0 &&
              (std::abs(cycle[k].X - cycle[j].X) >= TPoint2D::eps ||
               std::abs(cycle[k].Y - cycle[(j + 1) % cycle_size].Y) >= TPoint2D::eps))
        {
            k = prefixes[k - 1];
        }*/

        if (std::abs(cycle[k].X - cycle[j].X) < TPoint2D::eps &&
            std::abs(cycle[k].Y - cycle[(j + 1) % cycle_size].Y) < TPoint2D::eps)
        {
            ++k;
        }

        if (k == cycle_size)
        {
            symmetrtyNodes.emplace_back(2 * cycle_size - i - 2);
            
            k = prefixes[k - 1];
        }
    }

    for (auto it = symmetrtyNodes.rbegin(); it != symmetrtyNodes.rend(); ++it)
    {
        auto Node = *it;

        TPoint2D first = Node & 1 ?
            (TVector2D(
                Vertices[Node >> 1]) +
                Vertices[(Node + 1) >> 1]
            ) / 2
            :
            Vertices[Node >> 1];

        TPoint2D second = (cycle_size & 1) && !(Node & 1) ||
                          !(cycle_size & 1) && (Node & 1) ?
            (TVector2D(
                Vertices[(Node + cycle_size) >> 1]) +
                Vertices[((Node + cycle_size + 1) >> 1) % cycle_size]
            ) / 2
            :
            Vertices[((Node + cycle_size) >> 1) % cycle_size];

        axis.emplace_back(first, second);
    }

    return axis;
}

//---------------------------------------------------------------------------------------

std::vector<TPoint2D> TPolygon2D::GetCycle() const
{
    size_t points_size = Vertices.size();

    std::vector<TPoint2D> cycle;
    cycle.reserve(points_size);

    for (size_t i = 0; i < points_size; ++i)
    {
        size_t indexA = (points_size - 1 + i) % points_size;
        size_t indexB = i;
        size_t indexC = (i + 1) % points_size;

        TVector2D BC(TVector2D(Vertices[indexC]) - Vertices[indexB]);
        TVector2D AB(TVector2D(Vertices[indexB]) - Vertices[indexA]);

        double sizeAB = AB.Size();
        double sizeBC = BC.Size();

        cycle.push_back({
            sizeBC,
            (AB ^ BC) / (sizeAB * sizeBC)
        });
    }

    return cycle;
}

//---------------------------------------------------------------------------------------

std::istream& operator>>(std::istream& IStream, TPolygon2D& Polygon)
{
    Polygon.Vertices.clear();
    Polygon.Vertices.reserve(3);

    std::copy(
        std::istream_iterator<TPoint2D>(IStream),
        std::istream_iterator<TPoint2D>(),
        std::back_inserter(Polygon.Vertices)
    );

    return IStream;
}

//---------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& OStream, const TPolygon2D& Polygon)
{
    std::copy(
        Polygon.Vertices.begin(),
        Polygon.Vertices.end(),
        std::ostream_iterator<TPoint2D>(OStream, "\n")
    );

    return OStream;
}
