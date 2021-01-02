"""
Title: Klees Algorithm
Description:
    Given starting and ending positions of segments on a line, the
    task is to take the union of all given segments and find length
    covered by these segments.
Examples:
    Input : segments[] = {{2, 5}, {4, 8}, {9, 12}}
    Output : 9
    segment 1 = {2, 5}
    segment 2 = {4, 8}
    segment 3 = {9, 12}
    If we take the union of all the line segments,
    we cover distances [2, 8] and [9, 12]. Sum of
    these two distances is 9 (6 + 3).
Solution:
    1) Put all the coordinates of all the segments in an auxiliary
    array points[].
    2) Sort it on the value of the coordinates.
    3) An additional condition for sorting – if there are equal
    coordinates, insert the one which is the left coordinate of any
    segment instead of a right one.
    4) Now go through the entire array, with the counter “count” of
    overlapping segments.
    5) If count is greater than zero, then the result is added to the
    difference between the points[i] and points[i - 1].
    6) If the current element belongs to the left end, we increase
    “count”, otherwise reduce it.
"""


# Utility function
def segmentUnionLength(segments: list) -> int:
    # size of given segments list
    n = len(segments)
    # Initialize empty points container
    points = [None] * (n * 2)
    # create a vector to store starting and ending points
    for i in range(n):
        points[i * 2] = (segments[i][0], False)
        points[i * 2 + 1] = (segments[i][1], True)
    # print (points)
    # print (len(points))
    # sorting all points by point value
    points = sorted(points, key=lambda x: x[0])
    # Initialize result as 0
    result = 0
    # To keep track of counts of current open segments
    # (Starting point is processed, but ending point
    # is not)
    Counter = 0
    # print (points)
    # Traverse through all points
    for i in range(0, n * 2):
        # If there are open points, then we add the
        # difference between previous and current point.
        # This is interesting as we don't check whether
        # current point is opening or closing
        if (i > 0) & (points[i][0] > points[i - 1][0]) & (Counter > 0):
            result += (points[i][0] - points[i - 1][0])
        # If this is an ending point, reduce, count of
        # open points.
        if points[i][1]:
            Counter -= 1
        else:
            Counter += 1
    return result


# Driver code
if __name__ == '__main__':

    segments = []
    segments.append((1, 6))
    segments.append((4, 5))
    segments.append((3, 8))
    segments.append((7, 9))
    print(segmentUnionLength(segments))
    segments = []
    segments.append((1, 3))
    segments.append((2, 5))
    segments.append((5, 6))
    print(segmentUnionLength(segments))
    segments = []
    segments.append((2, 5))
    segments.append((4, 8))
    segments.append((9, 12))
    print(segmentUnionLength(segments))
