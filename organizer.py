"""
author: Jie Chen (3rd Year CS)
school: Rochester Institute of Technology
status: AC
"""
from typing import *

DELIM = """

---

"""

class ContestInfo:
    def __init__(
            self,
            is_weekly: bool,
            contest_id: int,
            title: str,
            status: str,
            rank: str
        ):
        self.is_weekly = is_weekly
        self.contest_id = contest_id
        self.title = title
        self.status = status
        self.rank = rank
    
    def __lt__(self, rhs):
        assert isinstance(rhs, ContestInfo)
        return self.contest_id > rhs.contest_id
    
    def __eq__(self, rhs):
        assert isinstance(rhs, ContestInfo)
        return self.contest_id == rhs.contest_id
    
    def __str__(self):
        full = ("W" if self.is_weekly else "BW") + str(self.contest_id)
        return "| {} | {} | {} | {} |".format(
            full,
            self.title,
            self.status,
            self.rank
        )

class ProblemInfo:
    def __init__(
            self,
            problem_id: int,
            title: str,
            status: str
        ):
        self.problem_id = problem_id
        self.title = title
        self.status = status

    def __lt__(self, rhs):
        assert isinstance(rhs, ProblemInfo)
        return self.problem_id < rhs.problem_id
    
    def __eq__(self, rhs):
        assert isinstance(rhs, ProblemInfo)
        return self.problem_id == rhs.problem_id
    
    def __str__(self):
        return "| {} | {} | {} |".format(
            self.problem_id,
            self.title,
            self.status
        )
    
    def __repr__(self):
        return self.__str__()

class Organizer:
    def __init__(self):
        self.PROBLEM_DIR = "Problem"
        self.CONTEST_DIR = "Contest"

    def _check(self, path, prob_name):
        inside = True
        with open(path, "r") as fp:
            content = fp.read()
            if prob_name not in content:
                inside = False
        return content, inside

    def _parse(self, content):
        return [info.split("\n") for info in content.split(DELIM)]

    def _convert_prob(self, line):
        line = line.lstrip("| ").rstrip(" |")
        pid, title, status = line.split(" | ")
        pid = int(pid)
        return ProblemInfo(pid, title, status)

    def _parse_prob(self, content):
        K, E, M, H = self._parse(content)

        def get(A):
            new_A = A[:3]
            for i in range(3, len(A)):
                new_A.append(self._convert_prob(A[i]))
            return new_A

        return K, get(E), get(M), get(H)

    def _convert_contest(self, line):
        line = line.lstrip("| ").rstrip(" |")
        full, title, status, rank = line.split(" | ")
        if full.startswith("W"):
            is_weekly = True
            full = full[1:]
        else:
            is_weekly = False
            full = full[2:]
        cid = int(full)
        return ContestInfo(is_weekly, cid, title, status, rank)

    def _parse_contest(self, content):
        K, W, BiW = self._parse(content)

        def get(A):
            new_A = A[:3]
            for i in range(3, len(A)):
                new_A.append(self._convert_contest(A[i]))
            return new_A

        return K, get(W), get(BiW)

    def _norm(self, A):
        pref = A[:3]
        info = A[3:]
        info.sort()
        return pref + info

    def _combine(self, path, *A):
        B = []
        for i, a in enumerate(A):
            if i > 0:
                l = a[0].index("(")
                a[0] = a[0][:l] + f"({len(a) - 3})"
            b = "\n".join(map(str, a))
            B.append(b)
        C = DELIM.join(B)
        with open(path, "w") as fp:
            fp.write(C)

    def add(self, path, name, prob):
        content, inside = self._check(path, name)

        if inside:
            return

        if path.startswith(self.PROBLEM_DIR):
            K, E, M, H = self._parse_prob(content)
            to_add = self._convert_prob(prob)
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

        elif path.startswith(self.CONTEST_DIR):
            K, W, BiW = self._parse_contest(content)
            to_add = self._convert_contest(prob)
            if to_add.is_weekly:
                W.append(to_add)
            else:
                BiW.append(to_add)
            W = self._norm(W)
            BiW = self._norm(BiW)
            self._combine(path, K, W, BiW)