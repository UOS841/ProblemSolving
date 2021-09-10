#include <string>
#include <vector>

using namespace std;

string step1(string new_id)
{
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] >= 65 && new_id[i] <= 90)
        {
            new_id[i] += 32;
        }
    }
    
    return new_id;
}

string step2(string new_id)
{
    string return_id = "";

    for (int i = 0; i < new_id.size(); i++)
    {
        // 아이디에 들어갈 수 있는 문자인 경우
        if ((new_id[i] >= 48 && new_id[i] <= 57) ||
            (new_id[i] >= 97 && new_id[i] <= 122) ||
            new_id[i] == '-' ||
            new_id[i] == '_' ||
            new_id[i] == '.')
        {
            return_id += new_id[i];
        }
    }
    return return_id;
}

string step3(string new_id)
{
    string return_id = "";
    bool start = false;
    
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] == '.')
        {
            if (!start)
            {
                return_id += new_id[i];
                start = true;
            }
        }
        else
        {
            start = false;
            return_id += new_id[i];
        }   
    }
    return return_id;
}

string step4(string new_id)
{
    if (new_id[0] == '.')
    {
        new_id = new_id.substr(1);
    }
    if (new_id[new_id.size()] == '.')
    {
        new_id = new_id.substr(0, new_id.size() - 1);
    }
    
    return new_id;
}

string step5(string new_id)
{
    if (new_id == "")
    {
        new_id = "a";
    }
    return new_id;
}

string step6(string new_id)
{
    if (new_id.size() >= 16)
    {
        new_id = new_id.substr(0, 15);
    }
    if (new_id[new_id.size() - 1] == '.')
    {
        new_id = new_id.substr(0, new_id.size() - 1);
    }
    return new_id;
}

string step7(string new_id)
{
    while (new_id.size() <= 2)
    {
        new_id += new_id[new_id.size() - 1];
    }

    return new_id;
}

string solution(string new_id)
{
    return step7(step6(step5(step4(step3(step2(step1(new_id)))))));
}