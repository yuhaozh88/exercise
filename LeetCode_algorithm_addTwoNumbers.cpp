//@author yuhaozh88
#include<iostream>
#include<algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = NULL;
		ListNode* tail = NULL;
		ListNode* temp;
		int addtional = 0;//用来储存进位的变量
		while (l1 != NULL || l2 != NULL || addtional == 1) {
			if (l1&&l2&&head == NULL) {//得到最低位同时也是头指针的位置
				temp = new ListNode((l1->val + l2->val + addtional) % 10);
				head = temp;
				tail = head;
				addtional = (l1->val + l2->val + addtional) >= 10 ? 1 : 0;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1&&l2) {//两个数均存在的位，但是不是最低位
				temp = new ListNode((l1->val + l2->val + addtional) % 10);
				tail->next = temp;
				tail = temp;
				addtional = (l1->val + l2->val + addtional) >= 10 ? 1 : 0;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1 != NULL&&l2 == NULL) {
				temp = new ListNode((l1->val + addtional) % 10);
				tail->next = temp;
				tail = temp;
				addtional = (l1->val + addtional) >= 10 ? 1 : 0;
				l1 = l1->next;
			}
			else if (l1 == NULL&&l2 == NULL&&addtional == 1) {
				temp = new ListNode(1);
				tail->next = temp;
				tail = temp;
				addtional = 0;
			}
			else if (l1 == NULL&&l2 != NULL) {
				temp = new ListNode((l2->val + addtional) % 10);
				tail->next = temp;
				tail = temp;
				addtional = (l2->val + addtional) >= 10 ? 1 : 0;
				l2 = l2->next;
			}
		}
		return head;
	}
};