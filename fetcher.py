"""
author: Jie Chen (3rd Year CS)
school: Rochester Institute of Technology
status: AC
"""
import requests

class Fetcher:
    def __init__(self):
        self.PROBLEM_PRE = "https://leetcode.com/problems/"
        self.CONTEST_PRE = "https://leetcode.com/contest/"

    def decide(self, link):
        if link.startswith(self.PROBLEM_PRE):
            return "P", self.fetch(link)
        elif link.startswith(self.CONTEST_PRE):
            return "C", {}
        return "N/A", {}
    
    def _get(self, pre, link):
        s_index = link.index(pre) + len(pre)
        slug = ""
        for i in range(s_index, len(link)):
            if link[i] == '/':
                break
            slug += link[i]
        return slug

    def fetch(self, link):
        title_slug = self._get(self.PROBLEM_PRE, link)

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
            return None

        data = res.json()["data"]["question"]
        return data
