# M = 0
# L = 1
# S = -1, XS = -2
def toVal(size):
    val = 0
    mult = 1 if "M" in size or "L" in size else -1
    for char in size:
        if(char == "X"):
            val = val + (1 * mult)
        if(char == "S"):
            val -= 1
        if(char == "L"):
            val += 1
    return val


def main(sizesInShop, requests):
    allFullfilled = True
    valSizes = [toVal(size) for size in sizesInShop]
    valSizes.sort()
    print(valSizes)
    for request in requests:
        availables = [x for x in valSizes if x >= toVal(request)]
        print(availables)
        if(len(availables) == 0):
            allFullfilled = False
            break
    if(allFullfilled):
        print("Yes")
    else:
        print("No")
