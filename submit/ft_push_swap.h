/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:56:09 by juyou             #+#    #+#             */
/*   Updated: 2021/10/31 13:49:12 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_stack
{
	int			data;
	struct s_stack *prev;
	struct s_stack *next;
} t_stack;

// libft_utils.c
char	*ft_strdup(const char *str, size_t str_len);
size_t	ft_str_len(char const *str);
char **ft_split(char const *str);
int			ft_isspace(char c);
int			ft_isalpha(char c);

// parse_utils.c
long long ft_atoi(char *str);
size_t	ft_str_count(char const *str); // ' '를 구분자로 들어오므로 str의 개수를 센다.
int		ft_parse(char **argv, int argc);
int		ft_arrlen(char **arr); //배열의 길이만 구해준다.


//validate.c
void 	ft_insert_num(char **arr, long long *num_arr, int *j, int arr_len);
void	ft_arr_atoi(char **argv, long long *num_arr, int argc, int arr_len);
int		ft_validate_limit(long long *arr, int arr_len);
void	ft_validate_order(long long *int_arr, int arr_len);



// memory_utils.c
int 	error(int ret);
void	free_str(char **str);
void	ft_free(char **s, int idx);
void	ft_free_stack(t_stack *a, t_stack *b);


// linkedlist
void	ft_create_linked(t_stack *head, long long *arr, int cnt);
		// ft_make_lst
t_stack	*ft_get_last(t_stack *stack);
		// find_last_lst
t_stack *ft_create_stack(void);
// operations directory
// push
void	ft_pop_first(t_stack *head);
void	ft_push_first(t_stack *head, int data);
void	pa(t_stack *a, t_stack *b, int *pa_cnt);
void	pb(t_stack *a, t_stack *b, int *pb_cnt);

//swap
int		ft_linked_len(t_stack *head);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

//rotate
void	ft_push_last(t_stack *head, int data);
void	ra(t_stack *a, int *cnt);
void	rb(t_stack *b, int *cnt);
void	rr(t_stack *a, t_stack *b);

//reverse_roate.c
void	ft_pop_last(t_stack *head);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);




////// ALGORITHM
void	ft_sort_start(t_stack *a, t_stack *b, int num);
void	ft_case_two(t_stack *head);
void	ft_case_three(t_stack *head);
void	ft_case_five(t_stack *a, t_stack *b);
void	ft_ret_max_min(t_stack *a, t_stack *b, int pb_cnt, int max);


/////ALGO UTILS
int		ft_max(t_stack *head);
int		ft_min(t_stack *head);
int		ft_find_pivot(t_stack *head, int cnt); // 수정
void	ft_sort_arr(long long *arr, int cnt); // 수정
void	ft_swap(long long *arr, int idx, int l_idx); // 수정



// mergeSORT
void	ft_a_to_b(t_stack *a, t_stack *b, int cnt);
void	ft_b_to_a(t_stack *a, t_stack *b, int cnt);
void	ft_rr(t_stack *a, t_stack *b, int cnt, int type);



// //stack



//stack utils
// void	ft_sort_arr(long long *arr, int cnt);

// int		ft_find_max(t_stack *head);
// int		ft_find_min(t_stack *head);
// int		ft_find_pivot(t_stack *head, int cnt);
// void	ft_swap(long long *arr, int idx, int l_idx);


// //mian
// void	ft_case_two(t_stack *head);
// void	ft_case_three(t_stack *head);
// void	ft_case_five(t_stack *a, t_stack *b);
// void	ft_m_change(t_stack *a, t_stack *b, int pb_cnt, int max_v);
// void	ft_b_a(t_stack *a, t_stack *b, int cnt);
// void	ft_a_b(t_stack *a, t_stack *b, int cnt);
// void	ft_rr(t_stack *a, t_stack *b, int cnt, int type);







#endif