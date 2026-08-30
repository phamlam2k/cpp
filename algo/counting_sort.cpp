#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

struct Student
{
    string name;
    int mark;
};

void solve()
{
    vector<Student> students = {
        {"Alice", 3},
        {"Bob", 5},
        {"Lam", 10},
        {"Minh", 8},
        {"Linh", 10},
        {"Long", 5},
        {"Tran", 8},
        {"Cuong", 5},
    };

    int total_students = students.size();

    int highest_mark = 0;

    for (int i = 0; i < total_students; i++)
    {
        highest_mark = max(students[i].mark, highest_mark);
    }

    vector<int> appearence(highest_mark + 1, 0);

    for (int i = 0; i < total_students; i++)
    {
        int mark = students[i].mark;

        appearence[mark] += 1;
    }

    for (int i = 1; i <= highest_mark; i++)
    {

        appearence[i] += appearence[i - 1];
    }

    vector<Student> students_sorted(total_students);

    for (int i = total_students - 1; i >= 0; i--)
    {
        int mark = students[i].mark;

        int index = appearence[mark] - 1;

        // cout << index << endl;

        students_sorted[index] = students[i];

        appearence[mark]--;
    }

    for (int i = 0; i < total_students; i++)
    {
        cout << students_sorted[i].name << " - " << students_sorted[i].mark << endl;
    }
}

signed main()
{
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}