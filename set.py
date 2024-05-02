#!/usr/bin/env python
"""
author: Jie Chen (3rd Year CS)
school: Rochester Institute of Technology
status: AC
"""
import argparse
from organizer import Organizer, ProblemInfo

class Setter:
    def __init__(self):
        self.organizer = Organizer()
        self.PATH = "Problem/README.MD"

    def _get(self):
        with open(self.PATH, "r") as fp:
            content = fp.read()
        return content
    
    def _modify(self, a, pid, status):
        changed = False
        for i, info in enumerate(a):
            if i < 3:
                continue
            assert isinstance(info, ProblemInfo)
            if info.problem_id == pid:
                a[i].status = status
                changed = True
                break
        return a, changed

    def change(self, pid, status):
        content = self._get()

        K, E, M, H = self.organizer._parse_prob(content)
        changed = False
        E, ok = self._modify(E, pid, status)
        changed = changed or ok
        M, ok = self._modify(M, pid, status)
        changed = changed or ok
        H, ok = self._modify(H, pid, status)
        changed = changed or ok
        self.organizer._combine(self.PATH, K, E, M, H)
        return changed

STATUS = ["AC", "WX", "WA"]

def main():
    parser = argparse.ArgumentParser(
        prog = "py set.py pid new_status",
        description = "Set the status of some specific problem based on the problem path"
    )

    parser.add_argument("pid", type = int, help = "The problem id of the problem")
    parser.add_argument("new_status", type = str, help = "The set status to the problem path")

    args = parser.parse_args()

    if args.new_status not in STATUS:
        print("Status does not exist. Please try again.")
        return

    setter = Setter()
    res = setter.change(args.pid, args.new_status)
    if res:
        print(f"Status for P{args.pid} has successfully been changed to {args.new_status}.")
    else:
        print("No such problem is found.")

if __name__ == "__main__":
    main()