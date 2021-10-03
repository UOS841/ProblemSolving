#include<iostream>
#include<queue>

using namespace std;

#define MAX 10001
int visited[1000][1000] = { 0, };

struct CST{
	int clipboard = 0;
	int screen = 1;
	int time = 0;
};

int main() {
	int clipboard = 0, screen = 1, S, time = 0;
	queue<CST> q; //clip, screen, time
	CST init;

	cin >> S;

	q.push(init);

	while (!q.empty()) {
		clipboard = q.front().clipboard;
		screen = q.front().screen;
		time = q.front().time + 1;

		if (S == screen) break;
		q.pop();

		if (screen > 0 && !visited[screen][screen]) {
			q.push({ screen, screen, time }); //copy screen->clipboard
			visited[screen][screen] = 1;
		}
		if (clipboard > 0 && screen + clipboard < MAX && !visited[clipboard][screen + clipboard]) {
			q.push({ clipboard, screen + clipboard, time }); //paste clipboard->screen
			visited[clipboard][screen + clipboard] = 1;
		}
		if (screen > 0 && !visited[clipboard][screen - 1]) {
			q.push({ clipboard, screen - 1, time }); //delete one on screen
			visited[clipboard][screen - 1] = 1;
		}
	}

	cout << time - 1;
}