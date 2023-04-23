#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		int_error();
	stack_a = init_stack_a(argv_stack(argc, argv));
	stack_a = simplified_values(stack_a);
	stack_b = init_stack_b(stack_a);
	//printfunction(stack_a, stack_b);
	push_to_stack_b(stack_a, stack_b);
	//printf("\nORIGINAL FUNCTION\n");
	//printfunction(stack_a, stack_b);
	stack_a = basic_algorithm(stack_a);
	//printf("\nBASIC ALGORITHM\n\n");
	//printfunction(stack_a, stack_b);
	sorting_stacks(stack_a, stack_b);
	rearrange_stack(stack_a);
	//printf("\nRESULT!!!!!!!\n\n");
	printfunction(stack_a, stack_b);
	return (0);
}
