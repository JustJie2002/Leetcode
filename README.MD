## Table of Content
- [Introduction](#introduction)
- [Overview](#overview)
  - [Problem](#problem)
  - [Contest](#contest)
- [Script used to Organize](#script-used-to-organize)

# Introduction
Hi! My name is Jie Chen and I'm currently studying @ RIT. \
I'm a DSA enthusiast and an ongoing competitive programmer. \
Currently on RIT ICPC Team. Attended 2023 - 2024 ICPC NENA Regional and received 11th place (Bronze Medal) \
I have 3 Leetcode accounts:
- [JustJie](https://leetcode.com/JustJie/) (Main Account)
- [SleepyJie](https://leetcode.com/SleepyJie/) (Smurf 1)
- [TiredJie](https://leetcode.com/TiredJie/) (Smurf 2)

I personally have 3 accounts because I really like to do leetcode contests and at times I would be very tired/sleepy or just not feeling it, that's when I will hop on those 2 smurf accounts. Here are some stats: \
Problem Solved: <span style="color:green">572</span> | <span style="color:orange">731</span> | <span style="color:red">250</span> | 1553 (JustJie) \
Contest Rating: <span style="color:skyblue">2552</span> | <span style="color:skyblue">2735</span> | <span style="color:skyblue">2538</span>

# Overview
I will be splitting this repository into 2 parts:
- Problem
- Contest

## [Problem](Problem/)
For problem section, I will sort them based on their leetcode difficulty: Easy, Medium, and Hard. For each problem, I will write out the code as well as the explanation for the problem. Each explanation will be in the following format:
1. Code
2. Explanation
3. Time Complexity
4. Reasoning for Time Complexity

However, there might be times when the explanation is incomplete. That would only happen if I can't think of the best way to explain the current question.

## [Contest](Contest/)
For contest section, it's just going to be a storage area for my contest code and will not have explanation because it might or might not be well written.

# Script used to Organize
Notice that I have 4 python scripts in the source directory:
1. make.py
2. fetcher.py
3. organizer.py
4. set.py

They are used to create directories for me and add the information into their respective README.MD. In order to also use this, your directory must be in the following format

- Problem (Folder)
  - Easy (Folder)
  - Medium (Folder)
  - Hard (Folder)
  - Temp (Folder)
    - code.cpp (or whatever template you want to put here)
    - README.ME (Optional. Only if you also want to explain)
  - README.MD
    - It must be in the same format as mine.
- Contest (Folder)
  - Temp (Folder)
    - A.cpp
    - B.cpp
    - C.cpp
    - D.cpp (these names are up to you)
  - README.MD
    - It must be in the same format as mine.

For the README.MD in these 2 folders, you can reset those by deleting all entries under those tables, other than the key tables.

You can use the script by:
1. python3 make.py [problem_link]
2. python3 make.py [contest_link]

Examples:
```bash
python3 make.py https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-03-27

python3 make.py https://leetcode.com/problems/two-sum/

python3 make.py https://leetcode.com/problems/two-sum/solutions/

python3 make.py https://leetcode.com/contest/weekly-contest-391/
```

There will be 3 possibilities:
1. You've never done such contest/problem, so the script will create the folder for you and have the path copied to your clipboard. What I like to do is just `code [path]` so I can immediately start coding it in my IDE (VSCode).
2. You've already doen such contest/problem, the script will not create extra folder, it will just copy the path to your clipboard.
3. Tell you the link is not good.

After you've used make.py to create the row for the problem. There is another main script that I created to update the status of the README.MD in Problem directory based on problem id.

You can use the script by: \
python3 set.py [problem_id] [new_status] \
new_status can be: AC, WX, and WA. Based off the key, you can update the script to your preference.