#!/usr/bin/env python
import argparse
import subprocess as sp
import os
import pyperclip as pp

parser = argparse.ArgumentParser(
    prog = "py make.py d pid",
    description = "Creating a folder to store leetcode solutions and editorials"
)

parser.add_argument("d", type = str, help = "The difficulty of the leetcode problem (E/M/H)")
parser.add_argument("pid", type = int, help = "The id of the leetcode problem")

args = parser.parse_args()

mapper = {
    "E": "Easy",
    "M": "Medium",
    "H": "Hard"
}

path = os.path.join(mapper[args.d], f"P{args.pid}")

if os.path.exists(path):
    print("You've already done that problem or were working on it.")
    print(f"Just copied {path} to your clipboard.")
else:
    sp.run(f"cp -r Temp {path}", shell = True)
    print(f"Folder {path} created and copied to your clipboard.")
    pp.copy(path)
