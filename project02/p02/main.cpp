#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Skill
{
    string mSkill;
    int mSalary;

    Skill(string skill, int salary)
        : mSkill(skill), mSalary(salary)
    {
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int nSkills, nTexts;
    cin >> nSkills >> nTexts;
    vector<Skill> skills;

    for (int i = 0; i < nSkills; i++)
    {
        string skill;
        int salary;

        cin >> skill >> salary;

        skills.push_back(Skill(skill, salary));
    }

    sort(begin(skills), end(skills), [](Skill skill1, Skill skill2)
         { return skill1.mSkill < skill2.mSkill; });

    int result = 0;
    string skill;

    while (cin >> skill)
    {
        if (skill == ".")
        {
            cout << result << endl;
            result = 0;
        }

        auto it = lower_bound(begin(skills), end(skills), skill, [](Skill a, string b)
                              { return a.mSkill < b; });
                              
        if (it != skills.end() && (it->mSkill == skill))
        {
            result += (it->mSalary);
        }
    }
}