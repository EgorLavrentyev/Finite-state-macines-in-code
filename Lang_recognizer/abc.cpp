// �������� ������� � ��������� ��������, ���������� �� istream -- ��������� �� ������ �������.
class Dfa_example
{
    int state;

public:
    // ����������� �� ��������� ������������� ��������� ���������.
    Dfa_example()
        : state(0) {} // ������ �������������: ����� �� ��, ��� state = 0

      // ���������, ��������� �� ������� � ����������� ���������.
    bool accepts() const // const �������, ��� ����� ������ ������� �� ������ ��������� �������
    {
        return state == 4;
    }

    // ���������� ����, ���� ������� ������������ (����� ���������������).
    // ���������� ������, ���� ������� �� ������������ � ������� ��������� ������.
    bool operator()(char input)
    {
        switch (state)
        {
        case 0:
            if (input == 'a')
                state = 1;
            else
                state = 5;
            break;

        case 1:
            if (input == 'b')
                state = 2;
            else
                state = 5;
            break;

        case 2:
            if (input == 'c')
                state = 3;
            else if (input == 'b')
                state = 4;
            else
                state = 5;
            break;

        case 3:
            state = 0;
            break;

        case 4:
            if (input == 'b')
                state = 1;
            else
                state = 5;
            break;

        default:
            assert(false); // ���� ������ ���� ���������� �������
        }

        return (state != 5); // ��� ��������������
    }
};

#include <istream>
#include <iostream>
#include <cassert>

//#define ABC_1 //������������ ��� �������, ����� ���������� ��������� ����������

// ���������� ������, ���� ������� ����������� � ����������� ���������.
bool dfa_example(std::istream& is)
{
    int state = 0;

    for (char input; is.get(input) && input != '\n' && state != 5; ) switch (state)
    {
    case 0:
        if (input == 'a')
            state = 1;
        else
            state = 5;
        break;

    case 1:
        if (input == 'b')
            state = 2;
        else
            state = 5;
        break;

    case 2:
        if (input == 'c')
            state = 3;
        else if (input == 'b')
            state = 4;
        else
            state = 5;
        break;

    case 3:
        state = 0;
        break;

    case 4:
        if (input == 'b')
            state = 1;
        else
            state = 5;
        break;
    }

    // ��������� 4 -- �����������.
    return state == 4;
}

//---------------------------------------------------------------------------------------------------------------------------------------------



#ifdef ABC_1
int main()
{
    using namespace std;
    while (true)
    {
        auto accepts = dfa_example(cin);
        cout << "Accepted: ";
        if (accepts)
            cout << "True" << endl;
        else
            cout << "False" << endl;
        cout << "----------------------" << endl;
        cin.clear();
        cin.sync();
        cin.ignore(cin.rdbuf()->in_avail());
    }

    return 0;
}
#else
int main()
{
    using namespace std;
    while (true)
    {
        Dfa_example dfa; // ������� ��������� ������ ��������
        // ��� ��� ������� ������ �� �������� � ������� ����� ���,
        // ���� �� �������� ������������ � ���������� ���������
        for (char input; cin.get(input) && input != '\n' && dfa(input); ) {}
        cout << "Accepted: ";
        if (dfa.accepts())
            cout << "True" << endl;
        else
            cout << "False" << endl;
        cout << "----------------------" << endl;
        cin.clear();
        cin.sync();
        cin.ignore(cin.rdbuf()->in_avail());
    }

    return 0;
}
#endif