/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 09:55:47 by bnetschu          #+#    #+#             */
/*   Updated: 2019/09/13 14:29:39 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_norm
{
	char	*str;
	char	*str_f;
	va_list	*argptr;
	int		i;
	int		t;
}				t_norm;

void			nine_to_nul(char *str, int i);
int				found_rigor_s(char *str, int j);
void			hhh_cop_p(char *string, int *i, int *n, char *fr);
long long int	ft_atoi1(const char *str);
int				ft_printf(const char *str, ...);
void			ft_putchar(char c);
char			*flag_c(char *str, va_list *argptr, int *z, int *nul);
char			*flag_s(char *str, va_list *argptr, int *z);
void			ft_bzero1(void *s, unsigned int n);
size_t			ft_strlen(const char *str);
int				nons_minus(int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*non_flag(char *str, int *z);
char			*ft_itoa_ulong(unsigned long long int nb);
char			*flag_u(char *str, va_list *argptr, int *z);
char			*ft_itoa_base(unsigned long long int nbr, int base, int x);
char			*flag_x(char *str, va_list *argptr, int *z);
char			*flag_p(char *str, va_list *argptr, int *z);
char			*flag_o(char *str, va_list *argptr, int *z);
char			*flag_i(char *str, va_list *argptr, int *z);
char			*ft_itoa1(long long int nb);
char			*ft_itoa_base_stan(__int128_t nbr);
char			*flag_f(char *str, va_list *argptr, int *z);
char			*ft_itoa_base_double(long double nbr_d, int *n);
char			*ft_round_f(char *str, char *str_else, int n);
void			nine_to_nul(char *str, int i);
char			*h_nul_rigor(char *str);
char			*ft_round_hf(char *str, char *str_else, int n);
void			ft_ever_nul(char *str, int i, int n);
char			*f_inf(char *s, int i);
void			f_else_double(int *i, long double nbr_d,
										__int128_t nbr, char *str_else);
int				prom(int i, char *str, char flag);
char			*ft_strjoin_f(char const *s1, char const *s2);
int				cop_from_str2_c(char *fr, char *string, int *n);
int				cop_from_str_c(char *fr, char *string, int *n);
void			nul_c(int *num, int *nul, unsigned int *i);
int				ret_dod_s(int num, char *string, int *i);
int				cop_from_str_s(char *fr, char *string, int *n, char *str);
int				cop_from_str2_s(char *fr, char *string, int *n, char *str);
int				found_line_up_s(char *str, int i, int *num);
int				write_s(char *s, int *nul);
int				hh_pars(t_norm *norm, int *z, int *nul);
int				found_line_up_non(char *str, int i, int *num, int k);
int				cop_from_str_non(char *fr, int *n, int i);
int				h_nno(char *str, int i);
int				cop_from_str_o(char *fr, char *string, int *n, int w);
int				cop_from_str2_o(char *fr, char *string, int *n);
int				found_line_up_o(char *str, int i, int *num);
uintmax_t		ft_cast_o(char *str, va_list *argptr, int *z);
void			found_oktorp(char *str, int i, int *num);
int				found_rigor_o(char *str, int j);
void			h_cop2_o(int *n, char *fr, char *string, int *i);
int				cop_from_str_p(char *fr, char *string, int *n, int w);
int				cop_from_str2_p(char *fr, char *string, int *n);
int				found_line_up_p(char *str, int i, int *num);
void			found_oktorp_p(char *str, int i, int *num);
int				found_rigor_p(char *str, int j);
void			h_cop_str2_p(char *fr, int *n, char *string, int *i);
int				cop_from_str2_u(char *fr, char *string, int *n);
int				cop_from_str_u(char *fr, char *string, int *n);
int				found_line_up_u(char *str, int i, int *num);
int				found_rigor_u(char *str, int j);
int				prom1(int i, char *str, char k, char l);
int				cop_from_str2_x(char *fr, char *string, int *n);
int				cop_from_str_x(char *fr, char *string, int *n, int w);
int				found_line_up_x(char *str, int i, int *num);
uintmax_t		ft_cast_x(char *str, va_list *argptr, int *z);
int				found_rigor_x(char *str, int j);
void			found_oktorp_x(char *str, int i, int *num);
int				h_cop_x(int *n, char *fr, char *string, int w);
int				found_line_up_i(char *str, int i, int *num);
int				cop_from_str_i(char *fr, char *string, int *n);
int				cop_from_str2_i(char *fr, char *string, int *n);
__int128_t		ft_cast_i(char *str, va_list *argptr, int *z);
char			*for_minus_string(int *n, char *str);
int				found_rigor_i(char *str, int j);
void			h_cop_fr_str_i(char *fr, int *n, int *i, char *string);
int				h_f_up_i(char *str, int *num, int k, int i);
int				h_f_up_i1(char *str, int *num, int i);
int				h_f_up_i2(char *str, int *num, int i);
int				h_f_up_i_3(char *str, int *num, int i);
int				hh_f_i(int z, char *str, int *f_k);
int				found_line_up_f(char *str, int i, int *num);
int				cop_from_str_f(char *fr, char *string, int *n);
int				cop_from_str2_f(char *fr, char *string, int *n);
void			h_found_line_up_i11(char *str, int *f_k);
int				found_rigor_f(char *str, int j);
void			hh_flag_f(int *num, char *str, int *z);
void			h_flag_f(char *str, char *fr, long int *i);
void			h_cop_fr_str2_f(int *n, int *i, char *fr, char *string);
int				h_found_line_f(int *num, int i, char *str);
int				h_found_line_f1(char *str, int *num, int i, int *f_k);
int				h_found_line_f2(char *str, int *num, int i);
int				h_found_line_f3(char *str, int i, int *num);
int				h_f_line_f1(char *str, int *f_k, int z);
void			h_f_line_f2(int *f_k, char *str);
#endif
