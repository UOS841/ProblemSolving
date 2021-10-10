def add_str(convert_str, adding_str, count):
    if count == 1:
        convert_str += adding_str
    else:
        convert_str += (str(count) + adding_str)

    return convert_str

def convert(s, period):
    str_size = len(s)
    idx = 0
    before_substr = ""
    convert_str = ""
    sub_count = 1
    
    while idx < str_size:
        tmp_substr = s[idx:idx+period]

        # 제일 처음 탐색인 경우
        if idx == 0:
            # 마지막 탐색이면 그대로 출력
            if idx + period >= str_size:
                convert_str = add_str(convert_str, tmp_substr, sub_count)
            else:
                before_substr = tmp_substr
            
            idx += period
            continue

        # 기존 버퍼 내용과 같은 경우
        if before_substr == tmp_substr:
            sub_count += 1
        # 기존 버퍼 내용과 다른 경우
        else:
            convert_str = add_str(convert_str, before_substr, sub_count)
            # 현재 탐색 데이터로 교체 
            before_substr = tmp_substr
            sub_count = 1

        # 마지막 탐색인 경우 마저 출력
        if idx + period >= str_size:
            convert_str = add_str(convert_str, before_substr, sub_count)

        idx += period

    return convert_str

def solution(s):
    min = 2000
    for i in range(1000):
        convert_str = convert(s, i + 1)
        if min > len(convert_str):
            min = len(convert_str)
    
    return min