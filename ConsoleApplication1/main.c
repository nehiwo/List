#include "List.h"

#define ERR_TEST
#define TEST
#define CHECK_MEMORY

int main(void)
{
	NODE* p_new = CreateNode(0, "なし");
	NODE* p_head = p_new;
	NODE* p_tail = p_new;
	NODE* p_now = p_new;
#undef ERR_TEST
#undef TEST
#undef CHECK_MEMORY
#if defined(ERR_TEST) && !defined(TEST) && !defined(CHECK_MEMORY)
	/* エラー確認 */
	NODE* p_dummy = 0;
	ConnectNode(p_dummy, p_tail);
	ConnectNode(p_head, p_dummy);
	AddFirstNode(p_head, p_dummy);
	AddFirstNode(p_dummy, p_now);
	AddLastNode(p_tail, p_dummy);
	AddLastNode(p_dummy, p_now);
	InsertNode(p_dummy, p_now);
	InsertNode(p_now, p_dummy);
	RemoveNode(p_dummy);
	PrintList(p_dummy);

#elif !defined(ERR_TEST) && defined(TEST) && !defined(CHECK_MEMORY)
	/*各関数の動作確認*/
	for (int i = 2; i <= 10; i++) {
		p_new = CreateNode(i);
		ConnectNode(p_now, p_new);
		p_now = p_new;
	}
	p_tail = p_now;
	PrintList(p_head);
	printf("%u\n", GetListLength(p_head));

	p_now = SelectNode(6, p_head);
	p_new = CreateNode(11);
	InsertNode(p_now, p_new);
	PrintList(p_head);
	printf("%u\n", GetListLength(p_head));

	p_new = CreateNode(12);
	p_head = AddFirstNode(p_head, p_new);
	p_new = CreateNode(13);
	p_tail = AddLastNode(p_tail, p_new);
	PrintList(p_head);
	printf("%u\n", GetListLength(p_head));

	RemoveNode(p_now);
	PrintList(p_head);
	printf("%u\n", GetListLength(p_head));

	p_now = SelectNode(5, p_head);
	PrintNode(p_now);
	p_now = SelectNode(16, p_head);
	PrintNode(p_now);
	printf("\n");

	uint32_t index = SearchNode(4, p_head);
	index = SearchNode(12, p_head);
	index = SearchNode(13, p_head);
	index = SearchNode(100, p_head);
	printf("\n");

	p_head = SortList(p_head);
	PrintList(p_head);
	printf("%u\n", GetListLength(p_head));

	SaveList(p_head);
	p_head = LoadList(p_head);

	/*リスト消去*/
	p_head = (NODE*)DestroyList(p_head);
	p_tail = (NODE*)DestroyList(p_head);
	PrintNode(p_tail);
	p_now = (NODE*)DestroyList(p_head);
	p_new = (NODE*)DestroyList(p_head);
	//PrintList(p_head);

#elif !defined(ERR_TEST) && !defined(TEST) && defined(CHECK_MEMORY)
	/*メモリチェック*/
	int count = 1;
	while (p_new != NULL) {
		p_new = CreateNode(count);
		ConnectNode(p_now, p_new);
		if(p_new != NULL){
			p_now = p_new;
			count++;
		}
		else {
			/* nothing to do */
		}
	}
	p_tail = p_now;
	PrintNode(p_tail);

#elif !defined(ERR_TEST) && !defined(TEST) && !defined(CHECK_MEMORY)
	PrintMenu(p_head);

#else
	printf("don't define executing mode.\ncan't compile.\n");
#endif
	return 0;
}
