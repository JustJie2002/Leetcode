#!/usr/bin/env python
import argparse
import subprocess as sp
import os
import pyperclip as pp

parser = argparse.ArgumentParser(
    prog = "py make.py",
    description = "Creating a folder for LC Contest"
)

parser.add_argument("t", type = str, help = "The type of contest (W/BW)")
parser.add_argument("cid", type = int, help = "The id of the LC contest")

args = parser.parse_args()

path = os.path.join(f"{args.t}{args.cid}")

if os.path.exists(path):
    print("You've already done that contest or were working on it.")
    print(f"Here's the path: {path} and it's copied to your clipboard.")
else:
    sp.run(f"cp -r Temp {path}", shell = True)
    print(f"Folder {path} created and copied to your clipboard.")
pp.copy(path)