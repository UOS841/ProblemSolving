#include <iostream>
#include <vector>
#include <string>

using namespace std;

char alphanumeric[45] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '$', '%', '*',
	'+', '-', '.', '/', ':'
};
char hexa[16] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F'
};

// 입력된 16진수 코드를 binary 형태 문자열로 변환
string hex_to_bin(string code)
{
	string bin_code = "";

	int index = 0;
	while (index < code.size())
	{
		// index를 통해 code의 문자를 순차탐색
		// cur_char엔 현재 탐색 중인 문자의 ASCII 값으로 초기화
		int cur_char = (int)code[index];

		// ASCII 정보를 일반 숫자 정보로 변환
		// 문자가 0~9일 때
		if (cur_char >= 48 && cur_char <= 57)
		{
			cur_char -= 48;
		}
		// 문자가 A~F일 때
		else
		{
			cur_char -= 55;
		}
		
		// 16진수로 변환된 cur_char를 자릿수마다 비트 연산을 통해 0, 1 문자를 붙임
		int pos = 8;
		while (pos > 0)
		{
			int tmp = cur_char & pos;

			if (tmp > 0)
			{
				bin_code += "1";
			}
			else
			{
				bin_code += "0";
			}
			pos >>= 1;
		}

		// 다음 문자 탐색을 위해 index++
		index++;
	}
	return bin_code;
}

// binary code를 10진법 숫자로 변환하는 함수
int bin_to_dec(string code)
{
	int num = 0, pos = 1;
	for (int i = code.size() - 1; i >= 0; i--)
	{
		if ((char)code[i] == '1')
		{
			num += pos;
		}
		pos <<= 1;
	}

	return num;
}

// binary code를 16진법 문자열로 변환하는 함수
string bin_to_hex_string(string code)
{
	string data = "";

	int bit_pos = code.size() - 1;
	int num_pos = 1;
	int num = 0;

	// 코드 뒤에서부터 순차적으로 탐색
	// bit 4개만큼 num을 구해 data 변수에 추가
	while (bit_pos >= 0)
	{
		if ((char)code[bit_pos] == '1')
		{
			num += num_pos;
		}

		if (num_pos == 8)
		{
			data = hexa[num] + data;

			num_pos = 1;
			num = 0;
		}
		else
		{
			num_pos <<= 1;
		}
		bit_pos--;
	}
	// 미처 붙이지 못 한 나머지 앞의 부분 추가
	if (num_pos != 1)
	{
		data = hexa[num] + data;
	}

	return data;
}

// 코드의 문자 갯수 확인 함수
// length : Numeric -> 1 / Alphanumeric -> 2 / 8bit char -> 3 / kanji -> 4
int count_char(string code, int mode)
{
	int length;

	if (mode == 1)
	{
		length = 10;
	}
	else if (mode == 2)
	{
		length = 9;
	}
	else
	{
		length = 8;
	}

	return bin_to_dec(code.substr(0, length));
}

/*
int num_code_length(string code)
{
	return 0;
}
*/

// 0001 : Numeric decode
string decode_numeric(string code)
{
	int index = 0;

	// parameter code의 앞 10자리로 숫자 갯수 파악
	int count = bin_to_dec(code.substr(index, 10));
	index += 10;
	
	// 정보를 data 변수에 저장
	string data = "";

	// 우선 3개의 숫자가 저장된 10bit code를 처리
	for (int i = 0; i < count / 3; i++)
	{
		int num = bin_to_dec(code.substr(index, 10));
		data += to_string(num);
		index += 10;
	}

	// 만약 숫자 갯수(count)가 3으로 안 나눠지고 1, 2bit가 남는 경우 따로 변환
	if (count % 3 == 1)
	{
		int num = bin_to_dec(code.substr(index, 4));
		data += to_string(num);
		index += 4;
	}
	else if (count % 3 == 2)
	{
		int num = bin_to_dec(code.substr(index, 7));
		data += to_string(num);
		index += 7;
	}

	return data;
}

// 0010 : Alphaumeric decode
string decode_alphanumeric(string code)
{
	int index = 0;

	// parameter code의 앞 9자리로 숫자 갯수 파악
	int count = bin_to_dec(code.substr(index, 9));
	index += 9;

	// 정보를 data 변수에 저장
	string data = "";

	// 우선 2개의 문자가 저장된 11bit code를 처리
	for (int i = 0; i < count / 2; i++)
	{
		int num = bin_to_dec(code.substr(index, 11));

		char letter1 = alphanumeric[num / 45];
		char letter2 = alphanumeric[num % 45];
		data = data + letter1 + letter2;

		index += 11;
	}

	// 만약 문자 하나가 남는 경우 따로 변환
	if (count % 2 == 1)
	{
		int num = bin_to_dec(code.substr(index, 6));
		data += alphanumeric[num];
		index += 6;
	}

	return data;
}

// 0100 : 8 bit byte decode
string decode_8bit_char(string code)
{
	int index = 0;

	// parameter code의 앞 8자리로 숫자 갯수 파악
	int count = bin_to_dec(code.substr(index, 8));
	index += 8;

	// 정보를 data 변수에 저장
	string data = "";

	// count만큼의 8bit code를 처리
	for (int i = 0; i < count; i++)
	{
		int num = bin_to_dec(code.substr(index, 8));

		// 만약 decode한 숫자 값이 출력 가능한 아스키 문자라면 그대로 출력
		if (num >= 0x20 && num <= 0x7E)
		{
			data += (char)num;
		}
		// 그렇지 않다면 \xx 형태로 출력
		else
		{
			data += "\\";
			data += bin_to_hex_string(code.substr(index, 8));
		}
		index += 8;
	}

	return data;
}

// 1000 : Kanji decode
string decode_kanji(string code)
{
	int index = 0;

	// parameter code의 앞 8자리로 숫자 갯수 파악
	int count = bin_to_dec(code.substr(index, 8));
	index += 8;

	// 정보를 data 변수에 저장
	string data = "";

	// count만큼의 13bit code를 처리
	for (int i = 0; i < count; i++)
	{
		// #bxxx 형태로 변환
		data += "#";
		data += bin_to_hex_string(code.substr(index, 13));

		index += 13;
	}

	return data;
}



int main()
{
	/*
	int T;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		string code;
		cin >> code;

		cout << hex_to_bin(code) << endl;
		cout << bin_to_dec(hex_to_bin(code)) << endl;

		//cout << decode_alphanumeric(ha2) << endl;
	}
	*/
	string ha = "00000011010001011001001010100011";
	cout << decode_8bit_char(ha) << endl;
	return 0;
}