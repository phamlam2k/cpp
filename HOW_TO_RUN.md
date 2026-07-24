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

## Template Solution (LeetCode) — chạy input.txt trong VS Code

- `solution.cpp` — copy cho mọi bài LeetCode dạng `class Solution`

**Chạy bằng nút/menu VS Code (đã fix config):**
1. Copy template: `cp solution.cpp leetcode/1_two_sum.cpp`
2. Sửa hàm trong `class Solution` cho đúng đề.
3. Ở `main()`, chỉnh phần `WIRING` đọc đúng số/kiểu tham số, và đổi hàm `print...` cho đúng kiểu trả về.
4. Tạo `input.txt` **cùng thư mục** với file `.cpp`, dán sample kiểu LeetCode (mỗi tham số 1 dòng):
   ```
   [2,7,11,15]
   9
   ```
5. Mở file `.cpp`, bấm **Terminal → Run Task → `Build & Run (input.txt)`**
   (hoặc **Ctrl+Shift+P → Tasks: Run Test Task** vì task này là default test task).

Parser có sẵn: `readInt()`, `readVI()` (`[1,2,3]`), `readVVI()` (`[[1,2],[3,4]]`),
`readStr()` (`"abc"`), `readVS()` (`["a","b"]`).
In: `printInt()`, `printBool()`, `printStr()`, `printVI()`, `printVVI()`.

Khi submit LeetCode: chỉ copy phần giữa `>>> COPY TU DAY` → `...DEN DAY`.

> **Lưu ý về config:** shell mặc định trên máy là PowerShell 5.1 — **không** hỗ trợ `&&`
> lẫn `< input.txt`. Vì vậy task `Build & Run` được cấu hình chạy bằng **Git Bash**
> (`C:/Program Files/Git/bin/bash.exe`). Đó là lý do task "Build and Run" cũ (dùng `&&`
> trong PowerShell) không chạy được.

---

## Template Linked List (LeetCode)

- `linked_list.cpp` — copy file này cho mọi bài linked list

```bash
cp linked_list.cpp leetcode/206_reverse_linked_list.cpp
bash run.sh leetcode/206_reverse_linked_list.cpp
```

`input.txt` dán thẳng format LeetCode, mỗi tham số 1 dòng:
```
[1,2,3,4,5]
2
```

Trong file:
- Viết code trong `class Solution` (đổi tên hàm `solve` cho đúng đề).
- Ở `main()`, bỏ comment dòng `readList()` / `readInt()` tương ứng số tham số của đề.
- Khi submit: chỉ copy phần giữa 2 dải `COPY TU DAY...` → `...DEN DAY`.
- Không dùng `#define int long long` ở đây vì LeetCode khai báo `ListNode.val` là `int`.

Helper có sẵn: `readList()`, `readInt()`, `readInts()`, `printList()`, `makeCycle(head, pos)` (test bài có chu trình).

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
