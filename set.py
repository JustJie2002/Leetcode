#!/usr/bin/env python
"""
author: Jie Chen (3rd Year CS)
school: Rochester Institute of Technology
status: Todo
"""
import argparse
from organizer import Organizer

class Setter:
    def __init__(self):
        self.organizer = Organizer()

    def _set(self, path, status):
        content, inside = self._check(path, name)

        if not inside:
            return False

        K, E, M, H = self.organizer._parse_prob(content)
        to_add = self.organizer._convert_prob(prob)
        if "Easy" in to_add.title:
            E.append(to_add)
        elif "Medium" in to_add.title:
            M.append(to_add)
        else:
            H.append(to_add)
        E = self._norm(E)
        M = self._norm(M)
        H = self._norm(H)
        self._combine(path, K, E, M, H)
        return True

def main():
    parser = argparse.ArgumentParser(
        prog = "py set.py path new_status",
        description = "Set the status of some specific problem based on the problem path"
    )

    parser.add_argument("path", type = str, help = "The problem path to the problem")
    parser.add_argument("new_status", type = str, help = "The set status to the problem path")

    args = parser.parse_args()

    setter = Setter()
    setter._set(args.path, args.new_status)

if __name__ == "__main__":
    main()