/*
** 算法说明 (Algorithm Explanation):
** 在链表头部添加一个新节点。
** 将新节点的 next 指针指向当前头节点，然后更新头指针。
** 时间复杂度: O(1)
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
