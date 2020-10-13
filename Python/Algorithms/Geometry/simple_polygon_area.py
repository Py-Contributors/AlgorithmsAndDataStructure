from collections import namedtuple
from typing import List

Point = namedtuple('Point', 'x y')


def simple_polygon_area(points: List[Point]) -> float:
    """
    Calculates area of simple polygon given by a list of points.

    Assumes that points is a list of points in either clockwise
    or counter-clockwise order.

    Time Complexity: O(N)

    ------
    >>> simple_polygon_area([Point(0,0), Point(5, 0), Point(5, 5), Point(0, 5)])
    25.0
    >>> simple_polygon_area([Point(-4,3), Point(5,1), Point(2, 5)])
    15.0
    >>> simple_polygon_area([Point(3,4), Point(5,11), Point(12,8), Point(9,5), Point(5,6)])
    30.0
    >>> simple_polygon_area([Point(-3,-2), Point(-1,4), Point(6,1), Point(3,10), Point(-4,9)])
    60.0
    """

    area = 0
    for index in range(len(points)):
        curr, next = points[index], points[(index + 1) % len(points)]
        area += curr.x * next.y - curr.y * next.x

    return abs(area) / 2


if __name__ == "__main__":
    import doctest
    doctest.testmod()
