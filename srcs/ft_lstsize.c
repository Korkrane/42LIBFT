/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahaas <bahaas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 22:52:10 by bahaas            #+#    #+#             */
/*   Updated: 2020/11/02 17:46:40 by bahaas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*create_element(void *content)
{
	t_list *elem;
	elem = malloc(sizeof(t_list));
	if(!elem)
		return(NULL);
	if(elem)
	{
		elem->content = content;
		elem->next = NULL;
	}
	return(elem);
}

void	print_elem(t_list element)
{
	printf("content = %s, adress = %p\n", (char *)element.content, element.next);
}

int main()
{
	t_list *liste;
	t_list *elem1;
	t_list *elem2;
	t_list *elem3;
	t_list *elem4;

	liste = create_element("Test 1");
	elem1 = create_element("Bonjour");
	elem2 = create_element("veux");
	elem3 = create_element("tu");
	elem4 = create_element("bien");
	liste->next = elem1;
	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;

	t_list *begin_list;
	begin_list = liste;
	while(begin_list)
	{
		print_elem(*begin_list);
		begin_list = begin_list->next;
	}
	printf("\nNumber of elements :\n%d\n", ft_lstsize(liste));
	return 0;
}