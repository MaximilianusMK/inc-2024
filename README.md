# INC 2024 - Problem Repository

## Repository Structure

Each problem (from PA to PD for trial and A to M for contest) has their own folder. The folder name is the `slug` of the problem, which is the codename we used when we internally prepare the problems. The following table describes the slug for each problem

| Problem Code | Problem Slug | Problem Title            |
| ------------ | ------------ | ------------------------ |
| PA           | gold         | Golden Tickets           |
| PB           | diet         | Diet Plan                |
| PC           | permute      | Permutation Construction |
| PD           | narrow       | Narrow Passageway        |
| A            | problem      | Problem C                |
| B            | card         | The Journey of the King  |
| C            | choco        | Double Chunks            |
| D            | treasure     | Treasure Lair            |
| E            | three        | Three Three Three        |
| F            | work         | Intensive Training       |
| G            | creator      | Graph Director           |
| H            | combo        | Alchembit Exam           |
| I            | equal        | Count DFS Tree           |
| J            | sort         | Feng Shui                |
| K            | apple        | Red Panda                |
| L            | primal       | Primal Collection        |
| M            | median       | ICPC Provincial          |

In the problem folder, there should be exactly the following file/folder:

- `description.pdf`. The problem statement distributed to the contestants during the contest.
- `data/`. A folder consisting of all testcases. The sample inputs given in the problem statement will be in the form of `sample/[inc/incp]-<slug>_sample_<testcase number>.[in/ans]`, while the hidden testcases will be in the form of `secret/[inc/incp]-<slug>_1_<testcase number>.[in/ans]`.
- `solution.cpp`. The official solution used to generate the outputs of the testcases
- `scorer.cpp`. A validator used to validate contestants' output. The code accepts three arguments.
  - The first parameter will be used as the filename of the input file
  - The second parameter will be used as the filename of the judge's output file
  - The third parameter will be used as the filename of the contestant's output file
  - This code will print `WA` to stdout if the contestant's output is intended to be judged `WRONG ANSWER`, while it will print `AC` to stdout if the contestants's output is intended to be judged `CORRECT`.
- `verifier.py`. A verifier used to validate the input of the testcases. The code will crash if the input violates the problem constraint, while it will exit gracefully and will not output anything if the input satisfies the problem constraint.

## Limitations

The following table describes the time and memory limit for each problem.

| Problem Code | Problem Slug | Time Limit | Memory Limit |
| ------------ | ------------ | ---------- | ------------ |
| PA           | gold         | 1 sec      | 512 MB       |
| PB           | diet         | 1 sec      | 512 MB       |
| PC           | permute      | 1 sec      | 512 MB       |
| PD           | narrow       | 1 sec      | 512 MB       |
| A            | problem      | 1 sec      | 512 MB       |
| B            | card         | 1 sec      | 512 MB       |
| C            | choco        | 1 sec      | 512 MB       |
| D            | treasure     | 1 sec      | 512 MB       |
| E            | three        | 1 sec      | 512 MB       |
| F            | work         | 1 sec      | 512 MB       |
| G            | creator      | 1 sec      | 512 MB       |
| H            | combo        | 1 sec      | 512 MB       |
| I            | equal        | 1 sec      | 512 MB       |
| J            | sort         | 1 sec      | 512 MB       |
| K            | apple        | 2 sec      | 512 MB       |
| L            | primal       | 1 sec      | 512 MB       |
| M            | median       | 1 sec      | 512 MB       |

## Solutions

Note that while there is only one official published solution, we have a lot of other solutions prepared for our internal testing. These other solutions include, but not limited to:

- Solutions in several other languages
- Solutions that is intended to be incorrect (e.g. WA, TLE, etc.)
- Other correct solutions (especially on problems with more than one correct outputs for each input)

## Errata

None.

## Additional Notes

The problemset was officially deployed by the judges on [TLX](https://tlx.toki.id/problems/inc-2024).