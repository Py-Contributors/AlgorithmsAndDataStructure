"""Code to search and remove or include element in a list"""


def remove_ord(key, list_i):
    """Remotion of an element of the list by a key that was gaved"""
    pos = 0
    searcher = len(list_i) - 1
    while pos <= searcher:
        if key == pos:
            if key == searcher:
                list_i[key] = list_i[key - 1]
                pos += 1
            else:
                list_i[key] = list_i[key + 1]
                pos += 1
        else:
            pos += 1
    return list_i


def include_ord(key, elem, list_i):
    """Inclusion of an element on the list by a key and element provided"""
    pos = 0
    searcher = len(list_i) - 1
    while pos <= searcher:
        if pos == key:
            list_i[pos] = elem
            pos += 1
        else:
            pos += 1
    return list_i

LIST_I = [1, 88, 45, 732, 22, 5646, 8732]


remove_ord(2, LIST_I)
include_ord(2, 99, LIST_I)
