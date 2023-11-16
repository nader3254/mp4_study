import struct

def read_ftyp_atom(mp4_file):
    # Read the size of the ftyp atom
    size = struct.unpack("<I", mp4_file.read(4))[0]
    print("size is"+str(size))
    # Check if the size is valid
    if size < 16:
        raise ValueError("Invalid ftyp atom size")

    # Read the FourCC identifier of the atom
    fourcc = mp4_file.read(4)
    print("fourcc is "+str(fourcc))

    # Verify that the FourCC is indeed "ftyp"
    if fourcc != b"ftyp":
        raise ValueError("Invalid ftyp atom FourCC")
    
    # Read the major brand
    major_brand = mp4_file.read(4).decode("ascii")
    print("major_brand is "+str(major_brand))

    # Read the minor brand
    minor_brand = mp4_file.read(4).decode("ascii")
    print("minor_brand is "+str(minor_brand))

    # Read the list of compatible brands (if any)
    compatible_brands = []
    while size > 0:
        brand = mp4_file.read(4).decode("utf-8")
        compatible_brands.append(brand)
        size -= 4
    # while size > 0:
    #     brand = mp4_file.read(4).decode("ascii")
    #     compatible_brands.append(brand)
    #     size -= 4
    print("compatible_brands is"+str(compatible_brands))
    

    # return {
    #     "major_brand": major_brand,
    #     "minor_brand": minor_brand,
    #     "compatible_brands": compatible_brands
    # }

with open("test.mp4", "rb") as mp4_file:
    ftyp_atom_info = read_ftyp_atom(mp4_file)
    print("Major brand:", ftyp_atom_info["major_brand"])
    print("Minor brand:", ftyp_atom_info["minor_brand"])
    print("Compatible brands:", ftyp_atom_info["compatible_brands"])
