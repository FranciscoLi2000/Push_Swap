/*
** 算法说明 (Algorithm Explanation):
** 返回链表的最后一个节点。
** 遍历链表直到找到 next 为 NULL 的节点。
** 时间复杂度: O(n)
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
