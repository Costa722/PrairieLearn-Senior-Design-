import random, math

def isFilled(map, adr, variable):
    for i in range(variable['width']):
        if adr+i in map:
            return True
    return False

# Generates addresses between 0x2000_0000 and 0x2000_0fff, and keeps track of the mappings
#
# variable is an object with 3 attributes: name, width, and type.
# Type is the type of pointer made in C. i.e. unsigned int, int[5], char, etc.
# Width is the number of 4-byte memory blocks the variable takes up. int = 1, long long = 2, int[5] = 5, etc.
# Name is the name of the variable used in the C code.
def generateAddress(data, variable):
    memoryMap = data['params']['memoryMap']
    base = random.randint(0, 0x3ff)
    while isFilled(memoryMap, base, variable):
        base = (base + 1) % 0x400
    for i in range(variable['width']):
        if i == 0: memoryMap[base] = variable
        else: memoryMap[base+i] = None
    # returns 4-byte-aligned address
    return 0x20000000 | (base<<2)


def generate(data):
    # initializes the addressMap
    data['params']['memoryMap'] = {}

    data['params']['length'] = random.randint(5, 9)

    data['params']['x_adr'] = "0x%0.8X" % generateAddress(data, {'name':'X','width':10,'type':'unsigned int'})
    data['params']['y_adr'] = "0x%0.8X" % generateAddress(data, {'name':'Y','width':10,'type':'unsigned int'})

