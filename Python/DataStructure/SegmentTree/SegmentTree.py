# The methods in this segment tree are all implemented with an implicit stack
# instead of recursion.
class SegmentTree:
    """
    Segment Tree data structure.
    [wikipedia](https://en.wikipedia.org/wiki/Segment_tree)

    Segment trees are useful for storing information about ranges (also called
    segments) in a list of values.

    The `leaves` argument is a list of values that will be queried.

    The `accumulator` argument is a method that should compute some property of
    a segment. In order for the segment tree to work as intended, `accumulator`
    should take two inputs, and be commutative, and transitive. That is, for
    fixed leaves `a`, `b` and `c`:

    - Commutativity: `accumulator(a, b) == accumulator(b, a)`
    - Transitivity: `accumulator(a, accumulator(b, c)) ==
      accumulator(accumulator(a, b), c)`

    Some common examples of an `accumulator` method are `sum`, `min`, and
    `max`.
    """

    def __init__(self, leaves, accumulator):
        self.__n = len(leaves)
        self.acc = accumulator

        # Now we build the tree.
        self.tree = [None] * (self.__n * 4)

        NEITHER_DONE = 0
        LEFT_DONE = 1
        BOTH_DONE = 2

        stack = [(0, 0, self.__n, NEITHER_DONE)]

        while stack:
            print(stack)
            treeIdx, l, r, state = stack.pop()
            mid = r - ((r - l) >> 1)
            if l + 1 == r:
                # leaf node
                self.tree[treeIdx] = leaves[l]
            elif state == NEITHER_DONE:
                # We want to calculate the left subtree.
                # Next time we see this node, the left subtree will be done.
                stack.append((treeIdx, l, r, LEFT_DONE))
                # Push the left node to the stack.
                stack.append((treeIdx * 2 + 1, l, mid, NEITHER_DONE))
            elif state == LEFT_DONE:
                # We want to calculate the right subtree.
                # Next time we see this node, both subtrees will be done.
                stack.append((treeIdx, l, r, BOTH_DONE))
                # Push the right node to the stack.
                stack.append((treeIdx * 2 + 2, mid, r, NEITHER_DONE))
            else:
                self.tree[treeIdx] = self.acc(
                    self.tree[treeIdx * 2 + 1],
                    self.tree[treeIdx * 2 + 2]
                )

    def query(self, start, end):
        """
        Find the accumulated value over the range `leaves[start:end]` (includes
        `leaves[i]` for `start <= i < end`).
        """
        # we want to accumulate all nodes whose range (nodeStart, nodeEnd)
        # staisfies start ≤ nodeStart ≤ nodeEnd ≤ end
        result = None

        stack = [(0, 0, self.__n)]

        while stack:
            treeIdx, l, r = stack.pop()
            mid = r - ((r - l) >> 1)

            if start <= l and r <= end:
                # The entire node is contained in the query.
                if result is None:
                    result = self.tree[treeIdx]
                else:
                    result = self.acc(result, self.tree[treeIdx])
            else:
                if start < mid:
                    # At least some of the left subtree is contained in the
                    # query.
                    stack.append((treeIdx * 2 + 1, l, mid))
                if end > mid:
                    # At least some of the right subtree is contained in the
                    # query.
                    stack.append((treeIdx * 2 + 2, mid, r))

        return result

    def update(self, i, value):
        """
        Update the value in the `i`th leaf.
        """
        CHILD_NOT_DONE = 0
        CHILD_DONE = 1
        stack = [(0, 0, self.__n, CHILD_NOT_DONE)]

        while stack:
            treeIdx, l, r, state = stack.pop()
            mid = r - ((r - l) >> 1)

            if l + 1 == r:
                self.tree[treeIdx] = value
            elif state == CHILD_NOT_DONE:
                # we want to process the child that contains the node to be
                # updated.
                # Next time we see this node its child will be done.
                stack.append((treeIdx, l, r, CHILD_DONE))
                # Which subtree is the target node in?
                if i <= mid:
                    # It is in the left subtree.
                    stack.append((treeIdx * 2 + 1, l, mid, CHILD_NOT_DONE))
                else:
                    stack.append((treeIdx * 2 + 2, mid, r, CHILD_NOT_DONE))
            else:
                # Both children are now correct; one of them has been updated.
                self.tree[treeIdx] = self.acc(
                    self.tree[treeIdx * 2 + 1],
                    self.tree[treeIdx * 2 + 2]
                )
