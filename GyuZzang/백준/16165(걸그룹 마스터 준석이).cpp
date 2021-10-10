#include<iostream>
#include<set>
#include <string>
#include<map>

using namespace std;

int main() {
	int N, M,
		n_member,
		q_type;
	string group, member, question;
	//group --> set of member 
	map<string, set<string>> group_to_member;
	map<string, string> member_to_group;

	cin >> N >> M;

	//init
	for (int i = 0; i < N; i++) {
		cin >> group;
		set<string> members;
		cin >> n_member;

		while (n_member--) {
			cin >> member;
			members.insert(member);
			member_to_group.insert({ member, group });
		}

		group_to_member.insert({ group, members });
	}

	//start quiz
	while (M--) {
		cin >> question;
		cin >> q_type;

		if (q_type) {
			cout << member_to_group.find(question)->second << endl;
		}
		else {
			set<string> members = group_to_member.find(question)->second;
			for (auto it : members) {
				cout << it << endl;
			}
		}
	}

}