# How to Run C++ like a Competitive Programmer (Codeforces style)

## Setup

- `code.cpp`  — your template, copy this for every new problem
- `input.txt` — paste the sample input from Codeforces here
- `run.sh`    — compile + run script

---

## Workflow (step by step)

### Step 1 — Copy the template
```bash
cp code.cpp mysolution.cpp
```

### Step 2 — Paste the sample input into input.txt
Open `input.txt` and paste exactly what Codeforces gives you in the sample input box.

Example for a problem with 2 test cases:
```
2
5 3
1 2 3 4 5
```

### Step 3 — Write your solution in mysolution.cpp
Fill in the `solve()` function. The template already handles:
- Multiple test cases (`while (t--)`)
- Fast I/O (no TLE from cin/cout)
- Common typedefs and macros

### Step 4 — Compile and run
```bash
bash run.sh mysolution.cpp
```

Or manually:
```bash
g++ -O2 -std=c++17 -Wall -o sol mysolution.cpp && ./sol < input.txt
```

### Step 5 — Compare with expected output
Check if your output matches the sample output on Codeforces.

---

## Template macros explained

| Macro / typedef | Meaning |
|-----------------|---------|
| `#define int long long` | All `int` become 64-bit — avoids overflow bugs |
| `CODEGOD` | Fast I/O — put in main(), speeds up cin/cout |
| `pb` | Short for `push_back` |
| `all(x)` | `x.begin(), x.end()` — use in sort, etc. |
| `sz(x)` | Size of container as `int` |
| `pii` | `pair<int,int>` |
| `vi` | `vector<int>` |
| `MOD` | `1e9 + 7` — standard modulus |
| `INF` | `1e18` — safe infinity for long long |

---

## Common Codeforces tips

- **Always read `t` (number of test cases)** — most CF problems use this format
- **Use `endl "\n"`** — `"\n"` is faster than `std::endl` (no flush)
- **If only 1 test case** — comment out `cin >> t;` and keep `int t = 1;`
- **Submit in C++17 (64bit)** on Codeforces for best compatibility

---

## Quick commands

```bash
# compile + run with input.txt
bash run.sh code.cpp

# compile only
g++ -O2 -std=c++17 -o sol code.cpp

# run with input typed manually
./sol

# run and save output to file
./sol < input.txt > output.txt
```
