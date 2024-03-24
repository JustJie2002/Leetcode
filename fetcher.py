import requests

class Fetcher:
    def __init__(self):
        self.PROBLEM_PRE = "https://leetcode.com/problems/"
        self.PROBLEM_SUF = "/description/"
        self.CONTEST_PRE = "https://leetcode.com/contest/"
        self.CONTEST_SUF = "/"

    def decide(self, link):
        if link.startswith(self.PROBLEM_PRE) and link.endswith(self.PROBLEM_SUF):
            return "P", self.fetch(link)
        elif link.startswith(self.CONTEST_PRE) and link.endswith(self.CONTEST_SUF):
            return "C", {}
        return "N/A", {}

    def fetch(self, link):
        s_index = link.index(self.PROBLEM_PRE) + len(self.PROBLEM_PRE)
        e_index = link.rindex(self.PROBLEM_SUF)
        title_slug = link[s_index: e_index]

        BASE = "https://leetcode.com/graphql"

        body = """
        {
            question (
                titleSlug: "%s"
            ) {
                questionId
                questionFrontendId
                title
                titleSlug
                isPaidOnly
                difficulty
                likes
                dislikes
            }
        }
        """ % title_slug
        
        res = requests.post(url = BASE, json = {
            "query" : body
        })

        if res.status_code != 200:
            return -1

        data = res.json()["data"]["question"]
        return data