#!/usr/bin/env python3
import sys

def convert_xpm42(infile, outfile):
    with open(infile, 'r') as f:
        lines = f.readlines()
    if not lines:
        print("Empty file?")
        return

    # The first line is the magic header "!XPM42"
    header_magic = lines[0].rstrip("\n")
    # The second line contains: width height num_colors cpp letter
    dims = lines[1].strip().split()
    if len(dims) < 5:
        print("Header dimensions malformed")
        return
    width, height, num_colors, cpp, color_letter = dims
    # We want to change cpp to 1.
    new_cpp = "1"
    new_header_line = f"{width} {height} {num_colors} {new_cpp} {color_letter}\n"
    
    # Process color table lines: each original key is of length cpp (2 chars).
    new_color_lines = []
    for i in range(2, 2 + int(num_colors)):
        line = lines[i]
        # Take only the first character as the new key.
        new_key = line[0]
        # The rest of the line remains the same (starting from index cpp)
        rest = line[int(cpp):]
        new_color_lines.append(new_key + rest)
    
    # Process the pixel data lines: for each line, take every cpp characters (here 2) and keep only the first.
    new_pixel_lines = []
    for line in lines[2 + int(num_colors):]:
        line = line.rstrip("\n")
        new_line = ''.join(line[i] for i in range(0, len(line), int(cpp)))
        new_pixel_lines.append(new_line)
    
    with open(outfile, 'w') as f:
        f.write(header_magic + "\n")
        f.write(new_header_line)
        for cline in new_color_lines:
            f.write(cline)
        f.write("\n")
        for pline in new_pixel_lines:
            f.write(pline + "\n")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: convert_xpm42.py input.xpm42 output.xpm42")
        sys.exit(1)
    convert_xpm42(sys.argv[1], sys.argv[2])
