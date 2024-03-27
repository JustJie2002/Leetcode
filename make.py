#!/usr/bin/env python
"""
author: Jie Chen (3rd Year CS)
school: Rochester Institute of Technology
status: AC
"""
import argparse
import subprocess as sp
import os
import pyperclip as pp
from fetcher import Fetcher
from organizer import Organizer

class Maker:
    def __init__(self):
        self.fetcher = Fetcher()
        self.organizer = Organizer()
        self.PROBLEM_DIR = "Problem"
        self.CONTEST_DIR = "Contest"
        self.CONTEST_PRE = self.fetcher.CONTEST_PRE

    def contest_parse(self, link):
        contest_slug = self.fetcher._get(self.CONTEST_PRE, link)
        t, _, cid = contest_slug.split("-")
        parts = [s.capitalize() for s in [t, _, cid]]
        name = " ".join(parts)
        match t:
            case "weekly":
                t = "W"
            case "biweekly":
                t = "BW"
        path = os.path.join(self.CONTEST_DIR, f"{t}{cid}")
        return name, path

    def make(self, link):
        t, data = self.fetcher.decide(link)

        match t:
            case "P":
                if data is None:
                    print("Sorry we don't support this link or it's not valid.")
                    return
                pid = data["questionFrontendId"]
                diff = data["difficulty"]
                name = data["title"]
                path = os.path.join(self.PROBLEM_DIR, diff, f"P{pid}")
                if os.path.exists(path):
                    print(f"You were already working on \"{name}\".")
                    print(f"{path} is copied to your clipboard.")
                else:
                    sp.run(
                        args = f"cp -r {self.PROBLEM_DIR}/Temp {path}",
                        shell = True
                    )
                    print(f"\"{name}\" has been created and {path} is copied to your clipboard.")
                pp.copy(path)
                path_no_pre = path[len(self.PROBLEM_DIR) + 1: ]

                readme_path = f"{self.PROBLEM_DIR}/README.MD"
                prob_format = f"| {pid} | [{name}]({path_no_pre}) | WA |"
                self.organizer.add(readme_path, name, prob_format)
            case "C":
                name, path = self.contest_parse(link)
                if os.path.exists(path):
                    print(f"You were already working on \"{name}\".")
                    print(f"{path} is copied to your clipboard.")
                else:
                    sp.run(
                        args = f"cp -r {self.CONTEST_DIR}/Temp {path}",
                        shell = True
                    )
                    print(f"\"{name}\" has been created and {path} is copied to your clipboard.")
                pp.copy(path)
                path_no_pre = path[len(self.CONTEST_DIR) + 1: ]

                readme_path = f"{self.CONTEST_DIR}/README.MD"
                prob_format = f"| {path_no_pre} | [{name}]({path_no_pre}/) | N/A | N/A |"
                self.organizer.add(readme_path, name, prob_format)
            case "N/A":
                print("Sorry we don't support this link or it's not valid.")

def main():
    parser = argparse.ArgumentParser(
        prog = "py make.py link",
        description = "Creating a folder to store either the problem or contest"
    )

    parser.add_argument("link", type = str, help = "The link to the problem/contest")

    args = parser.parse_args()
    link = args.link

    maker = Maker()
    maker.make(link)

if __name__ == "__main__":
    main()
