#include "push_swap.h"

void	swap(t_stack **lst, char which_stack)
{
	t_stack	*tmp;

	tmp = *lst;
	*lst = (*lst)-> next;
	tmp -> next = (*lst)-> next;
	(*lst)-> next = tmp;
	if (which_stack == 'A')
		write(1, "sa\n", 3);
	if (which_stack == 'B')
		write(1, "sb\n", 3);
}

void	rotate(t_stack **lst, char which_stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *lst;
	tmp2 = (*lst)-> next;
	while ((*lst)-> next != NULL)
		(*lst) = (*lst)-> next;
	tmp1 -> next = NULL;
	(*lst)-> next = tmp1;
	(*lst) = tmp2;
	if (which_stack == 'A')
		write(1, "ra\n", 3);
	if (which_stack == 'B')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack **lst, char which_stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*lst);
	while ((*lst)-> next != NULL)
		(*lst) = (*lst)-> next;
	(*lst)-> next = tmp1;
	tmp2 = (*lst);
	while ((*lst)-> next != tmp2)
		(*lst) = (*lst)-> next;
	(*lst)-> next = NULL;
	(*lst) = tmp2;
	if (which_stack == 'A')
		write(1, "rra\n", 4);
	if (which_stack == 'B')
		write(1, "rrb\n", 4);
}

void	push(t_stack **stack_A, t_stack **stack_B, char which_stack)
{
	t_stack	*tmp;

	if (which_stack == 'A')
	{
		tmp = *stack_B;
		(*stack_B) = (*stack_B)-> next;
		tmp -> next = (*stack_A);
		(*stack_A) = tmp;
		write(1, "pa\n", 3);
	}
	if (which_stack == 'B')
	{
		tmp = *stack_A;
		(*stack_A) = (*stack_A)-> next;
		tmp -> next = (*stack_B);
		(*stack_B) = tmp;
		write(1, "pb\n", 3);
	}
}

void	reverse_rotate_r(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*stack_A);
	while ((*stack_A)-> next != NULL)
		(*stack_A) = (*stack_A)-> next;
	(*stack_A)-> next = tmp1;
	tmp2 = (*stack_A);
	while ((*stack_A)-> next != tmp2)
		(*stack_A) = (*stack_A)-> next;
	(*stack_A)-> next = NULL;
	(*stack_A) = tmp2;
	tmp1 = (*stack_B);
	while ((*stack_B)-> next != NULL)
		(*stack_B) = (*stack_B)-> next;
	(*stack_B)-> next = tmp1;
	tmp2 = (*stack_B);
	while ((*stack_B)-> next != tmp2)
		(*stack_B) = (*stack_B)-> next;
	(*stack_B)-> next = NULL;
	(*stack_B) = tmp2;
	write(1, "rrr\n", 4);
}
