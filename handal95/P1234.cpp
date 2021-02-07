#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> Toy;
enum ColorType{
    RED = 0,
    GREEN = 1,
    BLUE = 2
};


long long factorial(int n){
    if(n <= 1)
        return 1;
    return n * factorial(n - 1);
}

long long nCr(int N, int R){
    long long value = factorial(N) / (factorial(N - R) * factorial(R));
    cout << "nCr" << N << " C " << R << " = " << value << endl;
    return value;
}


long long decorate(int level, int red, int green, int blue){
    long long style = 0;
    if(red + green + blue < level)
        return style;
    
    if(level == 1){
        if(red >= 1)
            style += 1;
        if(green >= 1)
            style += 1;
        if(blue >= 1)
            style += 1;
        return style;
    }

    if(level % 3 == 0){
        // Deco with Combination of 3 colors
        int num = level / 3;
        int combi = nCr(level, 3);
        if(red >= num && green >= num && blue >= num){
            style += combi * decorate(level - 1, red - num, green - num, blue - num);
        }
    }
    if(level % 2 == 0){
        // Deco with Combination of 2 colors
        int num = level / 2;
        int combi = nCr(level, 2);

        if(red >= num && green >= num)
            style += combi * decorate(level - 1, red - num, green - num, blue);
        if(green >= num && blue >= num)
            style += combi * decorate(level - 1, red, green - num, blue - num);
        if(blue >= num && red >= num)
            style += combi * decorate(level - 1, red - num, green, blue - num);
    }

    // Deco with only 1 color
    int num = level;
    if(red >= num)
        style += decorate(level - 1, red - num, green, blue);
    if(green >= num)
        style += decorate(level - 1, red, green - num, blue);
    if(blue >= num)
        style += decorate(level - 1, red, green, blue - num);

    return style;
}

int main(){
    int N; // The level of Tree
    Toy toys(3); // The numbers of Toys
    cin >> N;
    cin >> toys[RED] >> toys[GREEN] >> toys[BLUE];

    long long answer = 0;
    int minimum = N * (N + 1) / 2;

    // Condition 1 : sum of toyes should be more than minimum
    if((toys[RED] + toys[GREEN] + toys[BLUE]) < minimum){
        cout << answer;
        return 0;
    }

    answer = decorate(N, toys[RED], toys[GREEN], toys[BLUE]);
    cout << answer;
}