#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 20;

    std::string subject, grade;
    double credit, score, totalCredit;

    while(T--)
    {
        std::cin >> subject >> credit >> grade;

        if(grade == "P") continue;

        totalCredit += credit;

        if(grade == "A+") score += credit * 4.5;
        else if (grade == "A0") score += credit * 4.0;
        else if (grade == "B+") score += credit * 3.5;
        else if (grade == "B0") score += credit * 3.0;
        else if (grade == "C+") score += credit * 2.5;
        else if (grade == "C0") score += credit * 2.0;
        else if (grade == "D+") score += credit * 1.5;
        else if (grade == "D0") score += credit * 1.0;
        else if (grade == "F") score += credit * 0.0;
    }

    double avg = score / totalCredit;
    std::cout << avg << '\n';
    return 0;
}

/*
틀린이유: 학점계산 공식을 잘못 알고 있었다.
분모는 이수한 과목들의 학점 총합이어야 한다.
*/