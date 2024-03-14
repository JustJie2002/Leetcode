from typing import *
import os
import subprocess as sp

def parse(to_be_parsed: str):
    secs = to_be_parsed.split("\n")
    header = secs[:3]
    secs = secs[3:]

    info = []
    for sec in secs:
        sec = sec.lstrip("| ")
        sec = sec.rstrip(" |")
        sec = sec.split(" | ")
        info.append(sec)
    return header, info

def organize(to_be_parsed: str):
    header, info = parse(to_be_parsed)
    info.sort(key = lambda x : int(x[0]))

    combined = header
    n = len(info)
    for i in range(n):
        s = "| " + " | ".join(info[i]) + " |"
        combined.append(s)
    
    return combined

mapper = {
    "E": "Easy",
    "M": "Medium",
    "H": "Hard"
}

with open("README.MD", "r") as fp:
    data = fp.read()
    K, E, M, H = [info.strip() for info in data.split("---")]

    running = True
    while running:
        stmt = input("owo: ")
        op, *argc = stmt.split()
        op = op.lower()
        argv = len(argc)

        match op:
            case "add":
                if argv != 2:
                    continue
                sp.run(f"./make.py {argc[0]} {argc[1]}", shell = True)

            case "quit":
                running = False
            case "q":
                running = False

            case "remove":
                if argc != 2:
                    continue


