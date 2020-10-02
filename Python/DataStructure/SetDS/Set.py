class Set:
    """ Set Implement in Python 3 """

    def __init__(self, values=None):
        """this is the constructor it gets called when you create a new Set."""
        self.dict = {}  # Each instance of set has it's own dict property

        if values is not None:
            for value in values:
                self.add(value)

    def __repr__(self):
        """ this is the string representations of a set objects"""
        return f"Set: {self.dict.keys()}"

    # we'll represnt membership by being a key in self.dict with value True
    def add(self, value):
        self.dict[value] = True

    def contains(self, value):
        return value in self.dict

    def remove(self, value):
        del self.dict[value]
