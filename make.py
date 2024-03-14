#!/usr/bin/env python
import argparse
import subprocess as sp
import os
import pyperclip as pp

parser = argparse.ArgumentParser(
    prog = "py make.py pre id",
    description = "Creating a folder to store either the problem or contest"
)

parser.add_argument("pre", type = str, help = "The prefix of the intention (E/M/H for problems) (B/BW for contest)")
parser.add_argument("id", type = int, help = "The id of the intention")

args = parser.parse_args()

mapper = {
    "E": "Problem/Easy/P",
    "M": "Problem/Medium/P",
    "H": "Problem/Hard/P",
    "W": "Contest/W",
    "BW": "Contest/BW"
}

path = os.path.join(f"{mapper[args.pre]}{args.id}")

if os.path.exists(path):
    print("You've already done that problem/contest or were working on it.")
    print(f"Just copied {path} to your clipboard.")
else:
    pref = path[:path.index("/")]
    sp.run(f"cp -r {pref}/Temp {path}", shell = True)
    print(f"Folder {path} created and copied to your clipboard.")
pp.copy(path)
