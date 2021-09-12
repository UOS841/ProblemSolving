#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// 문자열 나누고 vector에 저장
vector<string> split(string str)
{
    vector<string> result;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, ' '))
    {
        if (temp == "and")
        {
            continue;
        }
        result.push_back(temp);
    }
    return result;
}

// info의 내용을 2차원 벡터로 변환
vector<vector<string>> make_matrix(vector<string> info)
{
    vector<vector<string>> info_matrix;
    for (int i = 0; i < info.size(); i++)
    {
        info_matrix.push_back(split(info[i]));
    }

    return info_matrix;
}

// 쿼리 내용을 vector로 변환
vector<string> decode_query(string query)
{
    return split(query);
}

// 지원자 목록에서 어떤 항목에 대해 필터링한 목록을 반환
vector<int> filter_each_item(vector<vector<string>> info, vector<int> cur_filtered_applicant, int item, string keyword)
{
    if (keyword == "-")
    {
        return cur_filtered_applicant;
    }

    vector<int> new_filtered_applicant;
    int item_num;
    bool score_flag = false;
    switch (item)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        score_flag = true;
        break;
    default:
        break;
    }

    // 일반적인 필터링인 경우
    if (!score_flag)
    {
        for (int i = 0; i < cur_filtered_applicant.size(); i++)
        {
            int cur_applicant = cur_filtered_applicant[i];
            if (info[cur_applicant][item] == keyword)
            {
                new_filtered_applicant.push_back(cur_applicant);
            }
        }
    }
    // 점수 비교인 경우
    else
    {
        int ref_score = stoi(keyword);
        for (int i = 0; i < cur_filtered_applicant.size(); i++)
        {
            int cur_applicant = cur_filtered_applicant[i];
            int cur_applicant_score = stoi(info[cur_applicant][item]);
            if (cur_applicant_score >= ref_score)
            {
                new_filtered_applicant.push_back(cur_applicant);
            }
        }
    }

    return new_filtered_applicant;
}

// 한 쿼리 내용에 대리한 지원자 필터링 내용 반환
vector<int> filter_applicant(vector<vector<string>> info, vector<string> decoded_query)
{
    // 지원자 목록 초기화
    vector<int> filtered_applicant;
    for (int i = 0; i < info.size(); i++)
    {
        filtered_applicant.push_back(i);
    }

    // 필터 기준값이 나올 때까지 무시
    int i = 0;
    while (decoded_query[i] == "-")
    {
        i++;
    }

    // 그 후 뒤이어 필터링
    for (int j = i; j <= 4; j++)
    {
        filtered_applicant = filter_each_item(info, filtered_applicant, j, decoded_query[j]);
    }

    return filtered_applicant;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    // info 데이터 정제
    vector<vector<string>> matrix = make_matrix(info);
    vector<int> answer;

    // 각 쿼리마다 필터링 수행
    for (int i = 0; i < query.size(); i++)
    {
        vector<string> decoded_query = decode_query(query[i]);
        vector<int> filtered_applicant = filter_applicant(matrix, decoded_query);
        // 필터링된 목록의 지원자 수 저장
        answer.push_back(filtered_applicant.size());
    }

    return answer;
}

/*
int main()
{
    vector<string> info, query;
    info.push_back("java backend junior pizza 150");
    info.push_back("python frontend senior chicken 210");
    info.push_back("python frontend senior chicken 150");
    info.push_back("cpp backend senior pizza 260");
    info.push_back("java backend junior chicken 80");
    info.push_back("python backend senior chicken 50");

    query.push_back("java and backend and junior and pizza 100");
    query.push_back("python and frontend and senior and chicken 200");
    query.push_back("cpp and - and senior and pizza 250");
    query.push_back("- and backend and senior and - 150");
    query.push_back("- and - and - and chicken 100");
    query.push_back("- and - and - and - 150");

    vector<int> answer = solution(info, query);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
*/