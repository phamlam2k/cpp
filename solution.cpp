#include <bits/stdc++.h>
using namespace std;

/* ============================================================
   HELPERS - PARSER INPUT/OUTPUT KIEU LEETCODE
   (khong copy len leetcode)
   ============================================================ */

// Lay dong khong rong tiep theo tu input.txt
static string nextLine() {
    string line;
    while (getline(cin, line)) {
        for (char c : line)
            if (!isspace((unsigned char)c)) return line;
    }
    return "";
}

// -------- READ --------
int readInt() {
    string s = nextLine(), num;
    for (char c : s)
        if (c == '-' || isdigit((unsigned char)c)) num += c;
    return num.empty() ? 0 : stoi(num);
}

// [1,2,3]  hoac  1 2 3  hoac  1,2,3
vector<int> readVI() {
    string s = nextLine();
    for (char &c : s)
        if (c == '[' || c == ']' || c == ',') c = ' ';
    vector<int> v; stringstream ss(s); int x;
    while (ss >> x) v.push_back(x);
    return v;
}

// [[1,2],[3,4]]
vector<vector<int>> readVVI() {
    string s = nextLine();
    vector<vector<int>> res; vector<int> cur; string num; int depth = 0;
    for (char c : s) {
        if (c == '[') { if (++depth == 2) cur.clear(); }
        else if (c == ']') {
            if (!num.empty()) { cur.push_back(stoi(num)); num.clear(); }
            if (depth == 2) res.push_back(cur);
            depth--;
        } else if (c == '-' || isdigit((unsigned char)c)) num += c;
        else if (c == ',' && !num.empty()) { cur.push_back(stoi(num)); num.clear(); }
    }
    return res;
}

// "hello"  ->  hello   (bo dau nhay ngoai neu co)
string readStr() {
    string s = nextLine();
    if (s.size() >= 2 && s.front() == '"' && s.back() == '"')
        s = s.substr(1, s.size() - 2);
    return s;
}

// ["a","bc"]  ->  {"a","bc"}
vector<string> readVS() {
    string s = nextLine(); vector<string> res; string cur; bool in = false;
    for (char c : s) {
        if (c == '"') { if (in) res.push_back(cur), cur.clear(); in = !in; }
        else if (in) cur += c;
    }
    return res;
}

// -------- PRINT --------
void printInt(long long x)   { cout << x << "\n"; }
void printBool(bool b)       { cout << (b ? "true" : "false") << "\n"; }
void printStr(const string& s){ cout << s << "\n"; }
void printVI(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) cout << (i ? "," : "") << v[i];
    cout << "]\n";
}
void printVVI(const vector<vector<int>>& g) {
    cout << "[";
    for (size_t i = 0; i < g.size(); i++) {
        cout << (i ? "," : "") << "[";
        for (size_t j = 0; j < g[i].size(); j++) cout << (j ? "," : "") << g[i][j];
        cout << "]";
    }
    cout << "]\n";
}

/* ============================================================
   >>> COPY TU DAY LEN LEETCODE...
   ============================================================ */

class Solution {
public:
    int solve(vector<int>& nums, int target) {
        // viet loi giai o day (doi ten ham + tham so cho dung de bai)

        return 0;
    }
};

/* ============================================================
   ...DEN DAY. Phia duoi chi de test tren may, khong copy.
   ============================================================ */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* --- WIRING: doc input.txt theo dung thu tu tham so cua de ---
       Vi du de "two sum": dong 1 = mang, dong 2 = target
       input.txt:
           [2,7,11,15]
           9
    */
    vector<int> nums = readVI();
    int target = readInt();

    Solution sol;
    int ans = sol.solve(nums, target);

    printInt(ans);   // doi printVI / printVVI / printBool / printStr cho dung kieu tra ve
}
