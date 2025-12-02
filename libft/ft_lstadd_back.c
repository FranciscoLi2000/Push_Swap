/*
** 算法说明 (Algorithm Explanation):
** 在链表末尾添加一个新节点。
** 如果链表为空，新节点成为头节点；否则找到最后一个节点，将其 next 指针
** 指向新节点。
** 时间复杂度: O(n)
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
